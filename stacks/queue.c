#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

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
