/*
 * Given weights and prices of n items, we need to put a 
 * subset of items in a bag of capacity W such that we get
 * the maximum total value in the bag (also known as a knapsack)
 *
 * input
 *  n = 4
 *  W = 11
 *  wts = 2, 7, 3, 4
 *  prices = 5, 20, 20, 10
 * output
 *  40 use 2nd and 3rd items (total weight = 10)
 * 
 *
 * If you have n items, there are 2^n ways to form subsets
 * f(n, w) -> max profit = max(include item, exclude item)
 * Either include an item or now
 * If including last item     price[n - 1] + f(n-1, W - wts[n-1])
 * If excluding last item     0 + f(n-1, W)
 */
#include <iostream>
#include <vector>

// Recursive Code -> Top Down
int knapsack(int weights[], int prices[], int N, int W) {
    if (N == 0 || W == 0) {
        return 0;
    }

    int include {};
    if (weights[N - 1] <= W) {
        include = prices[N - 1] +
            knapsack(weights, prices, N - 1, W - weights[N - 1]);
    }
    int exclude = knapsack(weights, prices, N - 1, W);

    return std::max(include, exclude);
}

// Bottom Up DP
int knapsackDP(int weights[], int prices[], int N, int W) {
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1));
    for (int n {1}; n <= N; ++n) {
        for (int w {1}; w <= W; ++w) {
            int include {};
            if (weights[n - 1] <= w) {
                include = prices[n - 1] + dp[n - 1][w - weights[n - 1]];
            }
            int exclude {dp[n - 1][W]};
            dp[n][w] = std::max(include, exclude);
        }
    }
    return dp[N][W];
}

int main() {
    int w[] {2, 7, 3, 4};
    int p[] {5, 20, 20, 10};
    std::cout << knapsack(w, p, 4, 11) << '\n';
    std::cout << knapsackDP(w, p, 4, 11) << '\n';
    
}
