/*
 * Adjacency List Representation with Node Class
 */
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

class Node {
    public:
        Node (const std::string& name) : name {name} {
        }

        std::list<std::string> neighbors;
    private:
        std::string name;
};

class Graph {
    public:
        explicit Graph(const std::vector<std::string> &cities) {
            for (const auto &city : cities) {
                map[city] = new Node(city);
            }
        }

        void addEdge(const std::string &x, const std::string &y, bool undirected = false) {
            map[x]->neighbors.push_back(y);
            if (undirected) {
                map[y]->neighbors.push_back(x);
            }
        }

        void printAdjacencyList() {
            for (auto cityPair : map) {
                auto city = cityPair.first;
                Node *node = cityPair.second;
                std::cout << city << " --> ";
                bool first {true};
                for (const auto &neighbor : node->neighbors) {
                    std::cout << (first ? "" : ", ");
                    first = false;
                    std::cout << neighbor;
                }
                std::cout << '\n';
            }
        }

    private:
        std::unordered_map<std::string, Node*> map;
};

int main() {
    std::vector<std::string> cities {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);

    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");

    g.printAdjacencyList();
}
