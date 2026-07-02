#include <stdio.h>

#include <stdlib.h>

int main() {

    while (1) {

        void *p = malloc(1024L * 1024 * 1024);

        if (p == NULL) {

            puts("OOM!");

            break;

        }

        printf("%p\n", p);

    }

    return 0;

}