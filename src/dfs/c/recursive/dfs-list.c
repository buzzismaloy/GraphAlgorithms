#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTEXES 200

typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

typedef struct Graph {
	int numVertexes;
	Node* adjLists[MAX_VERTEXES];
	int visited[MAX_VERTEXES];
} Graph;

Graph* createGraph(int vertexes) {
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->numVertexes = vertexes;

	for (int i = 0; i < vertexes; ++i) {
		g->adjLists[i] = NULL;
		g->visited[i] = 0;
	}

	return g;
}

void freeGraph(Graph* g) {
	for (int i = 0; i < g->numVertexes; ++i) {
		Node* temp = g->adjLists[i];
		while (temp) {
			Node* toFree = temp;
			temp = temp->next;
			free(toFree);
		}
	}
	free(g);
}

void addEdge(Graph* g, int src, int dest) {
	//edge src -> dest
	Node* newNode1 = (Node*)malloc(sizeof(Node));
	newNode1->vertex = dest;
	newNode1->next = g->adjLists[src];
	g->adjLists[src] = newNode1;

	//edge dest -> src
	Node* newNode2 = (Node*)malloc(sizeof(Node));
	newNode2->vertex = src;
	newNode2->next = g->adjLists[dest];
	g->adjLists[dest] = newNode2;
}

void dfsRecursive(Graph* g, int start) {
	g->visited[start] = 1;
	printf("%d ", start);

	Node* temp = g->adjLists[start];
	while (temp) {
		int adjVertex = temp->vertex;
		if (!g->visited[adjVertex]) {
			dfsRecursive(g, adjVertex);
		}
		temp = temp->next;
	}
}

int main() {
    Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

	printf("DFS(List recursive): ");
	dfsRecursive(graph, 0);
	printf("\n\n");
	freeGraph(graph);

	return 0;
}

