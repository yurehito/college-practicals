// Question 1:
// Write a program to declare an array and initialize the values according to the user.
// Now ask the user for a number n and return the n-th element from the array.

#include <stdio.h>

int main() {
    int n, i, pos;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position n: ");
    scanf("%d", &pos);

    if(pos >= 1 && pos <= n) {
        printf("The %d-th element is: %d\n", pos, arr[pos - 1]);
    } else {
        printf("Invalid position.\n");
    }

    return 0;
}
