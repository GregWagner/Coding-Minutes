#include <iostream>

int main() {
    int n = 10;
    int dp[n + 1] {};

    for (int i {}; i <= n; ++i) {
        dp[i] = dp[i / 2] + (i % 2);
        std::cout << i << ": " << dp[i] << '\n';
    }
}
