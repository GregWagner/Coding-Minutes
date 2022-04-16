#include <iostream>
#include <list>
#include <memory>
#include <queue>
#include <vector>

class Graph {
    public:
        explicit Graph(int numberOfVertices)
            : mNumberOfVertices{numberOfVertices},
              mAdjacencyList{new std::list<int>[mNumberOfVertices]} { 
        }

        void addEdge(int i, int j, bool undirectional = false) {
            mAdjacencyList[i].push_back(j);
            if (undirectional) {
                mAdjacencyList[j].push_back(i);
            }
        }

        void bfs_topologicaLSort() {
            std::vector<int> inDegree(mNumberOfVertices, 0);

            // Find the in-degree for every edge
            for (int i {}; i < mNumberOfVertices; ++i) {
                for (auto neighbor : mAdjacencyList[i]) {
                    ++inDegree[neighbor];
                }
            }

            // bfs logic
            std::queue<int> q;
            // populate q with nodes having 0 in-degree
            for (int i {}; i < mNumberOfVertices; ++i) {
                if (inDegree[i] == 0) {
                    // if nothing is dependent on this, put on queue
                    q.push(i);
                }
            }

            // start popping
            while (!q.empty()) {
                int node = q.front();
                std::cout << node << ' ';
                q.pop();

                // go through neighbors of this node and reducc in-degree by 1.
                for (auto neighbor : mAdjacencyList[node]) {
                    --inDegree[neighbor];
                    if (inDegree[neighbor] == 0) {
                        // if nothing is dependent on this, put on queue
                        q.push(neighbor);
                    }
                }
            }
            std::cout << '\n';
        }

        void dfs(int node, std::vector<bool> &visited, std::list<int> &ordering) {
            visited[node] = true;

            for (int neighbor : mAdjacencyList[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, visited, ordering);
                }
            }
            // at this point we are back tracking
            ordering.push_front(node);
        }

        void dfs_topologicaLSort() {
            std::vector<bool> visited(mNumberOfVertices, false);
            std::list<int> ordering;

            // call dfs for every node that has not been visited
            for (int i {}; i < mNumberOfVertices; ++i) {
                if (!visited[i]) {
                    dfs(i, visited, ordering);
                }
            }

            // print the ordering
            for (auto node : ordering) {
                std::cout << node << ' ';
            }
            std::cout << '\n';
        }

    private:
        int mNumberOfVertices {};
        std::list<int> *mAdjacencyList;

        void dfsHelper(int node, bool* visited) {
            visited[node] = true;
            std::cout << node << ' ';

            // make a recursive call on all its unvisted neighbors
            for (auto neighbor : mAdjacencyList[node]) {
                if (!visited[neighbor]) {
                    dfsHelper(neighbor, visited); 
                }
            }
        }
};

int main() {
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1, 4);
    g.addEdge(1, 2);

    g.dfs_topologicaLSort();
}
