#include<stdio.h>
#include<time.h>

/*
Objetivos
nums = [3, 3]
target = 6

nums = [2, 7, 11, 15]
target = 9

nums = [2,5,5,11]
target = 10
*/
#define DATOS 12599

struct indexes{
    int index;
    int index2;
};

typedef struct indexes Struct;

Struct indexes (int nums[], int target)
{
    Struct ind;
    int i, j;

    for (i = 0; i < DATOS; i++)
    {
        for (j = i + 1; j < DATOS; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ind.index = i;
                ind.index2 = j;
                return ind;
            }
        }
    }
}

main()
{
    int nums[DATOS];
    int target = 50000;

    int i, j;
    int acum = 0;
    Struct inde;

    for (i = 0; i < DATOS; i++)
    {
        nums[i] = acum;
        acum += 2;
    }

    time_t begin = clock();

    inde = indexes(nums, target);
    printf("[%d, %d]", inde.index, inde.index2);

    time_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTiempo de ejecucion: %f", time_spent);
}