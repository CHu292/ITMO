#include <stdio.h>

int foo(int x, long y, double z, char *s) {
    printf(s);
    long zz = x + y;
    double yy = zz * z;
    return (int)yy;
}

int main() {
	int x = 0xabcdef00;
	long y = 0x0123456789abcdef;
	double z = 3.14;
	foo(x, y, z, "hello!");
	return 0;
}
