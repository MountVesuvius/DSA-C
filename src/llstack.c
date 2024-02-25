#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct stack {
    Node* top;
    int size;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL; 
    stack->size = 0;
}

int isEmpty(Stack* stack) {
    if (stack->size <= 0) { return 1; }
    return 0;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; 
    }
    printf("%d\n", stack->top->data);
    return stack->top->data;
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    int data = stack->top->data;
    Node* tmp = stack->top;
    stack->top = tmp->next;
    free(tmp);
    stack->size--;
    return data;
}

void clearStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < 5; i++) {
        push(&stack, i+1);
    }

    peek(&stack);

    // int data = pop(&stack);
    // printf("%d\n", data);
    //
    // peek(&stack);
    //
    // printf("Empty Stack?: %d", isEmpty(&stack));
    // clearStack(&stack);
    // printf("Empty Stack?: %d", isEmpty(&stack));
    //
    return EXIT_SUCCESS;
}
