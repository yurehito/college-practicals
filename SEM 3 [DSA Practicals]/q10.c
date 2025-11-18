// Question 10:
// Write a program to implement stack using linked list. Use push and pop operations.
// Also check if the stack is full or empty.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; struct Node *next;
} Node;

Node* push(Node *top, int v) {
    Node *n = malloc(sizeof(Node)); n->data = v; n->next = top; return n;
}

Node* pop(Node *top) {
    if (!top) { printf("Stack empty\n"); return NULL; }
    Node *t = top->next;
    printf("Popped %d\n", top->data);
    free(top);
    return t;
}

void printStack(Node *top) {
    if (!top) { printf("Stack empty\n"); return; }
    Node *t = top;
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

int main() {
    Node *top = NULL;
    int ch, v;
    while (1) {
        printf("1.push 2.pop 3.display 4.exit: "); if(!(scanf("%d",&ch))) break;
        if (ch == 1) { printf("Val: "); scanf("%d",&v); top = push(top,v); }
        else if (ch == 2) top = pop(top);
        else if (ch == 3) printStack(top);
        else break;
    }
    return 0;
}
