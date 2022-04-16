/*
 * Subarry Sort
 * 
 * Given an array with a size of at-least two, find the smallest subarray that
 * needs to be sorted in place so that the entire input array beccoes sorted.
 * If the input array is already sorted, the function shoulld return [-1, -1],
 * otherwise return the start and end index of the smallest subarray.
 * 
 * Input:
 *    1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11
 *                   [       ]
 * Output:
 *    [5, 7]
 * 
 * Approaches
 * 1) Sort array and compare with original (from left and from right)
 *    original to determine what items are out of place
 *    O(n log n)
 * 2) Iterate through array and find smallest and largest item that is out
 *    of order
 *       smallest would be 6 and largest 8
 *    Now find the correct positions where these would go
 *       From left find where smallest should be
 *       From right find where largest should be
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Brute Force Method O(n log n) timeA
std::pair<int, int> bruteForce(std::vector<int> a) {
    std::vector<int> b (a);          // save the original order
    std::sort(a.begin(), a.end());

    unsigned long left {};
    size_t n {a.size()};

    while (left < n && a[left] == b[left]) {
        ++left;
    }

    unsigned long right {n - 1};
    while (right >= 0 && a[right] == b[right]) {
        --right;
    }

    // check if already sorted
    if (left == a.size()) {
        return {-1, -1};
    }
    return {left, right};
}

// Helper function
bool outOfOrder(const std::vector<int> &a, int i) {
    int x {a[i]};

    // handle if looking at the first element in array
    if (i == 0) {
        return x > a[1];
    }

    // handle if looking at the last element in array
    if (i == static_cast<int>(a.size() - 1)) {
        return a[i - 1] > x;
    }

    return a[i - 1] > x || x > a[i + 1];
}

std::pair<int, int> subarrySort(std::vector<int> a) {
    int smallest {INT_MAX};
    int largest {INT_MIN};

    for (size_t i {}; i < a.size(); ++i) {
        int currentValue {a[i]};
        if (outOfOrder(a, i)) {
            smallest = std::min(smallest, currentValue);
            largest = std::max(largest, currentValue);
        }
    }

    // check if all elements were sorted
    if (smallest == INT_MAX) {
        return {-1, -1};
    }

    // now find the right index where the smallest and largest are
    int left {};
    while (smallest > a[left]) {
        ++left;
    }
    int right {static_cast<int>(a.size() - 1)};
    while (largest <= a[right]) {
        --right;
    }
    return {left, right};
}

int main() {          //0  1  2  3  4  5  6  7  8  9   10
    std::vector<int> a {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    std::vector<int> b {1, 2, 3, 4, 5};
    std::vector<int> c {5, 4, 3, 2, 1};
    std::vector<int> d {2, 6, 4, 8, 10, 9, 15};

    auto answer = subarrySort(a);
    std::cout << '{' << answer.first << ", " << answer.second << "}\n";
    answer = subarrySort(b);
    std::cout << '{' << answer.first << ", " << answer.second << "}\n";
    answer = subarrySort(c);
    std::cout << '{' << answer.first << ", " << answer.second << "}\n";
    answer = subarrySort(d);
    std::cout << '{' << answer.first << ", " << answer.second << "}\n";
}
