// Question 17:
// Implement binary search tree using linked list by writing a program to:
// a. Create a binary search tree using linked list
// b. Print the prefix notation of the BST
// c. Print the infix notation of the BST
// d. Print the postfix notation of the BST
// e. Search for an element in the BST

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int v) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) { printf("Memory error\n"); exit(1); }
    p->val = v; p->left = p->right = NULL; return p;
}

/* Standard BST insert */
Node* insert(Node *root, int v) {
    if (!root) return newNode(v);
    if (v <= root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

void preorder(Node *r) {
    if (!r) return;
    printf("%d ", r->val);
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node *r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->val);
    inorder(r->right);
}

void postorder(Node *r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->val);
}

Node* search(Node *r, int key) {
    while (r) {
        if (r->val == key) return r;
        if (key < r->val) r = r->left;
        else r = r->right;
    }
    return NULL;
}

void freeTree(Node *r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    free(r);
}

int main() {
    Node *root = NULL;
    int n, i, x;
    printf("How many nodes to insert? ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    printf("Enter %d values (space or newline separated):\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("\nPreorder (prefix): ");
    preorder(root);
    printf("\nInorder (infix): ");
    inorder(root);
    printf("\nPostorder (postfix): ");
    postorder(root);
    printf("\n");

    printf("\nEnter value to search: ");
    if (scanf("%d", &x) == 1) {
        Node *found = search(root, x);
        if (found) printf("Found node with value %d\n", found->val);
        else printf("Not found\n");
    }

    freeTree(root);
    return 0;
}
