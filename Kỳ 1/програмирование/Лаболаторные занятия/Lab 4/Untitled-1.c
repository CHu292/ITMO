#include <stdio.h>
#include <stdlib.h>

void fun(double*** b; int index1; int index2);

int main(){
    double **A;
    int n = 3;
    int m;
    a = (double**) colloc(n,sizeof(double*));
    for (int = 0; i < n; i++){
        a[i] = (double*)colloc(m,sizeof(double));
    }

    a[0][2] = 3.14; 
    double k = a[0][2];
    for (int j = 0; j < 3; j++){
        a[i][j] = 3.14;
        free(a[0]);
    }
    free(a);
    
}
 