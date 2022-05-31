/*
 * Mountains
 * Write a funnction that takes as input an array of distinct integers
 * and returns the length (width) of the highest mountain.
 *  - A mountain is defined as adjacent integers that are strictly
 *    increasing until they reach a peak, at which the become strictly
 *    decreasing
 *  - At least 3 numbers are required to form a mountain.
 *
 * Input:
 *    5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4
 *       *  [           *           ]        *
 * Output:
 *    9
 *
 * 1) Identify where the peaks are
 *    6, 5, 3 are peaks
 * 2) Add up the uphill numbers (backwards) to reach peak and downhill
 *    numbers (forward)
 * O(n)
 */
#include <iostream>
#include <vector>

int highest_mountain(const std::vector<int>& a) {
    int n = a.size();
    int largest {};

    int i { 1 };
    while (i <= n - 2) {
        // check if a[i] is a peak or not
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            int count { 1 };

            // count uphill to get to peak (i.e. count backwards)
            int j { i };
            while (j > 0 && a[j - 1] < a[j]) {
                ++count;
                --j;
            }

            // count downhill from peak (i.e. count forwards)
            while (i <= n - 2 && a[i + 1] < a[i]) {
                ++count;
                ++i;
            }
            largest = std::max(count, largest);
        } else {
            ++i;
        }
    }
    return largest;
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a { 5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4 };
    std::cout << (highest_mountain(a) == 9) << '\n';
    std::vector<int> a2 { 2, 1, 4, 7, 3, 2, 5 };
    std::cout << (highest_mountain(a2) == 5) << '\n';
    std::vector<int> a1 { 0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0 };
    std::cout << (highest_mountain(a1) == 11) << '\n';
}
