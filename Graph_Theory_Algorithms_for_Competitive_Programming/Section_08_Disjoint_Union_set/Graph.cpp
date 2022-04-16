/*
 * Cycle detection in an undirected graph using DSU
 */
#include <iostream>
#include <list>

class Graph {
    public:
        explicit Graph(int numberOfVertices) : mNumberOfVertices {numberOfVertices} {
        }

        void addEdge(int u, int v) {
            //mEdgeList.push_back(std::make_pair(u, v));
            mEdgeList.emplace_back(u, v);
        }

        int findSet(int i, int parent[]) {
            if (parent[i] == -1) {
                return i;
            }
            // path compression
            parent[i] = findSet(parent[i], parent);;
            return parent[i];
        }

        void unionSet(int x, int y, int* parent, int* rank) {
            // find the parents
            int set1 = findSet(x, parent);
            int set2 = findSet(y, parent);

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

        bool containsCycle() {
            int* parent = new int[mNumberOfVertices];
            int* rank = new int[mNumberOfVertices];
            for (int i {}; i < mNumberOfVertices; ++i) {
                parent[i] = -1;
                rank[i] = 1;
            }

            // iterate over the edge list
            for (auto edge : mEdgeList) {
                int i = edge.first;
                int j = edge.second;

                int set1 = findSet(i, parent);
                int set2 = findSet(j, parent);

                if (set1 == set2) {
                    delete [] parent;
                    delete [] rank;
                    return true;
                }
                unionSet(set1, set2, parent, rank);
            }
            delete [] parent;
            delete [] rank;
            return false;
        }

    private:
        int mNumberOfVertices {};
        std::list<std::pair<int, int>> mEdgeList;
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
//  g.addEdge(3, 0);

    std::cout << std::boolalpha;
    std::cout << g.containsCycle() << '\n';
}
