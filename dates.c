#include<stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearDay);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(int argc, char const *argv[])
{
    printf("El dia del año es: %d\n", day_of_year(2020, 8, 23));
    
    month_day(1968, 60);
    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearDay)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearDay > daytab[leap][i]; i++)
        yearDay -= daytab[leap][i];
    printf("El mes es: %d\n", i);
    printf("El dia es %d\n", yearDay);
 } 