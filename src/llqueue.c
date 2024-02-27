#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

typedef struct queue {
    Node* head;
    Node* tail;
    int size;
} Queue;

void initQueue(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

int main() {

    Queue queue;
    initQueue(&queue);
    
    return EXIT_SUCCESS;
}
