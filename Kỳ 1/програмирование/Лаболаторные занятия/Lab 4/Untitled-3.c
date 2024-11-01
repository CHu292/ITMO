#include <stdio.h>
#include <stdlib.h>

void f(double*** q, int w, int e);

int main()
{
double** a;
int n = 3, m = 3;
double sum = 0;
/* a = (double**)calloc(n, sizeof(double*));
for (int i = 0; i < n; i++)
a[i] = (double*)calloc(m, sizeof(double)); */

f(&a, n, m);


for (int i = 0; i < n; i++)
for (int j = 0; j < m; j++)
a[i][j] = 8.52;

for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++)
printf("%f\t", a[i][j]);
printf("\n");
}
printf("\n");

for (int i = 0; i < n; i++)
for (int j = 0; j < m; j++)
sum += a[i][j];

a[1][1] = sum;

for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++)
printf("%f\t", a[i][j]);
printf("\n");
}

for (int i = 0; i < 3; i++)
free(a[i]);
free(a);
return 0;
}

void f(double*** q, int w, int e) {
   *q = (double**)calloc(w, sizeof(double*));
    for (int i = 0; i < w; i++)
    (*q)[i] = (double*)calloc(e, sizeof(double));
}

// выделить память под двумерный массив (двойной указатель). Проинициализировать. Посчитать сумму эл-ов и поместить в серединный эл-т. Удалить выделенную память.
