/*
 * Given an array of coin denominations and an integer
 * M representing target money. Find the minimum
 * number of coins required to make the change.
 * [1, 3, 7, 10] M = 15
 * Answer 3 (7 + 7 + 1)
 */
#include <iostream>
#include <vector>
#include <climits>

// bottom up approach
int minNumberOfCoinsForChange(const std::vector<int> &coins, int target) {
    std::vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;
    for (int i {1}; i <= target; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[target] == INT_MAX ? -1 : dp[target];
}

int main() {
    std::vector<int> coins {1, 5, 7, 10};
    std::cout << minNumberOfCoinsForChange(coins, 8) << '\n';
}
