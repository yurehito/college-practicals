// Question 7:
// Write a program to merge two sorted linked lists.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val; struct Node *next;
} Node;

Node* append(Node *h, int v) {
    Node *n = malloc(sizeof(Node)); n->val = v; n->next = NULL;
    if (!h) return n;
    Node *t = h; while (t->next) t = t->next; t->next = n;
    return h;
}

Node* mergeSorted(Node *a, Node *b) {
    Node dummy; Node *tail = &dummy; dummy.next = NULL;
    while (a && b) {
        if (a->val <= b->val) { tail->next = a; a = a->next; }
        else { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

void printList(Node *h) { while (h) { printf("%d ", h->val); h = h->next; } printf("\n"); }

int main() {
    int n, i, x;
    Node *a=NULL, *b=NULL;
    printf("Size of first sorted list: "); scanf("%d",&n);
    for(i=0;i<n;i++){ scanf("%d",&x); a = append(a,x); }
    printf("Size of second sorted list: "); scanf("%d",&n);
    for(i=0;i<n;i++){ scanf("%d",&x); b = append(b,x); }
    printf("A: "); printList(a);
    printf("B: "); printList(b);
    Node *m = mergeSorted(a,b);
    printf("Merged: "); printList(m);
    return 0;
}
