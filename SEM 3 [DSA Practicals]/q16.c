// Question 16:
// Implement binary search tree using array by writing a program to:
// a. Create a binary search tree using array
// b. Print the prefix notation of the BST
// c. Print the infix notation of the BST
// d. Print the postfix notation of the BST
// e. Search for an element in the BST

#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int tree[MAX];
int present[MAX];

void insert_array_bst(int val) {
    int idx = 0;
    while (idx < MAX) {
        if (!present[idx]) {
            tree[idx] = val;
            present[idx] = 1;
            return;
        }
        if (val <= tree[idx]) idx = 2*idx + 1;
        else idx = 2*idx + 2;
    }
    printf("Insertion overflow: cannot insert %d (array full or index out of range)\n", val);
}

void preorder_array(int idx) {
    if (idx >= MAX || !present[idx]) return;
    printf("%d ", tree[idx]);
    preorder_array(2*idx + 1);
    preorder_array(2*idx + 2);
}

void inorder_array(int idx) {
    if (idx >= MAX || !present[idx]) return;
    inorder_array(2*idx + 1);
    printf("%d ", tree[idx]);
    inorder_array(2*idx + 2);
}

void postorder_array(int idx) {
    if (idx >= MAX || !present[idx]) return;
    postorder_array(2*idx + 1);
    postorder_array(2*idx + 2);
    printf("%d ", tree[idx]);
}

int search_array(int val) {
    int idx = 0;
    while (idx < MAX && present[idx]) {
        if (tree[idx] == val) return idx;
        if (val < tree[idx]) idx = 2*idx + 1;
        else idx = 2*idx + 2;
    }
    return -1;
}

int main() {
    int n, i, v, pos;
    for (i = 0; i < MAX; ++i) present[i] = 0;

    printf("How many nodes to insert? ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    printf("Enter %d values (space or newline separated):\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &v);
        insert_array_bst(v);
    }

    printf("\nPreorder (prefix): ");
    preorder_array(0);
    printf("\nInorder (infix): ");
    inorder_array(0);
    printf("\nPostorder (postfix): ");
    postorder_array(0);
    printf("\n");

    printf("\nEnter value to search: ");
    if (scanf("%d", &v) == 1) {
        pos = search_array(v);
        if (pos >= 0) printf("Found at array index %d\n", pos);
        else printf("Not found\n");
    }

    return 0;
}
