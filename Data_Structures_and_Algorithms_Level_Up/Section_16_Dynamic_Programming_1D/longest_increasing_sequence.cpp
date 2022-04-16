/*
 * Given an array sequence, find the length of the longest subsequence 
 * such that all elements of the subsequennce are sorted in increasing
 * order.
 */
#include <iostream>
#include <vector>

// bottom up 
int lis(const std::vector<int> &a) {
    std::vector<int> dp(a.size(), 1);

    int length {1};
    for (size_t i {1}; i < a.size(); ++i) {
        for (size_t j {}; j < i; ++j) {
            if (a[i] > a[j]) {
                dp[i] = std::max(dp[i], 1 + dp[j]);
                length = std::max(length, dp[i]);
            }
        }
    }
    return length;
}


int main() {
    std::vector<int> a {50, 4, 10, 8, 30, 100};
    std::cout << std::boolalpha;
    std::cout << (lis(a) == 4) << '\n';
}
