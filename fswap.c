#include<stdio.h>

#define swap(t, x, y) { t _z;   \
                        _z = y; \
                        y = x;  \
                        x = _z; }

int main(int argc, char const *argv[])
{
    int x = 10;
    int y = 5;

    printf("x = %d, y = %d\n", x, y);

    swap(int, x, y);

    printf("x = %d, y = %d", x, y);

    return 0;
}
