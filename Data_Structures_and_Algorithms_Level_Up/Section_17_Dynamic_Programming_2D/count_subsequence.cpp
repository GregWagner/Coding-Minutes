/*
 * Given 2 strrings, find the number of times the second string
 * occurs as a subsequence inn the first string.
 * s1 = "ABCDCE"
 * s1 = "ABC"
 * output 2
 */
#include <iostream>
#include <vector>

// recursive solution
int countSub(const std::string &a, const std::string &b, int m, int n) {
    if ((m == -1 && n == -1) || n == -1) {
        return 1;
    }
    if (m == -1) {
        return 0;
    }

    if (a[m] == b[n]) {
        return countSub(a, b, m - 1, n - 1) +
            countSub(a, b, m - 1, n);
    }
    return countSub(a, b, m - 1, n);
}

// bottom up 
int countSub(const std::string &a, const std::string &b) {
    int m = a.size();
    int n = b.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // first column is 1 (base case)
    for (int i {}; i <= m; ++i) {
        dp[i][0] = 1;
    }

    for (int i {1}; i <= m; ++i) {
        for (int j {1}; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::string a = "ABCECDG";
    std::string b = "ABC";
    std::cout << std::boolalpha;
    std::cout << (countSub(a, b, a.size() - 1, b.size() - 1) == 2) << '\n';
    std::cout << (countSub(a, b) == 2) << '\n';
}
