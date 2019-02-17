#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *link; 
}Stack;

Stack *stack = NULL;

int pop(){
	int item;
	if(stack == NULL){
		printf("Underflow");
		return -1;
	}else{
		item = stack->data;
		Stack *node = stack;
		stack = stack->link;
		node->link = NULL;
		free(node);
	}
	return item;	
}

void push(int data){
	Stack *node = (Stack *)malloc(sizeof(Stack));
	if(node == NULL)
		printf("Error creating New Node");
	node->data = data;
	if(!stack){
		node->link = stack;
		stack = node;
	}else{
		node->link = NULL;
		stack = node;
	}
}

int main(){
	push(10);
	push(20);
	push(30);	
	printf("The popped element is--->%d\n", pop());	
	return 0;
}
