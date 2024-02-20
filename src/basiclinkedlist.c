#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

// Node** head, points to the head pointer
// O(1)
void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// O(n), need a tail pointer to be O(1)
void insertTail(Node* head, int data) {
    while (head->next != NULL) {
        head = head->next;
    }
    Node* newNode = createNode(data);
    head->next = newNode;
}

void printList(Node* head) {
    while (head->next != NULL) {
        printf("%d,", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}

// Search to my knowledge has to be O(n), as you have to start from the head
void findItem(Node* head, int search) {
    while (head != NULL) {
        if (head->data == search) {
            printf("Found: %d\n", search);
            return;
        }
        head = head->next;
    }
    printf("Item not found\n");
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);
    insertHead(&head, 40);

    insertTail(head, 50);

    printList(head);

    findItem(head, 10);
    findItem(head, 11);
    return 0;
}
