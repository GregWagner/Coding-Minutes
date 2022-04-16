/*
 * Quick Sort
 * Average O(n log(n))
 * Worst cast P(n^2)
 *
 * 1) Choose a pivot (example last element)
 * 2) Partition into 2 parts (< pivot and > pivot)
 * 3) Recusrively sort the left and right
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

void quicksort(std::vector<int>& a, int start, int end) {
    if (start >= end) {
        return;
    }
    int p = partition(a, start, end);
    quicksort(a, start, p - 1);
    quicksort(a, p + 1, end);
}

int main() {
    std::vector<int> a {10, 5, 2, 0, 7, 6, 4};
    quicksort(a, 0, a.size() - 1);

    for (auto x: a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
