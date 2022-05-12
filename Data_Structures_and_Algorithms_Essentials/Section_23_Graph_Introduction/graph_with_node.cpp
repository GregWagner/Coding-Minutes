#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

class Node {
    public:
        std::string name;
        std::list<std::string> neighbors;

        Node(std::string& name) : name(name) {
        }
};

class Graph {
    private:
        std::unordered_map<std::string, Node*> m;

    public:
        Graph(std::vector<std::string> cities) {
            for (auto city : cities) {
                m[city] = new Node(city);
            }
        }

        void addEdge(std::string x, std::string y, bool undirected=false) {
            m[x]->neighbors.push_back(y);
            if (undirected) {
            m[y]->neighbors.push_back(x);

            }
        }

        void printAdjancyList() {
            for (auto cittPair : m) {
                auto city = cittPair.first;
                Node* node = cittPair.second;

                std::cout << city << " --> ";
                for (auto neighbor : node->neighbors) {
                    std::cout << neighbor << ' ';
                }
                std::cout << '\n';
            }
        }

};

int main() {
    std::vector<std::string> cities {"Delhi", "London", "Paris", "New York"};

    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");

    g.printAdjancyList();

}
