#include <stdio.h>
#include <stdlib.h>

#define STACK_LIMIT 10

int stack[STACK_LIMIT];
int size = 0;

void push(int data) {
    if (size > STACK_LIMIT) {
        return;
    }
    stack[size] = data;
    size++;
}

// assumes positive stack values
// it's really dumb ik
int pop() {
    if (size == 0) {
        return 0;
    }
    size--;
    int value = stack[size];
    stack[size] = -1;
    return value;
}

int peak() {
    if (size == 0) {
        return 0;
    }
    printf("Peaked: %d\n", stack[size-1]);
    return stack[size-1];
    
}

int isEmpty() {
    if (size == 0) {
        printf("yep, empty");
        return 1;
    } else {
        printf("nope, full");
        return 0;
    }
}

void printStack() {
    for (int i = 0; i < STACK_LIMIT; i++) {
        printf("%d,", stack[i]);
    }
    printf("\n");
}


int main() {
    for (int i = 0; i < 5; i++) {
        push(i+1);
    }

    printStack();

    int value = pop();

    printStack();

    peak();

    
    return EXIT_SUCCESS;
}
