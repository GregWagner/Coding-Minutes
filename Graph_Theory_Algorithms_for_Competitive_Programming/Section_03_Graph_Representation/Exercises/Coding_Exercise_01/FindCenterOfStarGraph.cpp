/*
 * There is an undirected star graph consisting of n nodes from 1 to n.
 * A star graph is a graph where there is one center node and exactly
 * n - 1 edges that connect the center node with every other node.
 * You are given a 2D integer array edges where edges[i] = [ui, vi]
 * indicates that there is an edge between the nodes ui and vi. Return
 * the center of the given star graph.
 *
 * Constraints:
 * - 3 <= n <= 10^5
 * - edges.length == n - 1
 * - edges[i].length == 2
 * - 1 <= ui, vi <= n
 * - ui != vi
 * - The given edges represent a valid star graph.
 */

/*
 * After I solved it this way, I looked at other solutions and the fastest
 * way was to get the 2 vertices of the first edge and compare both with 
 * the next one and return what ever matches.....
 */

#include <iostream>
#include <vector>
#include <list>
#include <memory>

/*
 * Using an Adjacency List to represent a graph
 */
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

    int findCenter() {
        for (int i {}; i < mNumberOfVertices; ++i) {
            if (mAdjacencyList[i].size() == mNumberOfVertices - 1) {
                return i;
            }    
        }
        return 0;
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

int findCenter(std::vector<std::vector<int>>edges) {
    Graph g(edges.size() + 1);
    for (const auto &vertice : edges) {
        g.addEdge(vertice[0] - 1, vertice[1] - 1);
    }
    return g.findCenter() + 1;
}

int main() {
    std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    std::cout << std::boolalpha;
    std::cout << (findCenter(edges) == 2) << '\n';
}
