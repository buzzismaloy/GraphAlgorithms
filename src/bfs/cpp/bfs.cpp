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
					if (visited[v]) {
						visisted[v] = true;
						q.push(v);
					}
				}
			}
			std::cout << "\n\n";
		}

		void bfsAdjMatrix() {

		}
	public:

		BFS(int num, bool typeList) : numVertexes(num), useAdjList(typeList) {
			if (usedAdjList) {
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

	return 0;
}
