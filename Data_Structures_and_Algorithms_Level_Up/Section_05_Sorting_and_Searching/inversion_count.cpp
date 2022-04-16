/*
 * Inversion Count
 * 
 * Given an array containing integers, you need to return the total 
 * number of inversions. In inversion is when 2 elements a[i] and a[j]
 * form and inversion if a[i] > a[j] and i < j.
 * 
 * input:
 *  0 5 2 3 1
 * Output
 *  5
 *
 *  0 2 5 3 1       1
 *  0 2 3 5 1       2
 *  0 2 3 1 5       3
 *  0 2 1 3 5       4
 *  0 1 2 3 5       5
 *
 *  Brute force: compare every element i with every element after i which
 *  take O(n^2)
 *
 *  Calculate how many inversions each element will form 
 *  Try a D&C algorithm
 *  Split in 2 and calculate
 *  1) number of inversions in left
 *  2) number of inversions in right
 *  3) number of inversions between left and right
 *
 *  left = 0 5 2            Inversions (5, 2)
 *  right = 3, 1            Inversions (3, 1)
 *                          Cross inversions (5, 3), (5, 1), (2, 1)
 * To calculate cross inversions:
 *      During the merge, an inversion occurs when you move an element from the 
 *      right array into the left array (not including those moved after the left
 *      array is done)
 *      left   0, 3, 8, 10
 *      right   1, 12
 *
 *      temp    0           0 inveersions
 *              0, 1        3 inversions
 *      none of the rest of the merge causes an inversion
 *
 * Note this is basicly merge sort!!!
 */
#include <iostream>
#include <vector>

void printVector(const std::vector<int> &a) {
    for (const auto &e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

int merge(std::vector<int> &a, int start, int end) {
    int left = start;
    int middle = (start + end) / 2;
    int right = middle + 1;
    int inversionCount {};

    std::vector<int> temp;
    while (left <= middle && right <= end) {
        if (a[left] < a[right]) {
            temp.push_back(a[left++]);
        } else {
            temp.push_back(a[right++]);
            inversionCount += middle - left + 1;
        }
    }

    // copy remaining elements (if any)
    while (left <= middle) {
        temp.push_back(a[left++]);
    }
    while (right <= end) {
        temp.push_back(a[right++]);
    }

    int k {};
    for (int index {start}; index <= end; ++index) {
        a[index] = temp[k++];
    }
    return inversionCount;
}

int countInversions(std::vector<int> &a, int start, int end) {
    if (start >= end) {
        return 0;
    }

    int middle = (start + end) / 2;
    int rightInversionCount = countInversions(a, start, middle);
    int leftInversionCount = countInversions(a, middle + 1, end);
    int crossInversionCount = merge(a, start, end);
    return rightInversionCount + leftInversionCount + crossInversionCount;
}

int main() {
    std::vector<int> a {0, 5, 2, 3, 1};
    std::cout << countInversions(a, 0, a.size() - 1) << '\n';
}
