#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printInOrder(Node* root) {
    if (!root) return;

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void insert(Node* root, int data) {
    if (data < root->data) {
        if (!root->left) {
            root->left = createNode(data);
        } else {
            insert(root->left, data);
        }
    } else {
        if (!root->right) {
            root->right = createNode(data);
        } else {
            insert(root->right, data);
        }
    }
}

Node* findMin(Node* root) {
    Node* curr = root;
    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}

Node* findMax(Node* root) {
    Node* curr = root;
    while (curr->right) {
        curr = curr->right;
    }
    return curr;
}

Node* _find(Node* root, int data) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data) return _find(root->left, data);
    return _find(root->right, data);
}

int findValue(Node* root, int data) {
    Node* found = _find(root, data);
    if (found) printf("%d\n", found->data);
    else printf("not found");

    return found->data;
}

int main() {

    Node* root = createNode(5);
    insert(root, 1);
    insert(root, 4);
    insert(root, 2);
    insert(root, 3);

    printInOrder(root);
    printf("\n");

    // printf("%d\n", findMin(root)->data);

    // printf("%d\n", findValue(root, 3)->data);


    return EXIT_SUCCESS;
}
