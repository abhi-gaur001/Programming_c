#include <stdio.h>

unsigned long long factorial(int n) {
    if (n <= 1) return 1ULL;        // base case: 0! and 1! = 1
    return (unsigned long long)n * factorial(n - 1);
}

int main(void) {
    int n;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    unsigned long long result = factorial(n);
    printf("Factorial of %d is %llu\n", n, result);
    return 0;
}
