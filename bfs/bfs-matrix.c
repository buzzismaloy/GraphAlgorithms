#include <stdio.h>
#include <stdlib.h>

#define N 6

void bfs(int g[N][N], int start) {
	int visited[N] = {0};
	int queue[N], front = 0, rear = 0;
	queue[rear++] = start;
	visited[start] = 1;

	printf("BFS: ");
	while(front < rear) {
		int cur = queue[front++];
		printf("%d ", cur);

		for (int i = 0; i < N; ++i) {
			if (g[cur][i] && !visited[i]) {
				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}
	printf("\n\n");
}

int main() {
    int graph[N][N] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

	bfs(graph, 0);

	return 0;
}
