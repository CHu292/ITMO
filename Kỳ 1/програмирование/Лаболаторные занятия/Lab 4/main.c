#include <stdio.h>

int main(){
    // задание 1
    int A = 0x8520ABCD;
    int *pA;
    pA = &A; //
    /*unsigned short B = *((short*)pA);
    unsigned short C = *((short*)pA + 1);
    *((short*)pA + 1) = B;
    *((short*)pA) = C;
    */
    for (int i = 3; i >= 0; i--){
        printf("%x", *((unsigned char*)pA + i));
        if (i == 2 || i == 0){
            printf("\n");
        }
    }

    for (int i = 0; i < 4; i++){
        printf("%x", *((unsigned char*)pA + i));
    }

    printf("\n");
    // задание 2
    char target[9] = "ITMO";
    char source[] = "FBIT";
    char *sptr = source; 
    char *tptr = target;
    // 1 вариант
    /*while (*tptr != '\0'){
        tptr++;
    }*/

    /*while ((*tptr = *sptr) != '\0'){
        tptr++;
        sptr++;
    }*/
    // 2 вариант
    while (*tptr++);
    tptr--;
    while (*tptr++ = *sptr++);
    printf("%s", target);
    return 0;
}