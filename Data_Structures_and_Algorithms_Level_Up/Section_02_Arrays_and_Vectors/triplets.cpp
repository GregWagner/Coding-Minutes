/*
 * Triplets
 *
 * Given an array containing N integers and a number S denoting a target
 * sum, find all distinct integers that can add up to form the target
 * sum. The numbers in each triplet should be ordered in ascending order,
 * and the triplets should be ordered also.
 * Return an empty array if no such triplet exists.
 *
 * Input
 *    [1, 2, 3, 4, 5, 6, 7, 8, 9, 15]
 *    targetSum = 18
 *
 * Output:
 *    [[1, 2, 15],
 *     [3, 7, 8],
 *     [4, 6, 8],
 *     [5, 6, 7]]
 *
 * 1) Brute Force
 *    3 for loops = O(n^3)
 * 2) For each number in the array
 *    Calculate new sum needed
 *    Handle same as we did with pairs (unordered_set)
 *    O(n^2) time and O(n) space
 * 3) Sort array  - O(n log n)
 *    For each number
 *       Use pairSum to find other numbers using 2 pointer approach
 *           (one at 1st and one at last)
 *           This takes a total of O(n^2)\
 *   NOTE: You can't use this for the orginal pairSum since the sorting
 *   would be the bottleneck.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> triplets(std::vector<int>& a, int targetSum) {
    std::vector<std::vector<int>> results;

    std::sort(a.begin(), a.end());

    // pick every element and solve pair sum for remaining part
    int n = a.size();
    for (int i {}; i <= n - 3; ++i) {

        // 2 pointer approach
        // point to the next element and the last element
        int start { i + 1 };
        int end { n - 1 };

        while (start < end) {
            int currentSum = a[i] + a[start] + a[end];
            if (currentSum == targetSum) {
                results.push_back({ a[i], a[start], a[end] });
                ++start; // setup to look for more pairs
                --end;
            } else if (currentSum > targetSum) {
                // too high, try moving to left
                --end;
            } else {
                // too low, try moving to the right
                ++start;
            }
        }
    }
    return results;
}

int main() {
    std::vector<int> a { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
    int targetSum = 18;

    auto p = triplets(a, targetSum);

    if (p.empty()) {
        std::cout << "No such pair exists\n";
    } else {
        for (auto e : p) {
            std::cout << "[" << e[0] << ", " << e[1] << ", " << e[2] << "]\n";
        }
    }
}
