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

        void printAdjacencyList() {
            for (int i {}; i < mNumberOfVertices; ++i) {
                std::cout << i << " --> ";
                bool first {true};
                for (const auto &vertice : mAdjacencyList[i]) {
                    std::cout << (first ? "" : ", ");
                    first = false;
                    std::cout << vertice;
                }
                std::cout << '\n';
            }
        }

        void bfs(int source) {
            std::queue<int> q;
            bool *visited = new bool[mNumberOfVertices] {};

            q.push(source);
            visited[source] = true;

            while (!q.empty()) {
                int vertice = q.front();
                std::cout << vertice << '\n';
                q.pop();

                // put all the neighbors on the queue
                for (const auto &neighbor : mAdjacencyList[vertice]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }

        void dfs(int source) {
            bool *visited = new bool[mNumberOfVertices] {};
            dfsHelper(source, visited);
            std::cout << '\n';
        }

        void bfsShortestPath(int source, int destination = -1) {
            std::queue<int> q;
            bool *visited = new bool[mNumberOfVertices] {};
            int *distance = new int[mNumberOfVertices] {};
            int *parent = new int[mNumberOfVertices] {-1};

            q.push(source);
            visited[source] = true;
            parent[source] = source;
            distance[source] = 0;

            while (!q.empty()) {
                int vertice = q.front();
                std::cout << vertice << '\n';
                q.pop();

                // put all the neighbors on the queue
                for (const auto &neighbor : mAdjacencyList[vertice]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        parent[neighbor] = vertice;
                        distance[neighbor] = distance[vertice] + 1;
                        visited[neighbor] = true;
                    }
                }
            }
            // print the shortest distancce 
            for (int i {}; i < mNumberOfVertices; ++i) {
                std::cout << "Shortest distance to " << i << " from " << source
                    << " is " << distance[i] << '\n';
            }

            // print the path from source to any destination
            if (destination != -1) {
                int temp {destination};
                while (temp != source) {
                    std::cout << temp << " -- ";
                    temp = parent[temp];
                }
                std::cout << source << '\n';
            }

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
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);

    //g.bfsShortestPath(1, 6);
    g.dfs(1);
}
