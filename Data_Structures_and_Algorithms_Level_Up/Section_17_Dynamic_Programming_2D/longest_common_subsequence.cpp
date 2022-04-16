/*
 * Given 2 sequences, find the length of the longest subsequence
 * which is common to both of them.
 *
 * s1 = "ABCD"
 * s2 = "ABEDG"
 * Annswer 3 ("ABD")
 */
#include <iostream>
#include <vector>
#include <algorithm>

//bottom up
int lcs(std::string s1, std::string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    std::vector<std::vector<int>> dp(n1 + 1, std::vector<int> (n2 + 1, 0));
    // pick i characters from 1st string and j from the second
    for (int i {1}; i <= n1; ++i) {
        for (int j {1}; j <= n2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                int option1 {dp[i - 1][j]};
                int option2 {dp[i][j - 1]};
                dp[i][j] = std::max(option1, option2);
            }
        }
    }

    for (int i {}; i <= n1; ++i) {
        for (int j {}; j <= n2; ++j) {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    std::vector<int> result;
    int i {n1};
    int j {n2};
    while (i != 0 && j != 0) {
        if (dp[i][j] == dp[i][j - 1]) {
            --j;
        } else if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else {
            result.push_back(s1[i - 1]);
            --i;
            --j;
        }
    }
    std::reverse(result.begin(), result.end());
    for (char c : result) {
        std::cout << c << ' ';
    }
    std::cout << '\n';
    return dp[n1][n2]; 
}

// top down
int lcs(std::string &s1, std::string &s2, 
        std::vector<std::vector<int>> &dp, size_t i=0, size_t j=0) {
    if (i == s1.size() || j == s2.size()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (s1[i] == s2[i]) {
        return dp[i][j] = 1 + lcs(s1, s2, dp, i + 1, j + 1);
    }

    int option1 = lcs(s1, s2, dp, i + 1, j);
    int option2 = lcs(s1, s2, dp, i, j + 1);

    return dp[i][j] = std::max(option1, option2);
}

int main() {
    std::string s1 = "ABCD";
    std::string s2 = "ABEDG";

    size_t n1 = s1.size();
    size_t n2 = s2.size();
    std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, -1));

    std::cout << std::boolalpha;
    std::cout << (lcs(s1, s2, dp) == 3) << '\n';
    std::cout << (lcs(s1, s2) == 3) << '\n';

    for (size_t i {}; i <= n1; ++i) {
        for (size_t j {}; j <= n2; ++j) {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
