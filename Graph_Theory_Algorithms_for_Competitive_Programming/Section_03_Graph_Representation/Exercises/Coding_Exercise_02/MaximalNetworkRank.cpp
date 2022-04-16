#include <iostream>
#include <list>
#include <memory>
#include <vector>
#include <algorithm>

class Graph {
public:
    explicit Graph(int numberOfVertices) : mNumberOfVertices {numberOfVertices},
        mAdjacencyList{new std::list<int>[mNumberOfVertices]} { 
        }
    void addEdge(int i, int j, bool undirectional = true) {
        mAdjacencyList[i].push_back(j);
        if (undirectional) {
            mAdjacencyList[j].push_back(i);
        }
    }
    int maximalNetworkRank() {
        int max {};
        for (int i {}; i < mNumberOfVertices; ++i) {
            int currentSize = mAdjacencyList[i].size();
            for (int j {}; j < mNumberOfVertices; ++j) {
                if (i != j) {
                    int count = currentSize + mAdjacencyList[j].size();
                    if (isNeighbor(i, j)) {
                        --count;
                    }
                    max = std::max(count, max);
                }
            }
        }
        return max;
    }

private:
    int mNumberOfVertices {};
    std::list<int> *mAdjacencyList;

    bool isNeighbor(int i, int j) {
        for (const auto &vertice : mAdjacencyList[i]) {
            if (vertice == j) {
                return true;
            }        
        }
        return false;
    }
};

int maximalNetworkRank(int n, std::vector<std::vector<int>> roads) {
    Graph g(n);
    for (const auto &vertice : roads) {
        g.addEdge(vertice[0], vertice[1]);
    }
    return g.maximalNetworkRank();
}

int main() {
   std::vector<std::vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};
   std::cout << maximalNetworkRank(4, roads) << '\n';
    std::cout << maximalNetworkRank(8,
            {{0,1}, {1,2}, {2,3}, {2,4}, {5,6}, {5,7}}) << '\n';
}
