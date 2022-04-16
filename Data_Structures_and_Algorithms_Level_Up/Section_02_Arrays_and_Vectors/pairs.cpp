/*
 * Pairs
 *
 * Given an array containing N integers and a number totalSum denoting a
 * target sum, find two distinct integers that can pair up to form the
 * target sum. Assume that there will only be one such pair.
 *
 * Input:
 *    array = [10, 5, 2, 3, -6, 9,, 11]
 *    S = 4
 * Output:
 *    [10, -6]
 *
 * Possiblle Solutions
 * 1) Brute force Approach
 *    O(n^2)
 *    2 nested for loops
 * 2) Sort the array
 *    Binary search
 *    O(n log n)
 * 3) Hash table
 *    Can look up in O(1) time
 *    O(n)
 *    Go through the array and for each value check if the needed number
 *    is in the hash table, if not add it and move to the next number
 *    Note: creating the hash first may cause a problem if x + x = S
 */
#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> pairSum(const std::vector<int> &a, int totalSum) {
    std::unordered_set<int> hash;
    std::vector<int> results;

    for (auto const value : a) {
        // check if the number needed has already been added to the hash
        if (hash.find(totalSum - value) != hash.end()) {
            results.push_back(value);
            results.push_back(totalSum - value);
            break;
        }
        hash.insert(value);
    }
    return results;
}

int main() {
    std::vector<int> a {10, 5, 2, 3, -6, 9, 11};
    int totalSum = 4;

    auto p = pairSum(a, totalSum);
    if (p.empty()) {
        std::cout << "No such pair exists\n";
    } else {
        std::cout << "[" << p[0] << ", " << p[1] << "]\n";
    }
}
