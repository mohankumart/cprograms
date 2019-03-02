#include<stdio.h>
#include<stdlib.h>
#include"../stacks/queue.h"
#include"directedGraphs.h"


Graph *graph = NULL;

int v = 6;
int degree[6] = {0,0,0,0,0,0};
Queue *queue = NULL;

void topologicalsort(Graph *graph){
	int i;
	for(i=0;i<v;i++){
		Node *t = graph->array[i].head;
		while(t){
			degree[t->data]++;
			t = t->next;
		}
	}
	queue = createQueue(10);
	for(i=0;i<v;i++){
		if(degree[i] == 0){
			enqueue(queue, i);
			degree[i] = -1;
		}
	}
	
	int u;
	while(queue->front != queue->rear){
		u = dequeue(queue);
		printf("%d ", u);
		Node *t = graph->array[u].head;
		while(t){
			degree[t->data]--;
			if(degree[t->data] == 0){
				enqueue(queue, t->data);
			}
			t = t->next;
		}		
	}
}

int main(){
	
	// Graph Creation
	graph = createGraph(v);
	setEdge(5, 2, graph);
	setEdge(5, 0, graph);
	setEdge(4, 0, graph);
	setEdge(4, 1, graph);
	setEdge(2, 3, graph);
	setEdge(3, 1, graph);
	printGraph(graph);
	topologicalsort(graph);
	printf("\n");
	return 0;
}
