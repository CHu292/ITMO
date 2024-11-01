#include <stdio.h>
#include <math.h>
//%e
int main() {
    const double eps = 1.0E-20;
    double a = 1.0, b = 1.0E12, c = 1.0E12;
    double R1, R2, x1, x2;
    R1 = -(b / (2 * a));
    R2 = sqrt(b * b - 4 * a * c) / (2 * a);
    if (R1 > eps)
        x1 = R1 + R2;
    else
        x1 = R1 - R2;
        x2 = c / (a * x1);

    printf("x1 = %e \nx2 = %e", x1, x2);
    return 0;
}