/*
 * Insert edges in graph than
 * Use BFS shortest path
 */
#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {

    // Adjacency List Representations
    private:
        int vertex {};
        std::list<int>* l {};
    public:
        Graph(int v) : vertex {v} {
            l = new std::list<int>[v];
        }

        void addEdge(int i, int j, bool undirected=true) {
            l[i].push_back(j);
            if (undirected) {
                l[j].push_back(i);
            }
        }

        void printAdjancyList() {
            for (int i {}; i < vertex; ++i) {
                std::cout << i << " --> ";
                for (auto node : l[i]) {
                    std::cout << node << ' ';
                }
                std::cout << '\n';
            }
        }

        // shortest path using BFS (single source shortest path)
        int shorestPath(int source, int destination=-1) {
            std::queue<int> q;
            bool *visited = new bool[vertex] {};
            int* distance = new int[vertex] {};
            int* parent = new int[vertex] {};
            for (int i {}; i < vertex; ++i) {
                parent[i] = -1;
            }

            q.push(source);
            visited[source] = true;
            parent[source] = source;
            distance[source] = 0;

            while (!q.empty()) {
                int f = q.front();
                std::cout << f << '\n';
                q.pop();

                // push the neighbors of current node if
                // they have not already been visited
                for (auto neighbor : l[f]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        parent[neighbor] = f;
                        distance[neighbor] = 1 + distance[f];
                        visited[neighbor] = true;
                    }
                }
            }
            return distance[destination];
        }
};

int min_dice_throws(int n,
        const std::vector<std::pair<int, int>> &snakes,
        const std::vector<std::pair<int, int>> &ladders) {
    std::vector<int> board(n + 1, 0);

    // board to grapph conversion
    for (auto sp : snakes) {
        int start {sp.first};
        int end {sp.second};
        board[start] = end - start;
    }

    for (auto lp : ladders) {
        int start {lp.first};
        int end {lp.second};
        board[start] = end - start;
    }

    Graph g(n + 1);
    for (int u {1}; u < n; ++u) {
        for (int dice {1}; dice <= 6; ++dice) {
            int v {u + dice};
            v += board[v]; // add in any snake or ladder
            if (v <= n) {
                g.addEdge(u, v);
            }
        }
    }
    return g.shorestPath(1, n);
}

int main() {

}
