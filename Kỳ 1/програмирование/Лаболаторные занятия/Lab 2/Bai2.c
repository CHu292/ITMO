#include <stdio.h>

int main () {
    int mas[4] = {255, 1024, -1, -2};
    for (int j = 4; j > 0; j--){
        for (int i = 0; i < j; i++){
            if (mas[i] >= mas[i + 1]){
                int tmp = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = tmp;
            }
        }
    }
    
    for (int i = 0; i < 4; i++){
        printf("%d \n", mas[i]);
    }
}