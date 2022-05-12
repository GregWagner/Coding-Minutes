/*
 * Find the largest sum of all the subarrays
 */
#include <iostream>
#include <vector>

// Brute Force O(n^3)
template <typename T>
int largestSubArraySum1(const std::vector<T> &a) {
    int largestSum {};
    for (size_t startingIndex {}; startingIndex < a.size(); ++startingIndex) {
        for (size_t endingIndex {startingIndex}; endingIndex < a.size(); ++endingIndex) {
            int subArraySum {};
            for (size_t index {startingIndex}; index < endingIndex; ++index) {
                subArraySum += a[index];
            }
            largestSum = std::max(largestSum, subArraySum);
        }
    }
    return largestSum;
}

// Prefix Sum O(n^2)
/*
 * Create a new prefix array with the sums of all the elements
 * input        1 2 4 -2 3
 * prefix       1 3 7  5 8
 * The sub array sum from i to j is prefix[j] - prefix[i - j]
 */
template <typename T>
int largestSubArraySum2(const std::vector<T> &a) {
    // precompute the prefix sum vector which is the sum of all the 
    // revious elements
    std::vector<T> prefix (a.size());
    prefix[0] = a[0];
    for (size_t i {1}; i < a.size(); ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    // now compute the largest sum using the prefix sum array
    int largestSum {};
    for (size_t startingIndex {}; startingIndex < a.size(); ++startingIndex) {
        for (size_t endingIndex {startingIndex}; endingIndex < a.size(); ++endingIndex) {
            // check for > 0 needed to avoid prefix index of -1
            int subArraySum = (startingIndex > 0 ?
                    prefix[endingIndex] - prefix[startingIndex - 1] :
                    prefix[endingIndex]);
            largestSum = std::max(largestSum, subArraySum);
        }
    }
    return largestSum;
}

/*
 * Kadane's Algorithm O(n)
 * Note: THis implementation does not handle all negaative numbers
 * input        -2 3 4 -1 5 -12 6 1 3
 * Maintain a running sum and if running sum is negative reset to zero
 * currentSum   0  3 7  6 11 0  6  7  10
 * maxSum       0  4 7  7 11 11 11 11 11
 */
template <typename T>
int largestSubArraySum3(const std::vector<T> &a) {
    int largestSum {};
    int currentSum {};
    for (const auto& ele: a) {
        currentSum += ele;
        if (currentSum > 0) {
            largestSum = std::max(largestSum, currentSum);
        } else {
            currentSum = 0;
        }
    }
    return largestSum;
}

int main() {
    std::vector<int> a {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    std::cout << largestSubArraySum1(a) << '\n';
    std::cout << largestSubArraySum2(a) << '\n';
    std::cout << largestSubArraySum3(a) << '\n';
}
