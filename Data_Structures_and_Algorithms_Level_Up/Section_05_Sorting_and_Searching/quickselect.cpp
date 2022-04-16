/*
 * Quick Select
 *
 * Given an array of intergers, return the 
 * kth smallest integer.
 *
 * Sample input
 *      [10, 5, 2, 0, 7, 6, 4]  k = 4
 * Output
 *      5
 *
 * Solution - use partition until you swap the parition
 * into the correct index - that is your answer.
 * Note: only quick sort the part of the array that will
 * have the index in it.
 */
#include <iostream>
#include <vector>

int partition(std::vector<int>& a, int start, int end) {
    int pivot = a[end];
    int i = start - 1;

    for (int j {start}; j < end; ++j) {
        if (a[j] < pivot) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[end]);
    return i + 1;
}

int quickselect(std::vector<int>& a, int start, int end, int k) {
    int p = partition(a, start, end);
    if (p == k) {
        return a[p];
    } else if (k < p) {
        return quickselect(a, start, p - 1, k);

    }
    return quickselect(a, p + 1, end, k);
}

int main() {
    std::vector<int> a {10, 5, 2, 0, 7, 6, 4};
    std::cout << quickselect(a, 0, a.size() - 1, 4) << '\n';
}
