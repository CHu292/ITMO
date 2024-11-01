#include <stdio.h>
#include<stdlib.h>
#include <math.h>

double f1(int);
int f2(void);
int f3(void);
int main()
{
    int(*pf2)(void); 
    pf2=f2;
    pf2();
    pf2=f3;
    printf("%d\n",pf2());

    int(*pmas[])()={f2,f3};
   
    for(int i=0;i<2;i++)
        pmas[i]();
        /*("pmas[i]();")*/

    int Mas[3]={(int)f1, (int)f2, (int) f3};
    double(*pf1)(int);
    pf1=(double(*)(int)) Mas[0];
    double m=pf1(5);
    printf("%f\n",m);

    for(int i=1;i<3;i++)
    {
        pf2=(int(*)())Mas[i];
        pf2();
    }

    /*sin, cos*/
    double fun(double);
    double (*psin)(double);
	double (*pcos)(double);
	psin = sin;
	pcos = cos;
	printf("\n");
	printf("%f\n", psin(0.5));
	printf("%f\n", pcos(0.7));
    /*0.5, 0.2*/
}
double f1(int a)
{
    printf("\ndouble f1(int)");
    double b=a;
    if(!a) return b; 
    else return 1.0/b;
}
int f2(void)
{
    printf("\nint f2(void)");
    return 200;
}
int f3(void)
{
    printf("\nint f3(void)");
    return 300;
}
