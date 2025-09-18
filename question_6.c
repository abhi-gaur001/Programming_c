#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    (num & 1) ? printf("Odd\n") : printf("Even\n");

    return 0;
}
