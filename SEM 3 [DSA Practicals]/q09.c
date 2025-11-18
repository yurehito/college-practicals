// Question 9:
// Write a program to implement stack using array. Use push and pop operations.
// Check whether the stack is full or empty.

#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX], top = -1;
    int choice, x;

    while (1) {
        printf("1.push 2.pop 3.display 4.exit: ");
        if (!(scanf("%d", &choice))) break;
        if (choice == 1) {
            if (top == MAX-1) { printf("Stack full\n"); continue; }
            printf("Enter value: "); scanf("%d", &x);
            stack[++top] = x;
        } else if (choice == 2) {
            if (top == -1) { printf("Stack empty\n"); continue; }
            printf("Popped %d\n", stack[top--]);
        } else if (choice == 3) {
            if (top == -1) { printf("Stack empty\n"); continue; }
            for (int i = top; i >= 0; --i) printf("%d ", stack[i]);
            printf("\n");
        } else break;
    }
    return 0;
}
