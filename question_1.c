#include <stdio.h>

int main() {
    float l, w, area, perimeter;
    printf("Enter length of rectangle: ");
    scanf("%f", &l);
    printf("Enter width of rectangle: ");
    scanf("%f", &w);
    area = l * w;
    perimeter = 2 * (l + w);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
    return 0;
}
