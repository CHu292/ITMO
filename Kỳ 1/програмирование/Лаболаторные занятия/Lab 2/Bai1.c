#include <stdio.h>

int main(){
    char mas[] = "it9MO";

    for (int i = 0; i < 5; i++){
        if (mas[i] >= '0' && mas[i] <= '9')
        {
            continue;
        }

        if (mas[i] >= 'a' && mas[i] <= 'z')
        {
            mas[i] = mas[i] & '\xDF';
            continue;
        }

        if (mas[i] >= 'A' && mas[i] <= 'Z')
        {
            mas[i] = mas[i]|32;
            continue;
        }
        
    }

    printf(mas);

}


