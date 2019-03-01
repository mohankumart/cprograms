#include<stdio.h>
#include<stdlib.h>

typedef struct adjNode {
	struct node *head;
}AdjNode;

typedef struct node {
int data;
	struct node *next;
}Node;

typedef struct graph {
	int v;
	struct adjNode *array;
}Graph;

void setEdge(int from, int to, Graph *graph){
	// add the node at begining of the list
	
	// construct the new node
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = to;
	newNode->next = NULL;
	
	// add the new node to adjList
	if(graph->array[from].head)
		newNode->next = graph->array[from].head;
	graph->array[from].head = newNode;
  	
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = from;
	newNode->next = NULL;

	// add the new node to adjList
	if(graph->array[to].head)
		newNode->next = graph->array[to].head;
	graph->array[to].head = newNode;
}

void printGraph(Graph *graph){
	int v;
	for(v=0;v<graph->v;v++){
		Node *t1 = graph->array[v].head;
		//printf("Adjacency List of %d\n", t1->data);
		printf("Head");
		while(t1){
			printf("----->%d", t1->data);
			t1 = t1->next;
		}
		printf("\n");
	}
}

Graph* createGraph(int v){
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->v = v;
	graph->array = (AdjNode *)malloc(v * sizeof(AdjNode));
	return graph;
}

int main(){
	int v;
	
	// Scan the number of vertices
	printf("Enter the Number of vertices: ");
	scanf("%d", &v);

	// initialize graph
	Graph *graph = createGraph(v);

	// construct the graph based on input
	setEdge(0,1, graph);
	setEdge(0,4, graph);
	setEdge(1,2, graph);
	setEdge(1,3, graph);
	setEdge(1,4, graph);
	setEdge(2,3, graph);
	setEdge(3,4, graph);

	// print graph
	printGraph(graph);
	
	return 0;
}
