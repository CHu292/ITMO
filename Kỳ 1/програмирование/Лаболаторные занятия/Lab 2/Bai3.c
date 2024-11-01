#include <stdio.h>
int main(){
    int mas0[4] = {255, 1024, -1, -2};
    for (int j = 4; j > 0; j--){
        for (int i = 0; i < j; i++){
            if (mas0[i] >= mas0[i + 1]){
                int tmp = mas0[i];
                mas0[i] = mas0[i + 1];
                mas0[i + 1] = tmp;
            }
        }
    }
    
    for (int i = 0; i < 4; i++){
        printf("%d \n", mas0[i]);
    }

    printf("\n");

    int mas[3][3] = {{10, 20, 70}, {30, 60, 15}, {80, 55, 29}};
    int min = mas[0][0];
    int x = 0;
    int y = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d  ", mas[i][j]);
        }     
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++){
        for (int j  = 0; j < 3; j++){
            if (mas[i][j] < min){
                min = mas[i][j];
                x = i;
                y = j;
            }
        }
    }

    printf("%d %d %d \n \n", min, x, y);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == j){
                printf("%d  ", min);
            } else {
                printf("%d  ", mas[i][j]);
            }
        }     
        printf("\n");
    }

    int sum1 = 0;
    int sum2 = 0;
    
    printf("\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == 0){
                sum1 += mas[i][j]; 
                if (j == 2)
                    mas[i][j] = sum1;
            } 
            if (i == 2){
                sum2 += mas[i][j];
            }
        }     
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if ((i == 2) && (j == 0))
                mas[i][j] = sum2;
            printf("%d  ", mas[i][j]);
        }     
        printf("\n");
    }
    return 0;
}