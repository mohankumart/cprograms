#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int *a;
	int top;
	int capacity;
}Stack;

int isEmpty(Stack *stack){
	return stack->top == -1;
}

int isFull(Stack *stack){
	return stack->top == stack->capacity-1;
}

void push(Stack *stack, int data){
	if(!isFull(stack))
		stack->a[++stack->top] = data;
}

int pop(Stack *stack){
	if(!isEmpty(stack))
		return stack->a[stack->top--];
	else
		return -1;
}

Stack *createStack(int capacity){
	Stack *stack= (Stack*)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->a = (int *)malloc(stack->capacity * sizeof(int));
	return stack;
}

int main(){
	Stack *stack = createStack(20);	
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	printf("%d popped from stack\n", pop(stack));

	return 0;
}
