/*
 * Print the number of set bits for each number from
 * 1 to n.
 *
 * Brute force is O(n logn)
 * Recursive is O(n)
 *
 * Need to look at the numbers in paris
 * For example 5 and 10 -- 5<<2 = 10
 */

#include <iostream>

int main() {
    int n = 10;
    int dp[11] {};

    for (int i {}; i <= n; ++i) {
        dp[i] = dp[i / 2] + (i & 1);
        std::cout << i << ": " << dp[i] << '\n';
    }
}
