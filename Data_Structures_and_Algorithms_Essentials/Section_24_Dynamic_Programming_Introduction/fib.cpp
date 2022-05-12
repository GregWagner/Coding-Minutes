#include <iostream>
#include <vector>

// O(2^n)
int fib_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Topdown: recursive + memoisation
// O(n)
int fib_dp(int n, std::vector<int> dp) {
    if (n <= 1) {
        return n;
    }

    if (dp[n] == 0) {
        dp[n] = fib_dp(n - 1, dp) + fib_dp(n - 2, dp);
    }
    return dp[n];
}

// Bottom Up
int fib_dp1(int n) {
    int first = 0;
    int second = 1;
    int current {1};
    for (int i {2}; i <= n; ++i) {
        current = first + second;
        first = second;
        second = current;
    }
    return current;
}

int main() {
    std::cout << fib_recursive(6) << '\n';
    std::vector<int> a(10, 0);
    std::cout << fib_dp(6, a) << '\n';
    std::cout << fib_dp1(6) << '\n';
}
