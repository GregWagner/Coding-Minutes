/*
 * A Hamiltonian path is a path in a direccted or undirected
 * graph that visits each vertex exactly one. The problem to
 * check if a graph contains a Hamiltonian Path is NP-complete,
 * so is the problem of finding all the Hamiltonian Paths
 * in a graph.
 *
 * To backtrack, mark a previously visited node as not
 * visited.
 */
#include <iostream>
#include <vector>

const int N = 1e5;
std::vector<int> graph[N];
int n {}, m {};
int visited[N] {};
bool hamiltonian_path {};

void paths(int current, int count = 1) {
    // base case
    if (count == n) {
        hamiltonian_path = true;
        return;
    }
    visited[current] = 1;

    for (const auto& x : graph[current]) {
        if (!visited[x]) {
            paths(x, count + 1);
        }
    }

    // backtrack
    visited[current] = 0;
}

int main() {

    n = 4;
    m = 4;

    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[1].push_back(3);
    graph[3].push_back(1);

    std::cout << std::boolalpha;
    paths(0);
    std::cout << hamiltonian_path << '\n';
    hamiltonian_path = false;
    paths(1);
    std::cout << hamiltonian_path << '\n';
}
