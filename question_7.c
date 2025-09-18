#include <stdio.h>

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    printf("Original value: %d\n", x);
    printf("Pre-increment (++x): %d\n", ++x);
    printf("Value after pre-increment: %d\n", x);
    printf("Post-increment (x++): %d\n", x++);
    printf("Value after post-increment: %d\n", x);

    return 0;
}
