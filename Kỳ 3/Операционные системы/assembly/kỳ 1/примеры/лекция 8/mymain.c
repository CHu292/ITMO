#include <stdio.h>

int my_main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("arg[%d] = '%s'\n", i, argv[i]);
    }

    return 42;
}

int main(int argc, char *argv[]) {
    int ret = my_main(argc-1, argv+1);
    printf("my_main() returned %d\n", ret);
    return ret;
}

