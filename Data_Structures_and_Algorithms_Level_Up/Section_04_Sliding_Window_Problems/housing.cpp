/*
 * Housing
 *
 * Along one side of a road there is a sequence of vacanent plots of land. Each
 * plot has a different non-zero area. So the areas form a sequence A[1], A[2], 
 * ...A{N}.
 * You want to buy K acres of land to build a house. You want to find all
 * seqments of contingous plots (i.e. subsection in the sequencce) of whose
 * sum is exactly K.
 *
 * Sample Input
 *  Plots = 1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2
 *  K = 8
 * Output
 *  2 5  (index 2-5)
 *  4 6
 *  5 9
 *
 * Brute Force would be O(n^3)
 *
 * Prefix Sum: (O(n log n))
 *  Input       1 3 2 5
 *  Prefix Sum  1 4 6 11
 *  PS[i] = PS[i - 1] + a[i]
 *  for every i, you find a j such that PS[j] - PS[i] = K
 *  if K = 7 that PS[3] - PS[1] = 7 so answer is 1 3
 *  Note: input must be non-negative so that PS is a non-decreasing sequence
 *
 * Sliding window (O(n))
 *  2 indexes and a current sum.
 *  Move one index and keep track of current sum until sum is greater than K,
 *  then move the other index and subtract until current sum is less than K.
 *  Repeat until the current sum is equal to K
 *
 */
#include <iostream>
#include <vector>

void housing(const std::vector<int> &a, int n, int k) {
    int i {};
    int j {};
    int currentSum {};

    while (j < n) {
//      std::cout << "i: " << i << ", j: " << j << ", sum: " << currentSum << '\n';
        // expand to the right
        currentSum += a[j];
        ++j;

        // remove elements from the left if needed
        while (currentSum > k && i < j) {
            currentSum -= a[i];
            ++i;
        }

        if (currentSum == k) {
            std::cout << i << ' ' << j - 1 << '\n';
        }
    }
}

int main() {
    std::vector<int> plots {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
    int k {8};
    housing(plots, plots.size(), k);
}
