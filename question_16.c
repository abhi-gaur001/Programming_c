#include <stdio.h>

int main() {
    int n, fact = 1;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check for negative input
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int i = n;

        // While loop to calculate factorial
        while (i > 0) {
            fact = fact * i;
            i--;
        }

        printf("Factorial of %d = %d\n", n, fact);
    }

    return 0;
}
