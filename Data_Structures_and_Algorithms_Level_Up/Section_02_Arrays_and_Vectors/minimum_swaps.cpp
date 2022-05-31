/*
 * Minimum Swaps
 *
 * Given an array of size N, find the minumum number of swaps
 * needed to make the array sorted.
 *
 * Sample Input                 Output
 *      5, 4, 3, 2, 1           2 (swap 5 and 1, swap 4 and 2)
 * --------------------------------------------------------------
 *      10, 11, 5, 4, 3, 2, 1   4
 *      1   2   3  4  5  10 11
 *      1st cycle 10 -> 2 -> 11 -> 1 -> 10      requires 3 swaps
 *      swap 10 and 2       2  11  5  4  3  10  1
 *      swap 2 and 11       11  2  5  4  3  10  1
 *      swap 11 and 1       1   2  5  4  3  10  11
 *      2nd cycle is 5 -> 3 -> 5                requires 1 swap
 *      swap 5 and 3        1   2  3  4  5  10  11
 * --------------------------------------------------------------
 *      2, 4, 5, 1, 3
 *      1  2  3  4  5
 *      1st cycle 2 -> 4 -> 1 -> 2      requires cycle length - 1 (2)
 *          swap 2 and 4    4 2 5 1 3
 *          swap 4 and 1    1 2 5 4 3
 *      2nd cycle 5 -> 3 -> 5           requires cycle length - 1 (1)
 *          swap 5 and 3    1 2 3 4 5
 *                                         3 swaps required
 *
 * To calculate you need to figure out the correct location of each
 * element of the array.
 * - i.e. sort the array
 * --------------------------------------------------------------
 * Input:
 * ap = | 2 4 5 1 3 |    after sorting: | 1 2 3 4 5 |
 *      | 0 1 2 3 4 |                   | 3 0 4 1 2 |
 *
 * visited = [false, false, false, false, false]
 *
 * index = 0            ap[0] = 1, 3
 *      next node = 3   ap[3] = 4, 1
 *      next node = 1   ap[1] = 2, 0
 *      next node = 0   already visited (and old_position = i)
 * visited = [true, true, false, true, false]
 * swaps needed = 2
 *
 * index = 1            already visited
 * index = 2            ap[2] = 3, 4
 *      next node = 4   ap[4] = 5, 2
 *      next node = 2   already visited
 * visited = [true, true, true, true, true]
 * swaps neeed = 1
 *
 * total swaps needed = 3
 * --------------------------------------------------------------
 */
#include <algorithm>
#include <iostream>
#include <vector>

int countMinimumSwaps(std::vector<int>& a) {
    size_t n = a.size();

    // Store the current indice with the value
    // std::pair<int, int> ap[n];
    std::vector<std::pair<int, int>> ap(n);
    for (size_t i {}; i < a.size(); ++i) {
        ap[i].first = a[i];
        ap[i].second = i;
    }

    std::sort(ap.begin(), ap.end());

    // keep track if an item was part of a cycle.
    std::vector<bool> visited(n, false);

    int answer {};
    for (size_t i {}; i < n; ++i) {
        // if element has already been visited or element is already
        // in the correct position. If so, we can ignore this element
        if (visited[i] || ap[i].second == static_cast<int>(i)) {
            continue;
        }

        // visiting the element for the first time
        unsigned long node { i };
        int cycle {};

        while (!visited[node]) {
            visited[node] = true;
            // go to the next node
            node = ap[node].second; // orginal position
            ++cycle;
        }
        // it take n-1 swaps
        answer += cycle - 1;
    }
    return answer;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a { 5, 4, 3, 2, 1 };
    std::cout << (countMinimumSwaps(a) == 2) << '\n';

    std::vector<int> b { 10, 11, 5, 4, 3, 2, 1 };
    std::cout << (countMinimumSwaps(b) == 4) << '\n';

    std::vector<int> c { 2, 4, 5, 1, 3 };
    std::cout << (countMinimumSwaps(c) == 3) << '\n';
}
