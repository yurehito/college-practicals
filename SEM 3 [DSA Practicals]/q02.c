// Question 2:
// Write a program to implement array initialized with the numbers divisible by three up to 30.
// Write a function which accepts the array and returns the positions of the even numbers.

#include <stdio.h>

void printEvenPositions(int arr[], int size) {
    int i;
    printf("Positions of even numbers are: ");
    for(i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() {
    int arr[10];
    int i, value = 3;

    for(i = 0; i < 10; i++) {
        arr[i] = value;
        value += 3;
    }

    printf("Array elements: ");
    for(i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printEvenPositions(arr, 10);

    return 0;
}
