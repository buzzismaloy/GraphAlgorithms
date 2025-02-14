#include <iostream>
#include <vector>
#include <queue>

class BFS {
	private:
		int numVertexes;
		bool useAdjList;
		std::vector<std::vector<int>> adjList;
		std::vector<std::vector<int>> adjMatrix;

		void bfsAdjList(int start) {
			std::vector<bool> visited(numVertexes, false);
			std::queue<int> q;
			visited[start] = true;
			q.push(start);

			std::cout << "BFS(adjList): ";
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				std::cout << u << ' ';

				for (const int& v : adjList[u]) {
					if (!visited[v]) {
						visited[v] = true;
						q.push(v);
					}
				}
			}
			std::cout << "\n\n";
		}

		void bfsAdjMatrix(int start) {
			std::vector<bool> visited(numVertexes, false);
			std::queue<int> q;
			visited[start] = true;
			q.push(start);

			std::cout << "BFS(adjMatrix): ";
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				std::cout << u << ' ';

				for (int v = 0; v < numVertexes; ++v) {
					if (adjMatrix[u][v] && !visited[v]) {
						visited[v] = true;
						q.push(v);
					}
				}
			}
			std::cout << "\n\n";
		}
	public:

		BFS(int num, bool typeList) : numVertexes(num), useAdjList(typeList) {
			if (useAdjList) {
				adjList.resize(numVertexes);
			}
			else {
				adjMatrix.assign(numVertexes, std::vector<int>(numVertexes, 0));
			}
		}

		void addEdge(int src, int dest) {
			if (useAdjList) {
				adjList[src].push_back(dest);
				adjList[dest].push_back(src);
			}
			else {
				adjMatrix[src][dest] = 1;
				adjMatrix[dest][src] = 1;
			}
		}

		void bfs(int start) {
			if (useAdjList) {
				bfsAdjList(start);
			}
			else {
				bfsAdjMatrix(start);
			}
		}
};


int main() {
	BFS list(6, true), matrix(6, false);

    list.addEdge(0, 1);
    list.addEdge(0, 2);
    list.addEdge(1, 3);
    list.addEdge(1, 4);
    list.addEdge(2, 4);
    list.addEdge(3, 5);
    list.addEdge(4, 5);

    matrix.addEdge(0, 1);
    matrix.addEdge(0, 2);
    matrix.addEdge(1, 3);
    matrix.addEdge(1, 4);
    matrix.addEdge(2, 4);
    matrix.addEdge(3, 5);
    matrix.addEdge(4, 5);

	list.bfs(0);
	matrix.bfs(0);

	return 0;
}
