#include <stdio.h>
#include <stdlib.h>
int main()
{
    //Часть 1: определение порядка в номера дня в году по месяцу и число :
    static char daytab[2][13] =
        {
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    int year = 2022, month = 11, day = 1;
    int leap, i;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month < 1 || month > 12)
    {
        return -1;
    }
    if (day < 1 || day > daytab[leap][month])
    {
        return -1;
    }
    for (i = 1; i < month; i++)
    {
        day = day + daytab[leap][i];
    }
    printf("%d\n", day);

    //Часть 2: вычислить месяц и число по номеру дня году :
    int yearday = 259;
    int *pmonth = &month;
    int *pday = &day;
    for (i = 1; i < 12 && yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    if (i > 12 && yearday > daytab[leap][i])
    {
        *pmonth = -1;
        *pday = -1;
    }
    else
    {
        *pmonth = i;
        *pday = yearday;
    }
    printf("%d\n", *pmonth);
    printf("%d\n", *pday);

    //порядковый номер в году по месяцу и числу с использованием указателей
    char *p;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap]; //интерпретация, обьяснить и закоментировать
    while (--month)
        day += *++p;
    printf("%d\n", day);

    //определить месяцы день по дня в году используя указатели:
    char *p1 = daytab[leap];
    while (day > *++p1)
        day -= *p1;
    *pmonth = p1 - *(daytab + leap);
    *pday = day;
    printf("%d\n", *pmonth);
    printf("%d\n", *pday);

    return 0;
}