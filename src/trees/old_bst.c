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

/*
 * I did this to avoid weird insertions that didn't make sense to me.
 * For example this was what I was doing before:
 *      insertNode(&((*root)->left), data);
 * It only needed a single function but it was personally hard to understand.
 * If I find a better way in future I will learn to do it that way
 */
static void insert(Node* root, int data) {
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

void insertNode(Node** root, int data) {
    if (!*root) {
        *root = createNode(data);
    } else {
        insert(*root, data);
    }
} 

Node* findMin(Node* root) {
    Node* curr = root;
    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}

Node* deleteNode(Node* root, int data) {
    if (!root) return root;

    // trace to selected node
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
        return root;
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
        return root;
    }

    // free single child
    if (root->left == NULL) {
        Node* tmp = root->right;
        free(root);
        return tmp;
    } else if (root->right == NULL) {
        Node* tmp = root->left;
        free(root);
        return tmp;
    } else {
        // in order successor
        Node* parent = root;
        Node* child = root->right;
        while (child->left != NULL) {
            parent = child;
            child = child->left;
        }

        if (parent != root) {
            parent->left = child->right;
        } else {
            parent->right = child->right;
        }

        root->data = child->data;
        free(child);
        return root;
    }
}


void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    printf("%d, ", root->data);
    inOrder(root->right);
}


int main() {
    Node *root = NULL;
    
    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 4);
    insertNode(&root, 6);
    insertNode(&root, 8);
    insertNode(&root, 1);

    inOrder(root);
    printf("\n");

    // printf("\n%d\n", findMin(root)->data);
    deleteNode(root, 1);

    deleteNode(root, 7);
    inOrder(root);
    printf("\n");


    return EXIT_SUCCESS;
}
