/*
 * There are N stones given in the form of an array. Each element
 * in the array represeents the height of the ith stone. There is a
 * frog who is initially on stone #1. The fro will repeat the 
 * following action until it reachs stone N:
 *  if current on stone i, jump to stone i + 1 or stone i + 2. Here
 *  a cost of |hi - hj| is incurred, where j is the stone it laneded on.
 * Find the mimumun possible total cost incurred before the frog
 * reachs stone n.
 *
 * 10 10 cost = 0
 * 30 10 60 10 60 50 cost = 40
 *      1 -> 3 -> 5 -> 6
 *      |30 - 60| + |60 - 60| + |60 - 50| = 30 + 0 + 10 = 40
 */
#include <iostream>
#include <vector>

// bottom up
int getMinCost(const std::vector<int> &stones) {
    int n = stones.size();
    std::vector<int> dp(n, 0);

    dp[1] = std::abs(stones[1] - stones[0]);
    for (int i {2}; i < n; ++i) {
        int op1 = std::abs(stones[i] - stones[i - 1]) + dp[i - 1];
        int op2 = std::abs(stones[i] - stones[i - 2]) + dp[i - 2];
        dp[i] = std::min(op1, op2);
    }
    return dp[n - 1];
}

int main() {
    std::vector<int> stones {30, 10, 60, 10, 60, 50};
    std::cout << std::boolalpha;
    std::cout << (getMinCost(stones) == 40) << '\n';
}

