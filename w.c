#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(float time)
{
    float milli_seconds = 1000 * time;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

main()
{
    int i = 0;
    char anim[8] = {'|', '/', '-', '\\', '|', '/', '-', '\\'};

    while  (i >= 0)
    {
        printf("%c\n", anim[i]);
        i++;

        delay(0.025);
        system("cls");

        if (i == 8)
        {
            i = 0;
        }
    }
}