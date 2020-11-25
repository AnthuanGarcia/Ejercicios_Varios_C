#include<stdio.h>

int map[][10] = {
    {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0, -1, -1, -1, -1, -1, -1,  0, -1},
    {-1,  0, -1,  0, -1, -1, -1, -1,  0, -1},
    {-1,  0, -1,  0, -1, -1, -1, -1,  0, -1},
    {-1,  0, -1,  0, -1, -1, -1, -1,  0, -1},
    {-1,  0, -1,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0, -1,  0, -1, -1, -1, -1,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
};

#define MATRIX_SIZE (sizeof map / sizeof (map[0]))

int *mapeo(int (*map)[MATRIX_SIZE], int len);
// void printMatrix(int (*map)[MATRIX_SIZE]);

int main()
{
    int (*arr)[MATRIX_SIZE];
    arr = mapeo(map, MATRIX_SIZE);

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

int *mapeo(int (*map)[10], int len)
{
    int (*mapa)[10] = &map[0][0];
    int conteo = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (mapa[i][j] == -1){
                continue;
            } else {
                mapa[i][j] = conteo++;
            }
        }
    }

    return *mapa;
}