/*
 * Maximall Network Rank
 * Leetcode 1615
 */
#include <iostream>
#include <vector>
#include <list>

class Solution {
public:
    int maximalNetworkRank(int n, std::vector<std::vector<int>>& roads) {
        auto *adjacencyList{new std::list<int>[n]};
        for (auto &road : roads) {
            adjacencyList[road[0]].push_back(road[1]);
            adjacencyList[road[1]].push_back(road[0]);
        }

        int firstIndex {};
        size_t first = adjacencyList[firstIndex].size();
        int secondIndex {1};
        size_t second = adjacencyList[secondIndex].size();

        if (first < second) {
            std::swap(first, second);
            std::swap(firstIndex, secondIndex);
        }

        for (int i {2}; i < n; ++i) {
            if (first < adjacencyList[i].size()) {
                secondIndex = firstIndex;
                second = first;
                firstIndex = i;
                first = adjacencyList[i].size();
            } else if (second < adjacencyList[i].size()) {
                secondIndex = i;
                second = adjacencyList[i].size();
            }
        }
#if DEBUG
        for (int i {}; i < n; ++i) {
            std::cout << "Index: " << i << '\n';
            for (const auto &j : adjacencyList[i]) {
                std::cout << j << " ";
            }
            std::cout << '\n';
        }
#endif
        // check if there was a road between first and second
        for (const auto &road : adjacencyList[firstIndex]) {
            if (road == second) {
//              std::cout << "Road Between\n";
                --second;
                break;
            }
        }
//      std::cout << first << " + " << second << '\n';
//      std::cout << firstIndex << ", " << secondIndex << '\n';
        return first + second; 
    }
};

int main() {
    Solution s;
    std::cout << std::boolalpha;
    std::vector<std::vector<int>> v {{{0, 1},{0, 3},{1, 2}, {1, 3}}};
    std::cout << (s.maximalNetworkRank(4, v) == 4) << '\n';
    std::cout << "-----------------------------\n";

    std::vector<std::vector<int>> v1 {{{0, 1},{0, 3},{1, 2}, {1, 3}, {2, 3}, {2, 4}}};
    std::cout << (s.maximalNetworkRank(5, v1) == 5) << '\n';
    std::cout << "-----------------------------\n";

    std::vector<std::vector<int>> v3 {{{0, 1},{1, 2},{2, 3}, {2, 4}, {5, 6}, {5, 7}}};
    std::cout << (s.maximalNetworkRank(8, v3) == 5) << '\n';
    std::cout << "-----------------------------\n";

    std::vector<std::vector<int>> v4 {{{0, 2},{0, 1}}};
    std::cout << (s.maximalNetworkRank(3, v4) == 2) << '\n';
    std::cout << "-----------------------------\n";

    std::vector<std::vector<int>> v5 {{{2, 3},{0, 3}, {0, 4}, {4, 1}}};
    std::cout << (s.maximalNetworkRank(5, v5) == 4) << '\n';       
    std::cout << "-----------------------------\n";
}
