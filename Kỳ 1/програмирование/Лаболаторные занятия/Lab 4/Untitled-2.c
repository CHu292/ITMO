#include <stdio.h>
#include <stdlib.h>

void fun(double*** q, int w, int e);

int main(){
    double **a;
    int n = 3;
    int m = 3;
    fun (&a, n, m);

    

    double sum = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            a[i][j] = 6.28;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%f\t", a[i][j]);
            printf("\n");
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            sum += a[i][j];
        }
    }

    a[1][1] = sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%f\t", a[i][j]);
            printf("\n");
    }

    for (int i = 0; i < 3; i++){
        free(a[i]);
    }
    free(a);
    
}

void fun(double*** q, int w, int e){
    *q = (double**)calloc(w, sizeof(double*));
    for (int i = 0; i < w; i++)
    (*q)[i] = (double*)calloc(e, sizeof(double));
}
