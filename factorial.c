#include "factorial.h"

unsigned long long factorial_iterative(int n) {
    unsigned long long num = 1;
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        num *= i;
    }
    return num;
}

unsigned long long factorial_recursive(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}
