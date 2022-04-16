/*
 * Given an array, you need to count the number of triplets
 * with indicies (i, j, k) such that the elements at those
 * indices are in geometric progression for a given common
 * ratio r and i (i < j < k).
 *
 * Sliding Hash algorithm
 * w 2 hash tables (one for left and one for right)
 * as you move to the right - remove from right hash and add 
 * to left.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

int countTriplets(const std::vector<int> &a, int r) {
    std::unordered_map<long, long> leftSide;
    std::unordered_map<long, long> rightSide;

    // start with everything in the right
    for (auto x : a) {
        ++rightSide[x];
        leftSide[x] = 0;
    }

    int answer {};
    for (auto x : a) {
        --rightSide[x];

        if (x % r == 0) {
            long a = x / r;
            long b = x * r;

            answer += leftSide[a] * rightSide[b];
        }
        ++leftSide[x];
    }
    return answer;
}

int main() {
    std::vector<int> a {1, 16, 4, 16, 64, 16};

    std::cout << std::boolalpha;
    std::cout << (countTriplets(a, 4) == 3) << '\n';
}
