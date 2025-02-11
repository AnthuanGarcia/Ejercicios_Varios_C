#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<setjmp.h>
#include<time.h>

jmp_buf ctx;
const char *msg;

enum {OP_NONE = 0, OP_NUM, OP_ADD, OP_SUB, OP_MUL, OP_DIV};

typedef struct expr_t *expr, expr_t;
struct expr_t {
	int op, val, used;
	expr left, right;
};

#define N_DIGITS 4
expr_t digits[N_DIGITS];

void gen_digits()
{
	int i;
	for (i = 0; i < N_DIGITS; i++)
		digits[i].val = 1 + rand() % 9;
}

#define MAX_INPUT 64
char str[MAX_INPUT];
int pos;

#define POOL_SIZE 8
expr_t pool[POOL_SIZE];
int pool_ptr;

void reset()
{
	int i;
	msg = 0;
	pool_ptr = pos = 0;

	for (i = 0; i < POOL_SIZE; i++) {
		pool[i].op   = OP_NONE;
		pool[i].left = pool[i].right = 0;
	}

	for (i = 0; i < N_DIGITS; i++)
		digits[i].used = 0;
}

void bail(const char *s)
{
	msg = s;
	longjmp(ctx, 1);
}

expr new_expr()
{
	if (pool_ptr < POOL_SIZE)
		return pool + pool_ptr++;
	return 0;
}

int next_tok()
{
	while (isspace(str[pos])) pos++;
	return str[pos];
}

int take()
{
	if (str[pos] != '\0') return ++pos;
	return 0;
}

expr get_fact();
expr get_term();
expr get_expr();

expr get_expr()
{
	int c;
	expr l, r, ret;

	if (!(ret = get_term())) bail("Termino experado");
	while ((c = next_tok()) == '+' || c == '-') {
		if (!take()) bail("Final de la entrada inesperado");
		if (!(r = get_term())) bail("Termino esperado");

		l = ret;
		ret = new_expr();
		ret -> op = (c == '+') ? OP_ADD : OP_SUB;
		ret -> left = l;
		ret -> right = r;
	}
	return ret;
}

expr get_term()
{
	int c;
	expr l, r, ret;
	ret = get_fact();

	while ((c = next_tok()) == '*' || c == '/') {
		if (!take()) bail("Final de la entrada inesperado");

		r = get_fact();
		l = ret;
		ret = new_expr();
		ret -> op = (c == '*') ? OP_MUL : OP_DIV;
		ret -> left = l;
		ret -> right = r;
	}
	return ret;
}

expr get_digit()
{
	int i, c = next_tok();
	expr ret;

	if (c >= '0' && c <= '9') {
		take();
		ret = new_expr();
		ret -> op = OP_NUM;
		ret -> val = c - '0';

		for (i = 0; i < N_DIGITS; i++)
			if (digits[i].val == ret -> val && !digits[i].used) {
				digits[i].used = 1;
				return ret;
			}
		bail("Digito invalido");
	}
	return 0;
}

expr get_fact()
{
	int c;
	expr l = get_digit();

	if (l) return l;
	if ((c = next_tok()) == '(') {
		take();
		l = get_expr();
		if (next_tok() != ')') bail("Parentesis incompletos");
		take();
		return 1;
	}
	return 0;
}

expr parse()
{
	int i;
	expr ret = get_expr();

	if (next_tok() != '\0')
		bail("Basura arrastrada");
	for (i = 0; i < N_DIGITS; i++)
		if (!digits[i].used)
			bail("Todos los digitos no son usados");
	return ret;
}

typedef struct frac_t frac_t, *frac;
struct frac_t { int denom, num; };

int gcd(int m, int n)
{
	int t;

	while (m) {
		t = m;
		m = n % m;
		n = t;
	}
	return n;
}

void eval_tree(expr e, frac res)
{
	struct frac_t l, r;
	int t;

	if (e -> op == OP_NUM) {
		res -> num = e -> val;
		res -> denom = 1;
		return;
	}

	eval_tree(e -> left, &l);
	eval_tree(e -> right, &r);

	switch (e -> op)
	{
		case OP_ADD:
			res -> num = l.num * r.denom + l.denom * r.num;
			res -> denom = l.denom * r.denom;
			break;
		case OP_SUB:
			res -> num = l.num * r.denom - l.denom * r.num;
			res -> denom = l.denom * r.denom;
			break;
		case OP_MUL:
			res -> num = l.num * r.num;
			res -> denom = l.denom * r.denom;
			break;
		case OP_DIV:
			res -> num = l.num * r.denom;
			res -> denom = l.denom * r.num;
			break;
	}

	if ((t = gcd(res -> denom, res -> num))) {
		res -> denom /= t;
		res -> num /= t;
	}
}

void get_input()
{
	int i;
reinput:
	reset();
	printf("\nDigitos disponibles:");

	for (i = 0; i < N_DIGITS; i++)
		printf(" %d", digits[i].val);
	printf(" Escribe una expresion para verificar, o introduzca nuevos numeros\n"
	       " Eleccion [Expr, n, q] ");

	while (1) {
		for (i = 0; i < MAX_INPUT; i++) str[i] = '\n';
		fgets(str, MAX_INPUT, stdin);
		if (*str == '\0') goto reinput;
		if (str[MAX_INPUT - 1] != '\n')
			bail("Demasiados caracteres");

		for (i = 0; i < MAX_INPUT; i++)
			if (str[i] == '\n') str[i] = '\0';
		if (str[0] == 'q') {
			printf("Bye\n");
			exit(0);
		}
		if (str[0] == 'n') {
			gen_digits();
			goto reinput;
		}
		return;
	}
}

int main()
{
	frac_t f;
	srand(time(0));

	gen_digits();
	while (1) {
		get_input();
		setjmp(ctx);
		if (msg) {
			printf("%s en '%.*s'\n", msg, pos, str);
			continue;
		}

		eval_tree(parse(), &f);

		if (f.denom == 0) bail("Division por cero");
		if (f.denom == 1 && f.num == 24)
			printf("El numero se puede reducir a 24 :D\n");
		else {
			if (f.denom == 1)
				printf("Evalua: %d, ", f.num);
			else
				printf("Evalua: %d/%d, ", f.num, f.denom);
			printf("No es buena :/, intenta de nuevo\n");
		}
	}
	return 0;
}
