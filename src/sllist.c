/*
 * Singly Linked List
 * Goals:
 *  - [x] Insertion: Beginning, End, Positional
 *  - [x] Deletion: Beginning, End, Positional, Entire LList
 *  - [x] Search: Node by value
 *  - [x] Traversal: print them out ;)
 */

#include <stdlib.h>
#include <stdio.h>
#include "../include/sllist.h"

void printNode(Node* node) {
    if (node) {
        printf("Value: %d\n", node->data);
        return;
    }
    printf("Node does not exist\n");
}

// Init the llist to nothing as it's empty
void initLinkedList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Node* createNode(int data) {
    // This allocates a block of memory equal to the size
    // of the Node struct. malloc returns a void pointer
    // so you need to cast it to the same pointer type as
    // the the variable you want
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

// O(1)
void addAtEnd(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    // The list is empty, so both the head and the tail 
    // are the same node in the llist
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    // The tail is also a node, so point the tail->next
    // to the new node. then you can just set the new
    // node as the tail. no need for tmp swapping
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// This works similarly to addAtEnd() however the case
// when a list already exists needs to be flipped
// O(1)
void addAtStart(LinkedList* list, int data) {
    Node* newNode = createNode(data);

    if (list->tail == NULL) {
        list->tail = newNode;
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;
}

// Linear traversal to location so O(n)
void addAtPos(LinkedList* list, int data, int pos) {
    if (pos > list->size-1) {
        addAtEnd(list, data);
    } else if (pos <= 0) {
        addAtStart(list, data);
    } else {
        // Travel to one node before the position of
        // insertion
        Node* curr = list->head;
        for (int i; i < pos-1; i++) {
            curr = curr->next;
        }
        Node* newNode = createNode(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Frees the head, and replaces the node head is
// pointing to.
void deleteAtStart(LinkedList* list) {
    // Don't delete non-existing nodes
    if (list->head == NULL) {
        return;
    } 
    // Free from memory
    Node* tmp = list->head->next;
    free(list->head);
    list->head = tmp;
    // Clear out the tail pointer as well
    if (list->size == 1) {
        list->tail = NULL;
    }
    list->size--;
}

// Without double linkage the only way is to traverse
// linearly then remove the tail when the 2nd last node
// is reached
void deleteAtEnd(LinkedList* list) {
    if (list->tail == NULL) {
        return;
    } else if (list->size == 1) {
        free(list->tail);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }
    Node* curr = list->head;
    for (int i=0; i < list->size-1; ++i) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    list->tail = curr;
    list->size--;
}

// This requires a linear traversal, therefore O(n)
void deleteAtPos(LinkedList* list, int pos) {
    if (list->size == 0) {
        return;
    } else if (list->size == 1 || pos <= 0) {
        deleteAtStart(list);
        return;
    } else if (pos >= list->size) {
        deleteAtEnd(list);
        return;
    } 

    Node* curr = list->head;
    for (int i = 0; i < pos - 1; ++i) {
        curr = curr->next;
    }
    Node* tmp = curr->next;
    curr->next = tmp->next;
    // reupdates the tail incase node deleted is the
    // 2nd last node
    if (tmp->next == NULL) {
        list->tail = curr;
    }
    free(tmp);
    list->size--;
}

// Frees all nodes from memory and resets the llist.
// Allows for list to be reused if that usecase is required
void deleteList(LinkedList* list) {
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

// Linear search, O(n)
Node* searchValue(LinkedList* list, int value) {
    Node* curr = list->head;
    while (curr != NULL) {
        if (curr->data == value) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void printList(LinkedList* list) {
    // This requires a current Node pointer as if you
    // do the regular cycling through the llist from
    // the head, you will destory the llist. head is
    // a pointer to the node, no the node itself
    Node* curr = list->head;
    while (curr != NULL) {
        printf("%d,", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Testing llist operations
int main() {
    LinkedList list;
    initLinkedList(&list);

    addAtEnd(&list, 3);
    printList(&list);
    
    addAtStart(&list, 1);
    printList(&list);

    addAtPos(&list, 2, 1);
    addAtPos(&list, 0, 0);
    addAtPos(&list, 4, 5);
    printList(&list);

    // Node* value = searchValue(&list, 1);
    // Node* value2 = searchValue(&list, 10);
    // printNode(value);
    // printNode(value2);
    //
    // deleteAtStart(&list);
    // printList(&list);
    //
    // deleteAtEnd(&list);
    // printList(&list);
    //
    deleteAtPos(&list, 1);
    printList(&list);

    // deleteAtPos(&list, 0);
    // printList(&list);
    //
    deleteAtPos(&list, 20);
    printList(&list);

    deleteList(&list);
    printList(&list);


    return EXIT_SUCCESS;
}
