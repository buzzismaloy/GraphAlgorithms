#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEXES 200

typedef struct Graph {
	int numVertexes;
	int adjMatrix[MAX_VERTEXES][MAX_VERTEXES];
	int visited[MAX_VERTEXES];
} Graph;

Graph* createGraph(int vertexes) {

}

void freeGraph(Graph* g) {

}

void addEdge(Graph* g, int src, int dest) {

}

void dfsRecursive(Graph* g, int start) {

}

int main() {
	Graph* graph = createGraph();


	return 0
}
