// Question 5:
// Write a function to concatenate two linked lists.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* tail(Node *head) {
    if (!head) return NULL;
    while (head->next) head = head->next;
    return head;
}

Node* append(Node *head, int val) {
    Node *n = malloc(sizeof(Node));
    n->data = val; n->next = NULL;
    if (!head) return n;
    tail(head)->next = n;
    return head;
}

Node* concat(Node *a, Node *b) {
    if (!a) return b;
    tail(a)->next = b;
    return a;
}

void printList(Node *h) {
    while (h) { printf("%d ", h->data); h = h->next; }
    printf("\n");
}

int main() {
    Node *a = NULL, *b = NULL;
    int i, n, val;

    printf("First list size: "); scanf("%d", &n);
    for (i=0;i<n;i++){ scanf("%d", &val); a = append(a, val); }

    printf("Second list size: "); scanf("%d", &n);
    for (i=0;i<n;i++){ scanf("%d", &val); b = append(b, val); }

    printf("List A: "); printList(a);
    printf("List B: "); printList(b);

    a = concat(a, b);
    printf("After concatenation: "); printList(a);

    return 0;
}
