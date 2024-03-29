/*
 * Doubly Linked List
 * Goals:
 *  - [x] Insertion: Beginning, End, Positional
 *  - [x] Deletion: Beginning, End, Positional, Entire LList
 *  - [x] Search: Node by value
 *  - [x] Traversal: print them out ;)
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

void addAtPos(LinkedList* list, int pos, int data) {
    if (pos >= list->size) {
        addAtEnd(list, data);
        return;
    } else if (pos <= 0) {
        addAtStart(list, data);
        return;
    } else {
        Node* tmp = list->head;
        for (int i=0; i<pos-1; i++) {
            tmp = tmp->next;
        }
        Node* newNode = createNode(data);
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        if (tmp->next != NULL) { 
            tmp->next->prev = newNode;
        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }
    list->size++;
}

void deleteAtEnd(LinkedList* list) {
    if (list->size == 0) {
        return;
    } else if (list->size == 1) {
        free(list->tail);
        list->head = NULL;
        list->tail = NULL;
    } else {
        Node* prev = list->tail->prev;
        if (prev != NULL) {
            prev->next = NULL;
        }
        free(list->tail);
        list->tail = prev;
    }
    list->size--;   
}

void deleteAtStart(LinkedList* list) {
    if (list->size == 0) {
        return;
    } else if (list->size == 1) {
        free(list->head);
        list->tail = NULL;
        list->head = NULL;
    } else {
        Node* next = list->head->next;
        if (next != NULL) {
            next->prev = NULL;
        }
        free(list->head);
        list->head = next;
    }
    list->size--;
}

void deleteAtPos(LinkedList* list, int pos) {
    if (list->size == 0) {
        return;
    } else if (list->size == 1 || pos <= 0) {
        deleteAtStart(list);
        return;
    } else if (pos >= list->size-1) {
        deleteAtEnd(list);
        return;
    }
    Node* tmp = list->head;
    for (int i = 0; i < pos; i++) {
        tmp = tmp->next;
    }
    // Overchains the selected node, then frees it from memory
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    list->size--;
}

void deleteList(LinkedList* list) {
    if (list->size == 0) {
        return;
    }
    Node* tmp = list->head;
    while (list->head != NULL) {
        list->head = list->head->next;
        free(tmp);
        tmp = list->head;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Node* searchValue(LinkedList* list, int value) {
    Node* tmp = list->head;
    while (tmp != NULL) {
        if (tmp->data == value) {
            printNode(tmp);
            return tmp;
        }
        tmp = tmp->next;
    }
    printf("Value not found");
    return NULL;
}


int main() {
    LinkedList list;
    initLinkedList(&list);

    addAtEnd(&list, 2);
    addAtEnd(&list, 3);
    addAtEnd(&list, 4);

    addAtStart(&list, 0);

    addAtPos(&list, 1, 1);

    deleteAtPos(&list, 0);


    // deleteAtEnd(&list);
    // deleteAtStart(&list);
    deleteList(&list);

    printFromStart(&list);
    printFromEnd(&list);

    // Node* search = searchValue(&list, 6);

    return EXIT_SUCCESS;
}
