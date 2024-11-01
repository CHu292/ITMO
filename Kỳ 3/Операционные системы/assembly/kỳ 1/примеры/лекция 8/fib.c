#include <stdio.h>
/*
int fib(int n) {
    int res = 1;
	if (n > 2) 
	    res = fib(n-1) + fib(n-2);
	return res;
}
*/

int fib(int n) {
	if (n < 3) return 1;
	return fib(n-1) + fib(n-2);
}


int main() {
    int n = 5;

    int res = fib(n);

    printf("fib(%d) = %d\n", n, res);
    return 0;
}
