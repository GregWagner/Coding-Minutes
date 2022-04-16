/*
 * Implement a function that takes an array as input
 * and returns the maximmum subarray sum.
 *
 */
#include <iostream>
#include <vector>

template <typename T>
int maxSumSubarray(const std::vector<T>& a) {
    int largestSum {a[0]};
    int currentSum {};
    for (const auto& ele : a) {
        currentSum += ele;
        if (currentSum < 0) {
            currentSum = 0;
        } else {
            largestSum = std::max(largestSum, currentSum);
        }
    }
    return largestSum;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a {1, -2, 3, 4, 4, -2};
    std::cout << (maxSumSubarray(a) == 11) << '\n';

    std::vector<int> b {5, 0, -1, 0, 1, 2, -1};
    std::cout << (maxSumSubarray(b) == 7) << '\n';
}
