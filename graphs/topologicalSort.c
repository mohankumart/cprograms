#include<stdio.h>
#include<stdlib.h>
#include"directedGraphs.h"

Graph *graph = NULL;
int v = 7;
int visited[7];

int main(){
	
	// Graph Creation
	graph = createGraph(v);
	setEdge(1,0, graph);
	setEdge(4,0, graph);
	setEdge(0,2, graph);
	setEdge(0,6, graph);
	setEdge(2,5, graph);
	setEdge(6,5, graph);
	setEdge(6,2, graph);
	printGraph(graph);
	return 0;
}
