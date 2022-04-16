/*
 * Rod Cutting Problem
 * -------------------
 *  N = 8
 *
 * Example #1
 * length  | 1  2  3  4  5  6  7  8
 * ----------------------------------
 *  price  | 1  5  8  9 10 17 17 20
 *
 *  8 pieces of length 1 @1 dollar each = 8 dollars
 *  1 piece of length 8 @20 dollars = 20 dollars
 *  1 piece of length 6 + 1 piece of length 2 = 17 + 5 = 22
 *  Max Profit = 22
 *
 * Example #2
 * length  | 1  2  3  4  5  6  7  8
 * ----------------------------------
 *  price  | 3  5  8  9 10 17 17 20
 *  Max Profit = 24
 *
 */
#include <iostream>
#include <vector>
#include <climits>

// recursive solution
int maxProfit(const std::vector<int> &prices, int n) {
    if (n <= 0) {
        return 0;
    }

    int answer {INT_MIN};
    for (int length {}; length < n; ++length) {
        int cut {length + 1};

        int currentAnswer {prices[length] + maxProfit(prices, n - cut)};
        answer = std::max(answer, currentAnswer);
    }
    return answer;
}

// bottom up solution
int maxProfit_DP(const std::vector<int> &prices, int n) {
    std::vector<int> dp(n + 1, 0);

    for (int length {1}; length <= n; ++length) {
        int answer {INT_MIN};
        for (int i {}; i < length; ++i) {
            int cut {i + 1};
            int currentAnswer {prices[i] + dp[length - cut]};
            answer = std::max(answer, currentAnswer);
        }
        dp[length] = answer;
    }
    return dp[n];
}

int main() {
    std::vector<int> prices {1, 5, 8, 9, 10, 17, 17, 20};
    std::cout << maxProfit(prices, prices.size()) << '\n';
    std::cout << maxProfit_DP(prices, prices.size()) << '\n';
}
