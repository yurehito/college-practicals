// Question 3:
// Implement linked list in a program by writing functions for the following:
// a. Create a singly linked list of n nodes
// b. Count the number of nodes in the list
// c. Print the values of all the nodes
// d. Add a node at first, last and k-th position in the linked list
// e. Delete a node from first, last and k-th position
// f. Search for an element in the list. If found, return its position, otherwise return a negative value.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    int i, value;
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    return head;
}

int countNodes(struct Node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void printList(struct Node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* insertFirst(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node* insertLast(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) return newNode;

    struct Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

struct Node* insertAtK(struct Node *head, int value, int k) {
    if(k == 1) return insertFirst(head, value);

    struct Node *temp = head;
    int i;

    for(i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) return head;

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* deleteFirst(struct Node *head) {
    if(head == NULL) return NULL;
    struct Node *temp = head->next;
    free(head);
    return temp;
}

struct Node* deleteLast(struct Node *head) {
    if(head == NULL) return NULL;

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

struct Node* deleteAtK(struct Node *head, int k) {
    if(k == 1) return deleteFirst(head);

    struct Node *temp = head;
    int i;

    for(i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) return head;

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);

    return head;
}

int search(struct Node *head, int key) {
    int pos = 1;
    while(head != NULL) {
        if(head->data == key) return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = createList(n);

    printf("\nList: ");
    printList(head);

    printf("Total nodes: %d\n", countNodes(head));

    head = insertFirst(head, 100);
    head = insertLast(head, 200);
    head = insertAtK(head, 999, 3);

    printf("\nAfter insertions: ");
    printList(head);

    head = deleteFirst(head);
    head = deleteLast(head);
    head = deleteAtK(head, 2);

    printf("After deletions: ");
    printList(head);

    int key;
    printf("\nEnter number to search: ");
    scanf("%d", &key);

    int pos = search(head, key);
    if(pos > 0)
        printf("Found at position %d\n", pos);
    else
        printf("Not found.\n");

    return 0;
}
