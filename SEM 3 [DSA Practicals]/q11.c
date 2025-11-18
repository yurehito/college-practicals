// Question 11:
// Write a program to evaluate a simple postfix expression using stack.
// (Supports single-digit operands and operators + - * / with space-separated tokens)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int stack[100], top = -1;
void push(int v){ stack[++top]=v; }
int pop(){ return stack[top--]; }

int main() {
    char expr[200];
    printf("Enter postfix (space separated):\n");
    getchar(); // consume leftover
    if (!fgets(expr, sizeof(expr), stdin)) return 0;
    char *tok = strtok(expr, " \n");
    while(tok) {
        if(isdigit(tok[0]) && tok[1] == '\0') push(tok[0]-'0');
        else {
            int b = pop(), a = pop();
            switch(tok[0]) {
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }
        tok = strtok(NULL, " \n");
    }
    if (top==0) printf("Result: %d\n", pop());
    else printf("Invalid expression\n");
    return 0;
}
