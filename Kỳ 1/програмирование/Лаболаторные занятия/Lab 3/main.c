#include <stdio.h>

int mas[3][3] = {{10, 60, 90}, {20, 50, 40}, {70, 30, 80}};

void fun1 (int mas[][3], int n, int a, int b);
void prtmas();
int sum (int mas[][3], int a);

int main(){
    prtmas();
    int tmp;
    for (int i = 0; i < 3; i++){
        tmp = mas[1][i];
        mas[1][i] = mas[2][i];
        mas[2][i] = tmp;
    }
    prtmas();
    fun1(mas, 3, 1, 2);
    prtmas();
    
    for (int i = 0; i < 2; i++){
        int sumi = 0;
        for (int j = 0; j < 3; j++)
            sumi += mas[i][j];
    
        for (int k = i + 1; k < 3; k++){
            int sumk = 0;
            for (int j = 0; j < 3; j++)
                sumk += mas[k][j];
            if (sumi > sumk){
                fun1(mas, 3, i, k);
                sumi = sumk;
            }
        }
    }
    prtmas();
    
    for (int i = 0; i < 3; i++){
        int sum = 0;
        for (int j = 0; j < 3; j++){
            sum += mas[i][j];
        }   
        printf("%d  ", sum);       
    }  

}

void prtmas(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d  ", mas[i][j]);
        }   
        printf("\n");
    }  
    printf("\n");
}
void fun1 (int mas[][3], int n, int a, int b){
    int tmp; 
    for (int i = 0; i < 3; i++){
        tmp = mas[a][i];
        mas[a][i] = mas[b][i];
        mas[b][i] = tmp;
    }
}



