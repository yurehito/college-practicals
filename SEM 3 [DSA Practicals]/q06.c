// Question 6:
// Write a program to take a number k and split the linked list after k-th position.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* append(Node *head, int x) {
    Node *n = malloc(sizeof(Node)); n->data = x; n->next = NULL;
    if (!head) return n;
    Node *t = head; while (t->next) t = t->next; t->next = n;
    return head;
}

void printList(Node *h) {
    while (h) { printf("%d ", h->data); h = h->next; }
    printf("\n");
}

Node* splitAfterK(Node *head, int k) {
    if (!head || k <= 0) return head; // nothing to split
    Node *t = head;
    int i = 1;
    while (t && i < k) { t = t->next; i++; }
    if (!t || !t->next) return NULL; // no second part
    Node *second = t->next;
    t->next = NULL;
    return second;
}

int main() {
    int n, i, x, k;
    Node *head = NULL;
    printf("No. of nodes: "); scanf("%d", &n);
    for (i=0;i<n;i++){ scanf("%d", &x); head = append(head, x); }
    printf("Original list: "); printList(head);
    printf("Split after position k: "); scanf("%d", &k);
    Node *second = splitAfterK(head, k);
    printf("First part: "); printList(head);
    printf("Second part: "); printList(second);
    return 0;
}
