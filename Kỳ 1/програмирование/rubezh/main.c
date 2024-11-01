#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    printf("Введите количество элементов первого массива: ");
    scanf("%d", &m);
    printf("Введите количество элементов второго массива: ");
    scanf("%d", &n);

    /*Динамическое выделение памяти*/
    int *array1 = (int *)malloc(m * sizeof(int));
    int *array2 = (int *)malloc(n * sizeof(int));

    /*Введите элементы массива*/
    printf("Введите элементы первого массива:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &array1[i]);
    }
    printf("Введите элементы второго массива:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array2[i]);
    }

    /*Распечатать два массива*/
    printf("--------------------\n");
    printf("array1: ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", *(array1 + i));
    }
    printf("\n");
    printf("array1: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(array2 + i));
    }
    printf("\n");

    /*Объединить два массива*/
    int a;
    a = m + n;
    int *array3 = (int *)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        if (i < m)
            array3[i] = array1[i];
        else
            array3[i] = array2[i - m];
    }

    /*Распечатать массив после слияния*/
    printf("--------------------\n");
    printf("Массивы после слияния\n");
    printf("array3: ");
    for (int i = 0; i < a; i++)
    {
        printf("%d ", *(array3 + i));
    }

    /*Освобождение динамической памяти*/
    free(array1);
    free(array2);
    free(array3);
    return 0;
}