#include <stdio.h>
int main()
{
    /* Мы должны определить, является ли число степенью двойки?*/
    int a = 32;
    if (a & (a - 1))
        printf("No\n");
    else
        printf("Yes\n");
    /* Определение длины с использованием индексного выражения */
    char mas[21];
    int i = 0, count = 0;
    char c;
    while ((c = getchar()) != '\n' && i < 20)
    {
        mas[i++] = c;
    }
    mas[i] = 0;
    i = 0;
    /* Определение длины с использованием указателя */
    char *pmas = mas;
    while (*pmas++)
    {
        count++;
    }
    printf("Line is %d\n", count);
    /* Перевернуть массив с помощью указателей*/
    printf("%s \n", mas);
    char *pmas1 = mas;
    pmas -= 2;
    char tmp;
    for (int k = 0; k < count / 2; k++)
    {
        tmp = *pmas1;
        *pmas1++ = *pmas;
        *pmas-- = tmp;
    }
    printf("%s\n", mas);
    /* Перевернуть массив с помощью индексов*/
    int j = count - 1;
    for (i = 0; i < count / 2;)
    {
        tmp = mas[i];
        mas[i++] = mas[j];
        mas[j--] = tmp;
    }
    printf("%s\n", mas);
    return 0;
}