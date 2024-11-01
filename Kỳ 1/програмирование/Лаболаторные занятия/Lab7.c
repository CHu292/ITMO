#include <stdio.h>
#include <stdlib.h>

void ff1(int***, int, int);
int ff2(void (*)(int***, int, int), int***, int, int);

int main() {
    int **ppArr, dim1 = 3, dim2 = 3;
    void (*pff1)(int***, int, int);
    pff1 = ff1;
    int (*pff2)(void (*)(int***, int, int), int***, int, int);
    pff2 = ff2;
    printf("%d\n", pff2(pff1, &ppArr, dim1, dim2));

    for (int i = 0; i < dim1; i++)
        free(ppArr[i]);
    free(ppArr);
    return 0;
}
void ff1(int*** q, int w, int e) {
    *q = (int**)calloc(w, sizeof(int*));
    for (int i = 0; i < w; i++)
        (*q)[i] = (int*)calloc(e, sizeof(int));
}

int ff2(void (*pff1)(int***, int, int), int*** ppInt, int dim1, int dim2) {
    pff1(ppInt, dim1, dim2);
    (*ppInt)[0][0] = 255;
    return (*ppInt)[0][0];
}