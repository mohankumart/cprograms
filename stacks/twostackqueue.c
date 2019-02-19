#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int capacity;
	int top;
	int *a;
}Stack;

Stack *s1, *s2;

int isEmpty(Stack *s){
	return s->top == -1;
}

int isFull(Stack *s){
	return s->capacity-1 == s->top;
}

void push(Stack *s, int data){
	if(!isFull(s)){
		s->a[++s->top] = data;		
	}
}

int pop(Stack *s){
	if(!isEmpty(s)){
		return s->a[s->top--];
	}
	return -1;
}

int dequeue(){
	if(isEmpty(s2)){
		if(isEmpty(s1)){
			printf("Queue is Empty");
			return -1;	
		}else{
			while(!isEmpty(s1)){
				push(s2, pop(s1));
			}
			return pop(s2);
		}
	}
	return pop(s2);
}

void createStack(int capacity){
	s1 = (Stack *)malloc(sizeof(Stack));
	s1->top = -1;
	s1->capacity = capacity;
	s1->a = (int *)malloc(s1->capacity * sizeof(int));

	s2 = (Stack *)malloc(sizeof(Stack));
	s2->top = -1;
	s2->capacity = capacity;
	s2->a = (int *)malloc(s2->capacity * sizeof(int));
}

int main(){
	createStack(10);
	push(s1, 10);
	push(s1, 20);
	push(s1, 30);	
	printf("The dequeue element is -----> %d\n", dequeue());
	printf("The dequeue element is -----> %d\n", dequeue());
	return 0;
}
