/*
 * Given an array of positive integers, find the maximum sum of
 * non adjacent elements in the array.
 */
#include <iostream>
#include <vector>

int maxNonAdjacentSum(const std::vector<int> & a) {
    if (a.size() == 1) {
        return std::max(a[0], 0);
    }
    if (a.size() == 2) {
        return std::max(a[0], a[1]);
    }

    // bottom up logic
    std::vector<int> dp(a.size() + 1);
    dp[0] = a[0];
    dp[1] = std::max(dp[0], a[1]);

    for (size_t i {2}; i < a.size(); ++i) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + a[i]);
    }
    return dp[a.size() - 1];
}

int main() {
    std::vector<int> a {6, 10, 12, 7, 9, 14};
    std::cout << std::boolalpha;
    std::cout << (maxNonAdjacentSum(a) == 32) << '\n';
}
