#include <stdio.h>
#include <math.h>

double f1(double(*)(double), double);

int main()
{
    double (*pe)(double) = sin;
    double s = 1.57;
    printf("%g", f1(pe,s));
    return 0;
}

double f1(double(*pf)(double), double s)
{
    return pf(s);
}
