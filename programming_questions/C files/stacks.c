#include<stdio.h>
#include<stdlib.h>

enum bool {
    false,
    true
};

struct Stack {
    int top;
    unsigned capacity;
    int *arr;
}stack;

enum bool isEmpty(struct Stack *stack){

    if (stack->top == -1) return true;
    
    return false;
}

enum bool isFull(struct Stack *stack) {

    if (stack->top == stack->capacity) {
        return true;
    }

    return false;
}

struct Stack* createStack(unsigned limit){

    struct Stack *stack  = (struct Stack*)malloc(sizeof(stack));
    stack->capacity = limit;
    stack->top = -1;
    stack->arr = (int *)malloc(sizeof(int) * stack->capacity);

    return stack;
}

void push(int val, struct Stack* stack) {

    if (isFull(stack)) {
        printf("stack overflow");
        return;
    }else {
        stack->arr[++stack->top] = val;
        printf("pushed ele %d to stack\n",val);
    }
}

int pop(struct Stack *stack) {

    if (isEmpty(stack)) {
        printf("stack underflow");
        return 0;
    } else {
        int ele = stack->arr[stack->top];
        stack->top--;
        printf("Element popped %d\n",ele);
    }
  
    return 0;  
}

int peek(struct Stack *stack)
{

    if (isEmpty(stack)) {
        printf("stack is empty\n");
        return 0;
    } else {
        printf("Peek: %d\n",stack->arr[stack->top]);
        return stack->arr[stack->top];
    }
}

void display(struct Stack *stack){

    int idx = stack->top;
    printf("Elements: \n");
    while (idx >= 0) {
        printf("%d ",stack->arr[idx]);
        idx--;
    }
}

int main() {

    struct Stack *stack = createStack(10);
    push(1, stack);
    push(2, stack);
    push(3, stack);
    push(4, stack);
    push(5, stack);
    push(6, stack);
    push(7, stack);
    push(8, stack);
    push(9, stack);

    pop(stack);
    peek(stack);  

    display(stack);  
    return 0;
}