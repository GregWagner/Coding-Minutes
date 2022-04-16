/*
 * Given a ladder of size N and in integer K, write a funnction
 * to compute the number of ways to climb the ladder if you can
 * take a jump of at most k at every step.
 *
 * N = 4, K = 3
 * Answer:7
 */
#include <iostream>
#include <vector>

// recursive approach O(n^n)
int countWaysRec(int n, int k) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }

    int answer {};
    for (int jump {1}; jump <= k; ++jump) {
        answer += countWaysRec(n - jump, k);
    }
    return answer;
}

// Top down
int countWays(int n, int k, int* dp) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }

    // check if state is already computed
    if (dp[n] != 0) {
        return dp[n];
    }

    int answer {};
    for (int jump {1}; jump <= k; ++jump) {
        answer += countWays(n - jump, k, dp);
    }
    return dp[n] = answer;
}

// bottom up -iteratrive O(n*k)
int countWays(int n, int k) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i {1}; i <= n; ++i) {
        for (int jump {1}; jump <= k; ++jump) {
            if (i - jump >= 0) {
                dp[i] += dp[i - jump];
            }
        }
    }
    return dp[n];
}

// bottom up optimzied O(n+k)
int countWaysOpt(int n, int k) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i {2}; i <= k; ++i) {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i {k + 1}; i <= n; ++i) {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }
    return dp[n];
}


int main() {
    std::cout << std::boolalpha;
    int dp[1000] {};
    std::cout << (countWaysOpt(6, 4) == 29) << '\n';
    std::cout << (countWays(4, 3, dp) == 7) << '\n';
    std::cout << (countWays(4, 3) == 7) << '\n';
}
