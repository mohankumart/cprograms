#include<stdio.h>
#include<stdlib.h>

struct AdjListNode {
	int dest;
	struct AdjListNode *next;
};

struct AdjList {
	struct AdjListNode *head;
};

struct Graph {
	int v;
	struct AdjList *array;
};

struct Graph* createGraph(int v){
	struct Graph *graph = (Struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;

	graph->array = (struct AajList*)malloc(v* sizeof(struct AdjList));

	int i;
	for(i=0; i<v; i++){
		graph->array[i].head = NULL;
	}
	return graph;
}

void printGraph(struct Graph* graph){
	int v;
	for(v=0; v< graph->v; ++v){
		struct AdjListNode *pCrawl = graph->array[v].head;
		printf('\n Adjacency list of vertex %d\nhead', c);
		while(pCrawl){
			printf("----> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

struct AdjListNode *newAdjListNode(int dest){
	struct AdjListNode *newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

void addEdge(struct Graph *graph, int src, int dest){
	struct AdjListNode *newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src);
	newNode->next = graph->arry[dest].head;
	graph->array[dest].head = newNode;
}

int main(){
	
	return 0;
}
