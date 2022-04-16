#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#include <set>

class Graph {
    public:
        explicit Graph(int numberOfVertices) : mNumberOfVertices {numberOfVertices} {
            mAdjacencyList = new std::list<std::pair<int, int>> [numberOfVertices];
        }

        void addEdge(int u, int v, int weight, bool undirected = true) {
            mAdjacencyList[u].push_back({weight, v});
            if (undirected) {
                mAdjacencyList[v].push_back({weight, u});
            }
        }

        int dijkstra(int src, int dest) {
            std::vector<int> distance(mNumberOfVertices, INT_MAX);
            std::set<std::pair<int, int>> s;

            distance[src] = 0;
            s.insert({0, src});

            while (!s.empty()) {
                auto it {s.begin()};
                int node {it->second};
                int distanceTillNow {it->first};
                s.erase(it);        // pop

                // iterate over the neighbors of the node
                for (auto neighborPair : mAdjacencyList[node]) {
                    int neighbor {neighborPair.second};
                    int lengthOfCurrentEdge {neighborPair.first};

                    if (distanceTillNow + lengthOfCurrentEdge < distance[neighbor]) {
                        // remove if neighbor already exists in set
                        auto f = s.find({distance[neighbor], neighbor});
                        if (f != s.end()) {
                            s.erase(f);
                        }
                        // insert the updated value with the new distance
                        distance[neighbor] = distanceTillNow + lengthOfCurrentEdge;
                        s.insert({distance[neighbor], neighbor});
                    }
                }
            }
            for (int i {}; i < mNumberOfVertices; ++i) {
                std::cout << "Node: " << i << ", Dist: " << distance[i] <<'\n';
            }
            return distance[dest];
        }

    private:
        int mNumberOfVertices {};
        std::list<std::pair<int, int>>* mAdjacencyList;
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    std::cout << g.dijkstra(0, 4) << '\n';
}
