#include<iostream>
#include <climits>
#include<vector>

std::vector<int> bellman_ford(int V, int src,
        const std::vector<std::vector<int>>& edges) {

    std::vector<int> distance(V + 1, INT_MAX);
    distance[src] = 0;

    // relax all edges v-1 times
    for (int i {}; i < V - 1; ++i){
        for (auto edge : edges){
            int u {edge[0]};
            int v {edge[1]};
            int weight {edge[2]};

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // negative weight cycle 
    for (auto edge : edges){
        int u {edge[0]};
        int v {edge[1]};
        int weight {edge[2]};
        if(distance[u] != INT_MAX && distance[u] + weight < distance[v]){
            std::cout << "Negative weight cycle found\n";
            exit(0);
        }
    }
    return distance;
}

int main() {
    int n, m;
    std::cin>>n>>m;

    //edge list 
    std::vector<std::vector<int>> edges;       // (a,b,3) (c,d,5) ....

    for (int i {}; i < m; ++i) {
        int u,v,weight;
        std::cin >>u >> v >> weight;
        edges.push_back({u,v,weight});
    }

    std::vector<int> distances = bellman_ford(n, 1, edges);

    for (int i {1}; i <= n; ++i) {
        std::cout << "Node " << i << " is at distance " <<distances[i]<<'\n';
    }
}
