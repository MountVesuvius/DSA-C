/* Queues - LList Edition
 * - [x] Enqueue: Add an item to the end.
 * - [x] Dequeue: Remove the item from the beginning.
 * - [x] Front: Get the first item.
 * - [x] Rear: Get the last item.
 * - [x] isEmpty: Check if the queue is empty.
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

int dequeue(Queue* queue) {
    if (queue->size == 0) {
        return -1;
    }
    Node* tmp = queue->end->prev;
    int data = queue->end->data;
    free(queue->end);
    queue->end = tmp;
    queue->end->next = NULL;
    if (queue->size == 1) {
        queue->start = NULL;
    }
    queue->size--;
    return data;
}

void printQueue(Queue* queue) {
    Node* curr = queue->start;
    while (curr->next) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("%d", curr->data);
    printf("\n");
}

void rev_printQueue(Queue* queue) {
    Node* curr = queue->end;
    while (curr->prev) {
        printf("%d -> ", curr->data);
        curr = curr->prev;
    }
    printf("%d", curr->data);
    printf("\n");
}

int front(Queue* queue) {
    return queue->start->data;
}

int end(Queue* queue) {
    return queue->end->data;
}

int isEmpty(Queue* queue) {
    return queue->size < 1;
}

int main() {

    Queue queue;
    initQueue(&queue);

    printf("%d\n", isEmpty(&queue));

    for (int i = 0; i < 10; i++) {
        enqueue(&queue, i+1);
    }

    printf("%d\n", isEmpty(&queue));
    printf("Front: %d\n", front(&queue));
    printf("End: %d\n", end(&queue));

    printQueue(&queue);
    rev_printQueue(&queue);

    for (int i = 0; i < 5; i++) {
        printf("Removed: %d\n", dequeue(&queue));
    }

    printQueue(&queue);

    return EXIT_SUCCESS;
}
