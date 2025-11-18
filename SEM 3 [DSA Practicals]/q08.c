// Question 8:
// Write a program to implement list of lists.
// (Simple implementation: a list where each node holds a head pointer to its own sublist.)

#include <stdio.h>
#include <stdlib.h>

typedef struct Sub {
    int data; struct Sub *next;
} Sub;

typedef struct LNode {
    Sub *subHead;
    struct LNode *next;
} LNode;

Sub* appendSub(Sub *h, int v) {
    Sub *n = malloc(sizeof(Sub)); n->data = v; n->next = NULL;
    if(!h) return n;
    Sub *t=h; while(t->next) t=t->next; t->next=n; return h;
}

LNode* appendList(LNode *h, Sub *sub) {
    LNode *n = malloc(sizeof(LNode)); n->subHead = sub; n->next = NULL;
    if(!h) return n;
    LNode *t=h; while(t->next) t=t->next; t->next=n; return h;
}

void printAll(LNode *h) {
    int idx = 1;
    while(h) {
        printf("Sublist %d: ", idx++);
        Sub *s = h->subHead;
        while(s) { printf("%d ", s->data); s = s->next; }
        printf("\n");
        h = h->next;
    }
}

int main() {
    LNode *mainList = NULL;
    int lists = 2, i, items, v;
    for(i=0;i<lists;i++){
        printf("Enter size of sublist %d: ", i+1); scanf("%d",&items);
        Sub *s = NULL;
        int j;
        for(j=0;j<items;j++){ scanf("%d",&v); s = appendSub(s,v); }
        mainList = appendList(mainList, s);
    }
    printAll(mainList);
    return 0;
}
