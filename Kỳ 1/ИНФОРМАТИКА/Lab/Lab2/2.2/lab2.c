#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prtBin(int n){					//Выводить двоичное представление на экран.
    int i = sizeof(int) * 8 - 1;
    while (!(n >> i & 1)){			//Игнорировать бессмысленные нули
        i--;
    }
    for (i; i >= 0; i--){
        printf("%d", n >> i & 1);
    }
    printf("\n");
}
int imp(int a, int b){				//Побитовая импликация.
    return (~a)|b;
}
int rankByte(int a){				//Ранг байта.
    int b = a % 16; a >>= 4;
    return imp(b,a);				//Импликация младшей и старшей тетрад.
}
int getByte(int x, int pos){		//Получить байт, который находится на позиции pos.
    return (x >> (8 * pos)) & 0x000000ff;
}
void putByte(int* x, int a, int pos){	//Поместить байт a в позицию pos
    *x = *x & (~((0xff << (pos * 8)))); //pos-й байт = 0
    *x = *x | (a << (pos * 8));
}
int main()
{
    srand(time(NULL));					//Получить случайное целое типа int.
	int x = rand();
	printf("x = %x\n", x);
	prtBin(x);							//Выводить его двоичное представление на экран.
    for (int i = 0; i < 3; i++){			//Упорядочить байты числа по возрастанию их рангов.
        for (int j = i + 1; j < 4; j++){
            if (rankByte(getByte(x, i)) > rankByte(getByte(x, j))){ 		//Проверить условие.
                putByte(&x, a, j);			//Поменять местами два байта.
                putByte(&x, b, i);
            }
        }
    }
    printf("x = %x\n", x);
    prtBin(x);							//Выводить на экран двоичное представление результата преобразования.
    return 0;							//Завершить программу.
}
