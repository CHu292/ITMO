#include <stdio.h>
#include <math.h>

double trigonom(double a)
{
return sin(a);
}

double function(double (*f)(double), double a)
{
return f(a);
}

int main()
{
double a = 3;
double result;
result = function(trigonom, a);
printf("%f", result);
return 0;
}