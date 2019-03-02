#include<stdio.h>
#include<stdlib.h>
#include"../stacks/queue.h"
#include"graphs.h"

Graph *graph = NULL;
Queue *queue = NULL;
  
int v = 8;
int visited[5];

void bfs(int V){
	int i=0, u;
	for(i=0;i<v;i++){
		visited[i] = 0;
	}	

	u = V;
	visited[u] = 1;
	queue = createQueue(10);
	enqueue(queue, u); 	

	printf("\n");
	Node *t;
	while(queue->front != queue->rear){
		u = dequeue(queue);
		t = graph->array[u].head;
		while(t){
			if(visited[t->data] == 0){
				enqueue(queue, t->data);
				visited[t->data] = 1;
			}
			t= t->next;
		}
		printf("%d ", u);
	}

	printf("\n");	
}

int main(){
	// Graph Creation
	graph = createGraph(v);
	setEdge(0,1, graph);
	setEdge(0,2, graph);
	setEdge(1,3, graph);
	setEdge(1,4, graph);
	setEdge(2,5, graph);
	setEdge(2,6, graph);
	setEdge(3,7, graph);
	setEdge(4,7, graph);
	setEdge(5,7, graph);
	setEdge(6,7, graph);
	printGraph(graph);
	
	//BFS
	bfs(0);	
	return 0;
}
