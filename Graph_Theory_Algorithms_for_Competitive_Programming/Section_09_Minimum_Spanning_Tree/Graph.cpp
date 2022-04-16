/*
 * NOTE - Kruskal Code is not working
 *
 * Given a connected, undirecctied and weighted graph G, select
 * a subset of edges E such that graph G is connected and the 
 * total weigh of the selected edged in E is a minimmum.
 * Note: It will have V-1 edges
 *  Prim's Algorithm
 *      * Greedy
 *      * Uses priority queue
 *      * Terms
 *          MSG Set = [] // all nodes included in MST
 *                       // will include all nodes when done
 *          Active Edge  // edge from a vertex in MSG set to V
 *          MST Edge     // edge that has been included in MST
 *      * Algorithm
 *          1) Start from any source vertext
 *          2) out of all active edges, pick the one with the smallest weight
 *              - select an Y in MST
 *              - add edges starting from Y in the active edge list
 *  Kruskal's Algorithm
 *      * Greedy
 *      * Stores graph as an edge list
 *      * DSU for detecting cycles
 *      * O(E logV)
 *      * Algorithm
 *          1) Sort all edges bases on weight
 *          2) Pick smallest and check if they belong to the same set 
 *              if not, join them and add it to MST
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class DSU {
    public:
        explicit DSU(int numberOfVertices) : parent {new int[numberOfVertices]},
                 rank {new int[numberOfVertices]} {
            for (int i {}; i < numberOfVertices; ++i) {
                parent[i] = -1;
                rank[i] = 1;
            }
        }

        int findSet(int i) {
            if (parent[i] == -1) {
                return i;
            }
            // path compression
            parent[i] = findSet(i);;
            return parent[i];
        }

        void unionSet(int x, int y) {
            // find the parents
            int set1 = findSet(x);
            int set2 = findSet(y);

            if (set1 != set2) {
                // merge - attach smaller tree to larger tree
                if (rank[set1] < rank[set2]) {
                    parent[set1] = set2;
                    rank[set2] += rank[set1];
                } else {
                    parent[set2] = set1;
                    rank[set1] += rank[set2];
                }
            }
        }

    private:
        int* parent;
        int* rank;
};

class Graph {
    public:
        explicit Graph(int numberOfVertices) : mNumberOfVertices {numberOfVertices} {
        }

        void addEdge(int x, int y, int weight) {
            // set weight as first to make sorting easier
            mEdgeList.push_back({weight, x, y});
        }

        int kruskalMst() {
            std::sort(mEdgeList.begin(), mEdgeList.end());
            DSU s(mNumberOfVertices);

            int answer {};
            for (auto edge : mEdgeList) {
                int weight {edge[0]};
                int x {edge[1]};
                int y {edge[2]};

                // put the edge in MST if it does't form a cycle
                if (s.findSet(x) != s.findSet(y)) {
                    s.unionSet(x, y);
                    answer += weight;
                }
            }
            return answer;
        }

    private:
        int mNumberOfVertices {};
        std::vector<std::vector<int>> mEdgeList;
};

class Graph1 {
    public:
        explicit Graph1(int numberOfVertices) : mNumberOfVertices {numberOfVertices} {
            mAdjacencyList = new std::vector<std::pair<int, int>>[numberOfVertices];
        }

        void addEdge(int x, int y, int w) {
            mAdjacencyList[x].emplace_back(y, w);
            mAdjacencyList[y].emplace_back(x, w);
        }

        int primMst() {
            // minimum heap
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                std::greater<std::pair<int, int>>> queue;

            // visitied array that denotes if a node has been included in MST or not
            bool* visited = new bool[mNumberOfVertices] {};
            int answer {};

            queue.push({0, 0});  // weight, node
            while (!queue.empty()) {
                // pick edge with minimum weight
                auto best = queue.top();
                queue.pop();

                int weight = best.second;
                int to = best.second;

                if (visited[to]) {
                    // discard the edge and countineu
                    continue;
                }

                // otherwise take the current edge
                answer += weight;
                visited[to] = 1;

                // add the new edges in the queue
                for (auto x : mAdjacencyList[to]) {
                    if (visited[x.first] == 0) {
                        queue.push({x.second, x.first});
                    }
                }
            }
            return answer;
        }

    private:
        int mNumberOfVertices {};
        std::vector<std::pair<int, int>>* mAdjacencyList;
};

int main() {
#if 0
    int n, m;
    std::cin >> n >> m;

    Graph1 g(n);
    for (int i {}; i < m; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;
        g.addEdge(x - 1, y - 1, w);
    }
    std::cout << g.primMst() << '\n';
#endif

    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

    std::cout << g.kruskalMst() << '\n';
}
