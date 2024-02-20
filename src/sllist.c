/*
 * Singly Linked List
 * Goals:
 *  - [x] Insertion: Beginning, End, Positional
 *  - [ ] Deletion: Beginning, End, Positional
 *  - [x] Search: Node by value
 *  - [x] Traversal: print them out ;)
 */
#include <stdlib.h>
#include <stdio.h>

// The node struct 
typedef struct node {
    int data;
    struct node *next;
} Node;

/* This works as "container" which has the head and 
 * tail pointers for the the list, as well as the
 * size.
 * A nice way to think of these pointers is as labels
 * over nodes. So node1 may be the head node, however
 * the head pointer is the label node1.
 */
typedef struct linkedlist {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

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

void printNode(Node* node) {
    if (node) {
        printf("Value: %d\n", node->data);
        return;
    }
    printf("Node does not exist\n");
}

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

    Node* value = searchValue(&list, 1);
    Node* value2 = searchValue(&list, 10);
    printNode(value);
    printNode(value2);

    return EXIT_SUCCESS;
}
