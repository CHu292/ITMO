#include <stdio.h>

int main(){
    char mas[] = "NguyenHongHanhITMO2020";
    printf("%s\n", mas);

    int i = 0, n = 0;
    while(mas[i++]){
        n++;
    }

    printf("%d\n", n);
    for (int i = 0; i < n; i++){
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
    return 0;
}