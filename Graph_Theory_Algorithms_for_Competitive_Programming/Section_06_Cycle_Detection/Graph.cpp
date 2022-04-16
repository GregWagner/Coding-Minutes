#include <iostream>
#include <list>
#include <memory>
#include <queue>

class Graph {
    public:
        explicit Graph(int numberOfVertices)
            : mNumberOfVertices{numberOfVertices},
              mAdjacencyList{new std::list<int>[mNumberOfVertices]} { 
        }

        void addEdge(int i, int j, bool undirectional = true) {
            mAdjacencyList[i].push_back(j);
            if (undirectional) {
                mAdjacencyList[j].push_back(i);
            }
        }

        // Cycle Detection in Undirected Graph
        bool dfs(int node, std::vector<bool> &visited, int parent) {
            visited[node] = true;

            for (auto neighbor : mAdjacencyList[node]) {
                if (!visited[neighbor]) {
                    bool foundCycle = dfs(neighbor, visited, node);
                    if (foundCycle) {
                        return true;
                    }
                } else if (neighbor != parent) {
                    // neighbor is vvisited and its not the parent of
                    // current node in the current dfs call
                    return true;
                }
            }
            return false;
        }

        bool containsCycle() {
            // Graph must be a single component
            std::vector<bool> visited(mNumberOfVertices, false);
            return dfs(0, visited, -1);
        }

        // Cycle Detection in Directed Graph
        bool dfs(int node, std::vector<bool> &visited,
                std::vector<bool> &stack ) {
            visited[node] = true;
            stack[node] = true;

            for (int neighbor : mAdjacencyList[node]) {
                if (stack[neighbor] == true) {
                    return true;
                }
                if (!visited[neighbor]) {
                    bool foundCycle = dfs(neighbor, visited, stack);
                    if (foundCycle) {
                        return true;
                    }
                }
            }

            // going back
            stack[node] = false;
            return false;
        }

        bool contains_cycle() {
            std::vector<bool> visited(mNumberOfVertices, false);
            std::vector<bool> stack(mNumberOfVertices, false);

            for (int i {}; i < mNumberOfVertices; ++i) {
                int source {i};
                if (!visited[i]) {
                    if (dfs(i, visited, stack)) {
                        return true;
                    }
                }
            }
            return false;
        }

    private:
        int mNumberOfVertices {};
        std::list<int> *mAdjacencyList;

};

int main() {
    Graph g(3);
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 0, false);

    std::cout << std::boolalpha;
    std::cout << g.containsCycle() << '\n';
}
