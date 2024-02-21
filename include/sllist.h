#ifndef SLLIST_H
#define SLLIST_H

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


void initLinkedList(LinkedList* list);

Node* createNode(int data);

void printNode(Node* node);


#endif
