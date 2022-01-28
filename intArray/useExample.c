#include <stdio.h>
#include <stdlib.h>
#include "intArray.h"
#include <time.h>
#define SIZE 10

int main() {
    int i;
    int array[SIZE];
    int value;
    
    srand(time(NULL));
    generateElements(array, SIZE, -10, 20);

    printf("GENERATED ARRAY\n");
    printf(toString(array, SIZE));

    bubbleSort(array, SIZE);
    printf("\n\nSORTED ARRAY\n");
    printf(toString(array, SIZE));


    printf("\n\nMIN: %d\n", min(array, SIZE));
    printf("MAX: %d\n", max(array, SIZE));
    printf("SUM: %d\n", sum(array, SIZE));
    printf("AVERAGE: %.2f\n", average(array, SIZE));

    i = binarySearch(array, SIZE, 10);
    if (i == -1) {
        printf("\n10 not found.\n");
    } else {
        printf("\n10 found at index %d with binary search.\n", i);
    }

    i = linearSearch(array, SIZE, 3);
    if (i == -1) {
        printf("10 not found with linear search.\n");
    } else {
        printf("10 found at index %d with linear search.\n", i);
    }

    printf("\nFrequency of 5: %d\n", frequency(array, SIZE, 5));

    reverse(array, SIZE);

    printf("\nREVERSED ARRAY\n");
    printf(toString(array, SIZE));

    leftShift(array, SIZE, 1);    
    printf("\nLEFT SHIFT\n");
    printf("%s", toString(array, SIZE));

    rightShift(array, SIZE, 1);    
    printf("\nRIGHT SHIFT\n");
    printf("%s", toString(array, SIZE));
    
    swap(array, SIZE, 1, 5);
    printf("\n\nSWAP array[1] and array[5]\n");
    printf(toString(array, SIZE));

    return 0;
}