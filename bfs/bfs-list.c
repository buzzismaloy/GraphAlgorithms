#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEXES 200
//#define MAX_QUEUE_SIZE 200

typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

typedef struct Graph {
	int numVertexes;
	Node* adjLists[MAX_VERTEXES];
} Graph;

typedef struct Queue {
	int items[MAX_VERTEXES];
	int front, rear;
} Queue;

Graph* createGraph(int vertexes) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->numVertexes = vertexes;

	for (int i = 0; i < vertexes; ++i) {
		graph->adjLists[i] = NULL;
	}

	return graph;
}

void freeGraph(Graph* graph) {
	for (int i = 0; i < graph->numVertexes; ++i) {
		Node* temp = graph->adjLists[i];
		while(temp) {
			Node* tmp = temp;
			temp = temp->next;
			free(tmp);
		}
	}

	free(graph);
}

void addEdge(Graph* graph, int src, int dest) {
	//forward edge for undirected graph
	//node src -> dest
	Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->vertex = dest;
    newNode1->next = NULL;

    if (!graph->adjLists[src]) {
        graph->adjLists[src] = newNode1;
    } else {
        Node* temp = graph->adjLists[src];
        while (temp->next) temp = temp->next;
        temp->next = newNode1;
    }

	//reverse edge for undirected graph
	//node dest -> src
    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->vertex = src;
    newNode2->next = NULL;

    if (!graph->adjLists[dest]) {
        graph->adjLists[dest] = newNode2;
    } else {
        Node* temp = graph->adjLists[dest];
        while (temp->next) temp = temp->next;
        temp->next = newNode2;
    }
}

Queue* createQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = -1;
	queue->rear = -1;

	return queue;
}

int isQueueEmpty(Queue* q) {
	return q->front == -1;
}

void enqueue(Queue* q, int val) {
	if (q->rear == MAX_VERTEXES - 1) {
		fprintf(stderr, "\nThe Queue is full!\n\n");
		return;
	}

	if (q->front == -1) q->front = 0;
	q->rear++;
	q->items[q->rear] = val;
}

int dequeue(Queue* q) {
	if (isQueueEmpty(q)) {
		fprintf(stderr, "\nThe Queue is empty!\n\n");
		return -1;
	}

	int item = q->items[q->front];
	q->front++;

	if (q->front > q->rear) {
		q->front = q->rear = -1;
	}

	return item;
}

void bfs(Graph* g, int start) {
	int visited[MAX_VERTEXES] = {0}; // array for visited peaks, 0 for not unvisited
	Queue* q = createQueue();
	visited[start] = 1;
	enqueue(q, start);

	printf("BFS: ");

	while(!isQueueEmpty(q)) {
		int cur = dequeue(q);
		printf("%d ", cur);

		// going through all neighbors of this vertex
		Node* tmp = g->adjLists[cur];
		while (tmp) {
			int adjVertex = tmp->vertex;
			if (!visited[adjVertex]) {
				visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			tmp = tmp->next;
		}
	}

	free(q);
	printf("\n\n");
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

	bfs(graph, 0);
	freeGraph(graph);

	return 0;
}
