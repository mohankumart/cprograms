#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int front;
	int rear;
	int capacity;
	int *a;
}Queue;

Queue *createQueue(int capacity){
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->front = 0;
	queue->rear = 0;
	queue->capacity = capacity;
	queue->a = (int *)malloc(queue->capacity * sizeof(int));
	return queue;
}
 
void enqueue(Queue *queue, int data){
	queue->rear = (queue->rear + 1)%queue->capacity;
	if(queue->rear == queue->front){
		printf("Queue is full\n");
		if(queue->rear == 0){
			queue->rear = queue->capacity - 1;
		}else {
			queue->rear = queue->rear - 1;
		}	
	}else{
		queue->a[queue->rear] = data; 
	}
} 

int dequeue(Queue *queue){
	if(queue->front == queue->rear){
		printf("Queue is empty\n");
		return -1;
	}else{
		queue->front = queue->front + 1;
		return queue->a[queue->front];
	}
}

int main(){
	Queue *queue = createQueue(4);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	enqueue(queue, 50);
	printf("The dequeue element is -------> %d\n", dequeue(queue));
	
	printf("The dequeue element is -------> %d\n", dequeue(queue));
	printf("The dequeue element is -------> %d\n", dequeue(queue));
	printf("The dequeue element is -------> %d\n", dequeue(queue));
	printf("The dequeue element is -------> %d\n", dequeue(queue));
	printf("The dequeue element is -------> %d\n", dequeue(queue));
	return 0;
}
