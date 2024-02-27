/* Queues - LList Edition
 * - [ ] Enqueue: Add an item to the end.
 * - [ ] Dequeue: Remove the item from the beginning.
 * - [ ] Front: Get the first item.
 * - [ ] Rear: Get the last item.
 * - [ ] isEmpty: Check if the queue is empty.
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};

typedef struct queue {
    Node* start;
    Node* end;
    int size;
} Queue;

void initQueue(Queue* queue) {
    queue->start= NULL;
    queue->end = NULL;
    queue->size = 0;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->size == 0) {
        queue->start = newNode;
        queue->end = newNode;
    } else {
        queue->start->prev = newNode;
        newNode->next = queue->start;
        queue->start = newNode;
    }
    queue->size++;
}

int main() {

    Queue queue;
    initQueue(&queue);
    
    return EXIT_SUCCESS;
}
