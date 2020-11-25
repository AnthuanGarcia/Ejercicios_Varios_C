#include<stdio.h>

#define OPEN    1
#define CLOSED  0

int *doors(int *arr, int *open, int len);

int main()
{
    int door[100];
    int *openDoors;

    for (int i = 0; i < 100; i++)
    {
        door[i] = CLOSED;
    }

    doors(door, openDoors, 100);

    return 0;
}

int *doors(int arr[], int openDoors[], int len)
{
    //int *openDoors;
    int i, door = 1, opened = 0;

    while (door <= 100)
    {
        for (i = 0; i <= len; i += door)
        {
            if (arr[i] == OPEN)
            {
                arr[i] = CLOSED;
            }
            else
            {
                arr[i] = OPEN;
            }
        }
        door++;
    }


    for (i = 0; i <= len; i++)
    {
        if (arr[i] == OPEN){
            openDoors[opened] = i;
            printf("%d ", openDoors[opened]);
            opened++;
        }
    }
    printf("\n");
    return openDoors;
}