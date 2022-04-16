/*
 * Longest Band 
 *
 * Given an array containing N integers, find the length of the longest band.
 *
 * A band is defined as a subsequence which can be re-ordered in such a
 * manner that all the elements appear consecutive (i.e. with absolute
 * differnce of 1 between neighbouring elements).
 *
 * A longest band is the band (subsequence) which contains the maximum
 * integers.
 *
 * Input:
 *    1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6
 * Output:
 *    8
 *
 * Explanation:
 * Largest subset containing consectutive numbers is:
 *    0, 1, 2, 3, 4, 5, 6, 7
 *
 * Approaches
 * 1) Sort and then count consecutive numbers. Start a new band when reaching a 
 *    non-consecutive number O(n log n + n)
 * 2) Hint:
 *    Select a number and see if it is the start of a band, if not find the
 *    start of this particular band by going backwards
 *       i.e. You pick 1 so you need to see if 0 is in the array, if it is
 *       then it is not the start of a band so go to next number.
 *       Once a start of band is found, go forward counting consecutive numbers
 *    i.e. you need an unordered set for O(n)
 */
#include <iostream>
#include <unordered_set>
#include <vector>

int largestBand(const std::vector<int> &a) {
    // create the unordered set from the vector
    std::unordered_set<int> hash(std::begin(a), std::end(a));

    int largest {};
    for (auto const e : a) {
        int startOfBand {e};
        // check if this number is the start of a band
        if (hash.find(startOfBand - 1) == hash.end()) {
            // yes - this number is the start of a band
            int currentBandCount {1};
            int i {1};
            while (hash.find(startOfBand + i) != hash.end()) {
                ++i;
                ++currentBandCount;
            }
            largest = std::max(currentBandCount, largest);
        }
    }
    return largest;
}

int main() {
    std::vector<int> a {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    std::cout << largestBand(a) << '\n';
}
