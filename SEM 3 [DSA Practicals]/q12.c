// Question 12:
// Write a program to convert a decimal number into binary number using stack.

#include <stdio.h>

int main() {
    int n, stack[64], top = -1;
    printf("Enter decimal: "); if(!(scanf("%d",&n))) return 0;
    if (n == 0) { printf("0\n"); return 0; }
    while (n > 0) { stack[++top] = n % 2; n /= 2; }
    printf("Binary: ");
    while (top >= 0) printf("%d", stack[top--]);
    printf("\n");
    return 0;
}
