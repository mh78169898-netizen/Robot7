#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long fac_r(int n) {
if (n <= 1) {
        return 1;
    }
    return n * fac_r(n - 1);
}

int main() {
    int n = 5;
    long long result = fac_r(n);

    printf("%d\n", n);
    printf("%lld\n", result);

   return 0;
}

long long factorial_dynamic(int n) {
    if (n < 0) {
        return 0;
    }
    if (n <= 1) {
        return 1;
    }

    long long result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int n = 5;
    long long result = factorial_dynamic(n);

    printf("%d\n", n);
    printf("%lld\n", result);
    return 0;
}
