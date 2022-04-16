/*
 * Given an undirected graph and an integer n which is the number of
 * nodes in the graph, and an array edges where each edges[i] = [ui, vi]
 * indicaates that there is an undirected edge between ui and vi.
 *
 * A connected trio is a set of tthree nodes where there is an edge
 * between every pair of them.
 *
 * The degree of a connected trio is the number of edges where one 
 * endpoint is in the trio and the other is not.
 *
 * Return the minimum degree of a connected trio in the grap of -1
 * if the graph has no connected trioe.
 */
#include <iostream>
#include <list>
#include <memory>
#include <vector>

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

    void printAdjacencyList() {
        for (int i {}; i < mNumberOfVertices; ++i) {
            std::cout << i << " --> ";
            bool first {true};
            for (const auto &vertice : mAdjacencyList[i]) {
                std::cout << (first ? "" : ", ");
                first = false;
                std::cout << vertice;
            }
            std::cout << "\n";
        }
    }

    int minTrioDegree() {
        int min {mNumberOfVertices};
//        std::cout << "Starting, " << mNumberOfVertices << "\n";
        for (int first {}; first < mNumberOfVertices; ++first) {
//            std::cout << "First: " << first << std::endl;;
            int firstLevel = mAdjacencyList[first].size();
            // must have at least 2 edges connected
            if (firstLevel >= 2) {
                for (const auto &second : mAdjacencyList[first]) {
//                    std::cout << "First: " << first;
//                    std::cout << ", Second: " << second << std::endl;
                    for (const auto &third : mAdjacencyList[second]) {
//                        std::cout << "First: " << first;
//                        std::cout << ", Second: " << second;
//                        std::cout << ", Third: " << third << std::endl;
                        for (const auto &last : mAdjacencyList[third]) {
                            if (last == first) {
                                std::cout << "Trio found: " << first << ", "
                                    << second << ", " << third << "\n";
                                int firstLevel = mAdjacencyList[first].size();
                                int secondLevel = mAdjacencyList[second].size();
                                int thirdLevel = mAdjacencyList[third].size();
                                int total = firstLevel + secondLevel + thirdLevel - 6;
                                min = std::min(total, min);
                            }
                        }
                    }
                }
            }
        }
        return min == mNumberOfVertices ? -1 : min;
    }

private:
    int mNumberOfVertices {};
    std::list<int> *mAdjacencyList;
};

int minTrioDegree(int n, std::vector<std::vector<int>> edges) {
    Graph g(n + 1);
    for (const auto &vertice : edges) {
//        std::cout << "Adding: " << vertice[0] << ", " << vertice[1] << '\n';
        g.addEdge(vertice[0], vertice[1]);
//        g.printAdjacencyList();
    }
    g.printAdjacencyList();
    return g.minTrioDegree();
}

int main() {
    std::cout << minTrioDegree(6, {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}}) <<'\n';
}
