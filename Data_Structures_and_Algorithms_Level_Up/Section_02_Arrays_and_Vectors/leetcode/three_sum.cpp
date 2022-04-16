#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::vector<std::vector<int>> triplets(std::vector<int> &a) {
    std::vector<std::vector<int>> results;
    std::sort(a.begin(), a.end());

    // pick every element and solve pair sum for remaining part
    int n = a.size();
    for (int i {}; i <= n - 3; ++i) {

        // 2 pointer approach
        // point to the next element and the last element
        int start {i + 1};
        int end {n - 1};

        while (start < end) {
            int currentSum = a[i] + a[start] + a[end];
            if (currentSum == 0) {
                bool found {};
                for (auto &e : results) {
                    if (e[0] == a[i] && e[1] == a[start] && e[2] == a[end]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    results.push_back({a[i], a[start], a[end]});
                }
                ++start;
                --end;
            } else if (currentSum > 0) {
                // too high, try moving to left
                --end;
            } else {
                // too low, try moving to the right
                ++start;
            }
        }
    }
    return results;
}

int main() {
//  std::vector<int> a {-1, 0, 1, 2, -1, -4};
//  std::vector<int> a {};
//  std::vector<int> a {0};
    std::vector<int> a {0, 0, 0};
    auto p = triplets(a);

    if (p.empty()) {
        std::cout << "No such pair exists\n";
    } else {
        for (auto e : p) {
            std::cout << "[" << e[0] << ", " << e[1] << ", " << e[2] << "]\n";
        }
    }
}
