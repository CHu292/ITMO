#include<stdio.h>

int main(){
int a[] = {255, 1024, -1, -2};
int tmp;

for (int j=0; j<4; j++){
        for (int i=0; i<4; i++){
              if (a[i] > a[i+1]){ 
                     tmp = a[i];
                     a[i] = a[i+1];
                     a[i+1] = tmp;
              }
        }
}
int mas[3][3]={{1,2,3},{4,5,6},{7,8,9}};
for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        printf("%d  ",mas[i][j]);
        printf("\n");
    }
printf("\n");

int min = mas[0][0];
for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (min > mas[i][j])  
min = mas[i][j];  
for (int i = 0; i<3; i++)
        mas[i][i] = min;
printf("%d \n",min);
printf("\n");

for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            printf("%d  ",mas[i][j]);
            printf("\n");
}
printf("\n");

int sum1 = 0, sum2 = 0;

 for (int i = 0; i < 3; i++) {
     for (int j = 0; j < 3; j++) 
{
          if (i == 0)
              sum1 += mas[i][j];
          else if (i == 2)
              sum2 += mas[i][j];
     }
  }

  for (int i = 0; i < 3; i++) 
{
      for (int j = 0; j < 3; j++) 
{
          if (i == 0 && j == 2)
              mas[i][j] = sum1;
          if (i == 2 && j == 0)
             mas[i][j] = sum2;

}
}
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++)
        printf("%d ", mas[i][j]);
        printf("\n");
}

return 0;
}

