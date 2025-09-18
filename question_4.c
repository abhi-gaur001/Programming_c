#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    int largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;

    printf("Largest value: %d\n", largest);
    return 0;
}
