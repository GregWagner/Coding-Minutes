/*
 *
 * Given an array of positive integers, where each element
 * represents the max number of steps you can jump forward
 * in the array. Find the minimum jumps needed to reacch the 
 * final index.
 *
 * a = [3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5]
 * answer 4 (3 -> 4 -> 2 -> 7 -> 5)
 */
#include <iostream>
#include <climits>
#include <vector>

int minJumps(const std::vector<int> &a, int n, std::vector<int> &dp, int i=0) {
    if (i == n - 1) {
        return 0;
    }
    if (i >= n) {
        return INT_MAX;
    }
    if (dp[i] != 0) {
        return dp[i];
    }

    int steps {INT_MAX};
    int maxJump {a[i]};

    for (int jump {1}; jump <= maxJump; ++jump) {
        int nextIndex {i + jump};
        int subProblem = minJumps(a, n, dp, nextIndex);
        if (subProblem != INT_MAX) {
            steps = std::min(steps, subProblem + 1);
        }
    }
    return dp[i] = steps;
}

int main() {
    std::vector<int> a {3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    std::vector<int> dp(a.size(), 0);
    std::cout << minJumps(a, a.size(), dp) << '\n';
}
