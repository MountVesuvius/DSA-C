/*
 * Doubly Linked List
 * Goals:
 *  - [ ] Insertion: Beginning, End, Positional
 *  - [ ] Deletion: Beginning, End, Positional, Entire LList
 *  - [ ] Search: Node by value
 *  - [ ] Traversal: print them out ;)
 */

#include <stdio.h>
#include <stdlib.h>

// The node struct 
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

void printNode(Node* node) {
    if (node) {
        printf("Value: %d\n", node->data);
        return;
    }
    printf("Node does not exist\n");
}

typedef struct linkedlist {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

void initLinkedList(LinkedList* list)  {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void printFromStart(LinkedList* list) {
    Node* tmp = list->head;
    while (tmp != NULL) {
        printf("%d,", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void printFromEnd(LinkedList* list) {
    Node* tmp = list->tail;
    while (tmp != NULL) {
        printf("%d,", tmp->data);
        tmp = tmp->prev;
    }
    printf("\n");
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addAtEnd(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail= newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->size++;
}

void addAtStart(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->tail == NULL) {
        list->tail = newNode;
        list->head = newNode;
    } else {
        list->head->prev = newNode;
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;
}


int main() {
    LinkedList list;
    initLinkedList(&list);

    addAtEnd(&list, 2);
    addAtEnd(&list, 4);
    addAtEnd(&list, 6);

    addAtStart(&list, 0);

    printFromStart(&list);
    printFromEnd(&list);

    return EXIT_SUCCESS;
}
