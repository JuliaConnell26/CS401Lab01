#include <stdio.h>
#include "factorial.h"
#include "factorial.c"

int main() {
    int test[] = {0, 1, 5, 10, 15, 20}; 
    int num = sizeof(test) / sizeof(test[0]);
    for (int i = 0; i < num; i++) {
        int n = test[i]; 
        if (n > MAX) {
            printf("Input exceeds maximum value %d.\n", MAX);
            continue;
        }
        unsigned long long res1 = factorial_iterative(n);
        unsigned long long res2 = factorial_recursive(n);
        printf("Iterative Factorial of %d: %llu\n", n, res1);
        printf("Recursive Factorial of %d: %llu\n", n, res2);
    }
    return 0;
}