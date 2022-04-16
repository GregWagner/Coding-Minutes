#include <iostream>
#include <vector>

bool dfs_helper(std::vector<int> graph[], int node, int *visited, int parent, int color) {
    visited[node] = color;  // 1 or 2 both mean visited

    for (auto neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            int subProblem = dfs_helper(graph, neighbor, visited, node, 3 - color);
            if (!subProblem) {
                return false;
            }
        } else if (neighbor != parent && color == visited[neighbor]) {
            return false;
        }
    }
    return true;
}

bool dfs(std::vector<int> graph[], int n) {
    // 0 - not visited, 1  - visited Color is 1, 2 - visited Color is 2
    int visited[n] = {0};
    int color {1};
    int answer = dfs_helper(graph, 0, visited, -1, color);

    // print colors
    for (int i {}; i < n; ++i) {
        std::cout << i << " - Color " << visited[i] << '\n';
    }
    return answer;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> graph[N];

    while (M--) {
        int x, y;
        std::cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // bfs or dfs by coloring the nodes at each step
    // (current node has color 1, neighbors should have
    // color 2)
    std::cout << (dfs(graph, N) ? "Yes, its bipartite" : "No, not bipartite") << '\n';
}
