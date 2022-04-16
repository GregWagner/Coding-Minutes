/*
 * Using an Adjacency List to represent a graph
 */
#include <iostream>
#include <list>
#include <memory>

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
            std::cout << '\n';
        }
    }

private:
    int mNumberOfVertices {};
    std::list<int> *mAdjacencyList;
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);

    g.printAdjacencyList();
}
