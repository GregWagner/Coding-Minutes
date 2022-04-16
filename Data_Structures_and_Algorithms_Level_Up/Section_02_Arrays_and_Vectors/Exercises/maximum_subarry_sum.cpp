/*
 * Maximum Subarry Sum
 *
 * Implement a function that takes as input a vector of integers and
 * prints the maximmum subarray sum that can be formed. A subarry is
 * defined as a consecutive segment of the array. If all numbers are
 * negative, return 0.
 *
 * Input        -1, 2, 3, 4, -2, 6, -8, 3
 * Output       13
 *
 * Used Kadane's algorithm (see section 19 Data Strctures Essentials)
 */
#include <iostream>
#include <vector>

int maxSubarraySum(std::vector<int> a) {
    int maxSum {};
    int currentSum {};
    for (auto element : a) {
        currentSum = std::max(0, currentSum + element);
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a {-1, 2, 3, 4, -2, 6, -8, 3};
    std::cout << (maxSubarraySum(a) == 13) << '\n';

    std::vector<int> b {-1, -2, -3, -4, -2, -6, -8, -3};
    std::cout << (maxSubarraySum(b) == 0) << '\n';

    std::vector<int> c {-1, -2, -3, -4, -2, -6, -8, 0};
    std::cout << (maxSubarraySum(c) == 0) << '\n';

    std::vector<int> d {};
    std::cout << (maxSubarraySum(d) == 0) << '\n';
}
