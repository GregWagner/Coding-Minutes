#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>

class Graph {

    // Adjacency List Representations
private:
    int vertex;
    std::list<int>* l;

public:
    Graph(int v)
        : vertex { v } {
        l = new std::list<int>[v];
    }

    void addEdge(int i, int j, bool undirected = true) {
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

    void bfs(int source) {
        std::queue<int> q;
        bool* visited = new bool[vertex] {};
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int f = q.front();
            std::cout << f << '\n';
            q.pop();

            // push the neighbors of current node if
            // they have not already been visited
            for (auto neighbor : l[f]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void dfsHelper(int node, bool* visited) {
        visited[node] = true;
        std::cout << node << ' ';

        // make a dfs call of all univisted neighbors
        for (int neighbor : l[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int source) {
        bool* isVisited = new bool[vertex] {};
        dfsHelper(source, isVisited);
        std::cout << '\n';
    }

    // noot sure if this is working
    void topological_sort() {
        // calcullaate in-degree for all nodes
        std::vector<int> inDegree(vertex, 0);

        // iterate over all the edges to find the right index
        for (int i {}; i < vertex; ++i) {
            for (auto neighbor : l[i]) {
                ++inDegree[neighbor];
            }
        }

        // bfs
        std::queue<int> q;
        // initializee thhe queue with odes having an inDegree of 0
        for (int i {}; i < vertex; ++i) {
            std::cout << i << ": inDegree: " << inDegree[i] << '\n';
            if (inDegree[i] == 0) {
                std::cout << "Node " << i << " has inDegree of 0\n";
                q.push(i);
            }
        }

        // starting poping
        while (!q.empty()) {
            int node = q.front();
            std::cout << node << ' ';
            q.pop();

            // iteraate over the neighbors of this node
            // and reduce the inDegree by 1
            for (auto neighbor : l[node]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    std::cout << "Node " << neighbor << " has indegree of 0\n";
                    q.push(neighbor);
                }
            }
        }
        std::cout << '\n';
    }

    int dijkstra(int src, int dest) {
        std::vector<int> dist(vertex, INT_MAX);
        std::set<std::pair<int, int>> s;

        // initialize
        dist[src] = 0;
        s.insert({ 0, src });

        while (!s.empty()) {
            auto it = s.begin();
            int currentDistance = it->first;
            int node = it->second;
            s.erase(it); // remove from the set

            // iterate over the neighbors of the node
            for (auto neighborPair : l[node]) {
                int currentEdge = neighborPair.first;
                int neighbor = neighborPair.second;

                if (currentDistance + currentEdge < dist[neighbor]) {
                    // remove if neighbot already exits in set
                    auto f = s.find({ dist[neighbor], neighbor });
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    dist[neighbor] = currentDistance + currentEdge;
                    s.insert(std::make_pair(dist[neighbor], neighbor));
                }
            }
        }
        // print out single source shortest distance to all nodes
        for (int i {}; i < vertex; ++i) {
            std::cout << "Node " << i << ", Distance: " << dist[i] << '\n';
        }
        return dist[dest];
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    // g.printAdjancyList();
    g.bfs(1);
    std::cout << "-------------------------\n";
    g.dfs(1);
    std::cout << "-------------------------\n";
    g.topological_sort();
}
