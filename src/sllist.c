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
}

int main() {
    LinkedList list;
    initLinkedList(&list);

    addAtEnd(&list, 2);
    addAtEnd(&list, 3);
    addAtEnd(&list, 4);
    addAtEnd(&list, 5);
    
    addAtStart(&list, 1);
    addAtStart(&list, 0);

    printList(&list);
    return EXIT_SUCCESS;
}
