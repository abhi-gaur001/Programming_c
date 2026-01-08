#include <stdio.h>

float Average(int arr[], int size) {
    float sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int size;
    printf("Enter the number of elements (n): ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d numbers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    float average = Average(arr, size);
    printf("\nAverage of the numbers: %.2f\n", average);

    return 0;
}
