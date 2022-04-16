/*
 * Min Pairs
 *
 * Given 2 non-empty arrays, find the pair of number (one from
 * each array) whose absolute difference is minimmum. Print the
 * any one pair with the smallest different.
 *
 * a1 = [-1, 5, 10, 20, 3]
 * a2 = [26, 134, 135, 15, 17]
 *
 * Answer: [20, 17]
 *
 * 1) Sort the second array
 * 2) Go through each element of the first array and using 
 *    lower_bound and upper_bound, find the closest value.
 * 3) Check if that is a minimum
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void min_pair(std::vector<int>& a1, std::vector<int>& a2) {
    std::sort(a2.begin(), a2.end());

    int p1 {};
    int p2 {};
    int difference {INT_MAX};

    // iteraate over the 1st array and look for closeest element in 2nd array
    for (auto e : a1) {
        auto lowerIndex = std::lower_bound(a2.begin(), a2.end(), e) - a2.begin();

        // left
        if (lowerIndex >= 1 && e - a2[lowerIndex - 1] < difference) {
            difference = e - a2[lowerIndex - 1];
            p1 = e;
            p2 = a2[lowerIndex - 1];
        }

        // greater / right
        if (lowerIndex != a2.size() && a2[lowerIndex] - e < difference) {
            difference = a2[lowerIndex] - e;
            p1 = e;
            p2 = a2[lowerIndex];
        }
    }
    std::cout << "Min Pair: " << p1 << ", " << p2 << '\n';
}

int main() {
    std::vector<int> a1 {-1, 5, 10, 20, 3};
    std::vector<int> a2 {26, 134, 135, 15, 17};
    min_pair(a1, a2);
}
