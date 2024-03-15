#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void print_preorder(Node* root) {
    if (!root) return;

    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(Node* root) {
    if (!root) return;

    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

void print_postorder(Node* root) {
    if (!root) return;

    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
}

int tree_height(Node* root) {
    if (!root) return 0;
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);

    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}

void insert(Node* root, int data) {
    if (data < root->data) {
        if (!root->left) {
            root->left = create_node(data);
        } else {
            insert(root->left, data);
        }
    } else {
        if (!root->right) {
            root->right = create_node(data);
        } else {
            insert(root->right, data);
        }
    }
}

Node* find_min(Node* root) {
    Node* curr = root;
    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}

Node* find_max(Node* root) {
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

int find_value(Node* root, int data) {
    Node* found = _find(root, data);
    if (found) return root->data;
    else return -1;

    return found->data;
}

void delete_tree(Node* root) {
    if (!root) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

int main() {

    Node* root = create_node(3);
    insert(root, 5);
    insert(root, 2);
    insert(root, 1);
    insert(root, 4);

    print_inorder(root);
    printf("\n");

    printf("%d\n", find_value(root, 4));
    printf("%d\n", find_value(root, 12));

    printf("%d\n", tree_height(root));

    delete_tree(root);
    printf("tree deleted");

    return EXIT_SUCCESS;
}
