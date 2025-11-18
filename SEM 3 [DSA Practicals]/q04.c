// Question 4:
// Write a program to implement doubly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

DNode* createNode(int val) {
    DNode *n = (DNode*)malloc(sizeof(DNode));
    n->data = val; n->prev = n->next = NULL;
    return n;
}

DNode* append(DNode *head, int val) {
    DNode *n = createNode(val);
    if (!head) return n;
    DNode *t = head;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
    return head;
}

void printForward(DNode *head) {
    DNode *t = head;
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

void printBackward(DNode *head) {
    if (!head) { printf("\n"); return; }
    DNode *t = head;
    while (t->next) t = t->next;
    while (t) { printf("%d ", t->data); t = t->prev; }
    printf("\n");
}

DNode* deleteAtPos(DNode *head, int pos) {
    if (!head) return NULL;
    DNode *t = head;
    int i = 1;
    while (t && i < pos) { t = t->next; i++; }
    if (!t) return head;
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
    return head;
}

int main() {
    int n, i, val;
    DNode *head = NULL;
    printf("How many nodes to create? ");
    if (!(scanf("%d", &n))) return 0;
    for (i = 0; i < n; i++) {
        printf("Value %d: ", i+1); scanf("%d", &val);
        head = append(head, val);
    }
    printf("Forward: "); printForward(head);
    printf("Backward: "); printBackward(head);

    printf("Delete position (1-based): ");
    scanf("%d", &i);
    head = deleteAtPos(head, i);
    printf("After deletion forward: "); printForward(head);

    return 0;
}
