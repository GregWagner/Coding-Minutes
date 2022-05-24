/*
 * Given an array of coin denominations and an integer M
 * representing target money, Find the minimum number of coins
 * required to make change.
 * coins = [1, 3, 7, 10]
 * m = 15
 * output = 3 (7 + 7 + 1)
 */
#include <climits>
#include <iostream>
#include <vector>

// Bottom Up Approach
int minNumberOfCoinsForChange(int n, const std::vector<int>& coins) {
    std::vector<int> dp(n + 1, 0);

    for (int i { 1 }; i <= n; ++i) {
        dp[i] = INT_MAX;

        for (int c : coins) {
            if (i - c >= 0 && dp[i - c] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main() {
    std::vector<int> a { 1, 3, 7, 10 };
    std::cout << minNumberOfCoinsForChange(8, a) << '\n';
    std::cout << minNumberOfCoinsForChange(16, a) << '\n';
}
