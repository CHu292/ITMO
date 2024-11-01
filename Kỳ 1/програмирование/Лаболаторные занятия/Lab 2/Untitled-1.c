#include <stdio.h>
int main()
{
int mas[4] = { 2000, 1024, -1, -2 };
int tmp;

for (int i = 0; i < 4; i++) {
printf("%d ", mas[i]);
}
printf("\n");
for (int i = 0; i < 4; i++) {
for (int j = i; j < 4; j++) {
if (mas[i] < mas[j]) {
tmp = mas[i];
mas[i] = mas[j];
mas[j] = tmp;
if (!i)

}
}
}
if (!flag)
printf("array is sorted");
else
for (int i = 0; i < 4; i++) {
printf("%d ", mas[i]);
}

printf("\n");
int mas2[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int wow = 99999999, bufi = 0, bufj = 0;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++)
printf("%d ", mas2[i][j]);
printf("\n");
}
printf("\n");
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
if (wow > mas2[i][j]) {
wow = mas2[i][j];
bufi = i;
bufj = j;
}
}
}
for (int i = 0; i < 3; i++) {
mas2[i][i] = mas2[bufi][bufj];
}
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++)
printf("%d ", mas2[i][j]);
printf("\n");
}
printf("\n");
int sum1 = 0, sum2 = 0;
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
if (i == 0)
sum1 += mas2[i][j];
else if (i == 2)
sum2 += mas2[i][j];
if (i == 0 && j == 2)
mas2[i][j] = sum1;
}
}
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
if (i == 2 && j == 0)
mas2[i][j] = sum2;
}
}
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++)
printf("%d ", mas2[i][j]);
printf("\n");
}
return 0;
}