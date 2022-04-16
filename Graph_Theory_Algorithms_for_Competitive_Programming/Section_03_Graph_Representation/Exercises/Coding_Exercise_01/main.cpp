/*
 * Leetcode problem 1791
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        int a {edges[0][0]};
        int c {edges[1][0]};
        int d {edges[1][1]};
        if (a == c || a == d) {
            return a;
        } 
        return edges[0][1];
    }
};

int main() {
    std::vector<std::vector<int>> v {{{1, 2},{2, 3},{4, 2}}};

    Solution s;
    std::cout << s.findCenter(v) << '\n';
}
