/*
 * Merge Sort
 * Divide and Conquere Algorithm
 * 1) Divided into 2 parts
 * 2) Merge sort the left and the right part
 * 3) Merge the left and right into the final array
 *
 * Input    10, 5, 2, 0, 7, 6, 4
 * Output   0, 2, 4, 5, 6, 7, 10
 */
#include <iostream>
#include <vector>

void printVector(const std::vector<int> &a) {
    for (const auto &e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

void merge(std::vector<int> &a, int start, int end) {
    std::cout << "\nEntering merge, start: " << start << ", end: " << end << '\n';
    printVector(a);

    int left = start;
    int middle = (start + end) / 2;
    int right = middle + 1;

    std::vector<int> temp;
    while (left <= middle && right <= end) {
        if (a[left] < a[right]) {
            temp.push_back(a[left++]);
        } else {
            temp.push_back(a[right++]);
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
}

void mergesort(std::vector<int> &a, int start, int end) {
    if (start >= end) {
        return;
    }
    int middle = (start + end) / 2;
    mergesort(a, start, middle);
    mergesort(a, middle + 1, end);
    merge(a, start, end);
}

int main() {
    std::vector<int> a {10, 5, 2, 0, 7, 6, 4};
    mergesort(a, 0, a.size() - 1);
    printVector(a);
}
