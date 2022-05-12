/*
 * LIS - Longest Increasing Subsequennce
 * Given an array sequence, find the length of the longest
 * subsequence of such that all elements of the
 * subsequence are sorted in increasing order.
 * input = {50, 4, 10, 8, 30, 100}
 * answer = 4 - {4, 8, 30, 100}
 *
 * {50, 4, 10, 8, 30, 100}
 * { 1, 1,  2, 2,  3,   4}
 *    (4,10)
 *    (4,8)
 *    (4,8,30)
 *    (4, 9, 30, 100)
 *
 *    dp[i] has the length of the LIS ending at a[i]
 *    dp[i] = 1 + max(dp[j]) for all 0 <= j < i and a[j] < a[i]
 *    LIS = max(dp[i]) for all values of i
 */
#include <iostream>
#include <vector>

// bottom up solution
int lis(const std::vector<int>& a) {
    std::vector<int> dp(a.size(), 1);
    int length {1};
    for (size_t i {1}; i < a.size(); ++i) {
        for (size_t j {}; j < i; ++j) {
            // if we can attach this valus to a previous sequence
            if (a[i] > a[j]) {
                dp[i] = std::max(dp[i], 1 + dp[j]);
                length = std::max(length, dp[i]);
            }
        }
    }
    return length;
}

int main() {
    std::vector<int> a {50, 4, 10, 8, 30, 100};
    std::cout << lis(a) << '\n';
}
