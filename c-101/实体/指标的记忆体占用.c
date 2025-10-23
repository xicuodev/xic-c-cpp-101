#include <stdio.h>

int main () {
    int v[3] = {2, 1, 3};
    printf("int[3]: %zu\n", sizeof(v)); // (int[3])
    printf("int: %zu\n", sizeof(v[0])); // (int)
    printf("int *: %zu\n", sizeof(&v[0])); // (int *)
    printf("int(*)[3]: %zu\n", sizeof(&v)); // (int(*)[3])
    return 0;
}