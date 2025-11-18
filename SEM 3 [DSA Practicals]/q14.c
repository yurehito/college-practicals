// Question 14:
// Write a program to implement queue using linked list. Add new elements to the queue and
// remove elements from the queue represented by linked list. Also check whether the queue is full or empty.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; struct Node *next;
} Node;

void enqueue(Node **front, Node **rear, int v) {
    Node *n = malloc(sizeof(Node)); n->data = v; n->next = NULL;
    if (!*rear) *front = *rear = n;
    else { (*rear)->next = n; *rear = n; }
}

int dequeue(Node **front, Node **rear) {
    if (!*front) { printf("Queue empty\n"); return -1; }
    Node *t = *front; int v = t->data; *front = t->next;
    if (!*front) *rear = NULL;
    free(t); return v;
}

void display(Node *front) {
    if (!front) { printf("Queue empty\n"); return; }
    while(front){ printf("%d ", front->data); front = front->next; }
    printf("\n");
}

int main() {
    Node *front = NULL, *rear = NULL;
    int ch, v;
    while (1) {
        printf("1.enqueue 2.dequeue 3.display 4.exit: "); if(!(scanf("%d",&ch))) break;
        if (ch==1) { printf("Val: "); scanf("%d",&v); enqueue(&front,&rear,v); }
        else if (ch==2) { int x = dequeue(&front,&rear); if (x!=-1) printf("Dequeued %d\n", x); }
        else if (ch==3) display(front);
        else break;
    }
    return 0;
}
