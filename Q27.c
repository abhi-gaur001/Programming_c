#include <stdio.h>

// Define Rectangle structure
struct Rectangle {
    int length;
    int breadth;
};

// Function to read rectangle dimensions from user and return a Rectangle
struct Rectangle inputRectangle(void) {
    struct Rectangle r;
    printf("Enter length: ");
    if (scanf("%d", &r.length) != 1) r.length = 0;
    printf("Enter breadth: ");
    if (scanf("%d", &r.breadth) != 1) r.breadth = 0;
    return r;
}

// Function to compute area of a rectangle
int area(struct Rectangle r) {
    return r.length * r.breadth;
}

int main(void) {
    struct Rectangle rect = inputRectangle();
    int a = area(rect);
    printf("Area = %d\n", a);
    return 0;
}
