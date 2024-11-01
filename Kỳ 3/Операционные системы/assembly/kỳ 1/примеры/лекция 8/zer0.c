// Note that this gets SIGFPE despite integer arithmetic

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int zer0(int n) {
    //printf("n = %d\n", n);
    return 42 / n;
}

int main() {
    srand(time(NULL));
    zer0( rand() % 2 );
    return 0;
}

