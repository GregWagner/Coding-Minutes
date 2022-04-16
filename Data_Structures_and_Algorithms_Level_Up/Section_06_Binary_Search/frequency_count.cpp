/*
 * Frequency Count
 *
 * Given a sorted array which can contain repeated elements,
 * and a key, find the frequency of the given key.
 *
 * Use modified binary search
 * 1) Find lower bound (either left or at found position)
 * 2) Find uppper bound (either right or at found position)
 *
 * Could also use std::upper_bound and std::lower_bound
 */
#include <iostream>
#include <vector>

int upper_bound(std::vector<int> a, int key) {
    int start {};
    int end = a.size() - 1;
    int answer {-1};

    while (start <= end) {
        int middle = (start + end) / 2;
        if (a[middle] == key) {
            answer = middle;
            start = middle + 1;
        } else if (a[middle] > key) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }
    return answer;
}

int lower_bound(std::vector<int> a, int key) {
    int start {};
    int end = a.size() - 1;
    int answer {-1};

    while (start <= end) {
        int middle = (start + end) / 2;
        if (a[middle] == key) {
            answer = middle;
            end = middle - 1;
        } else if (a[middle] > key) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }
    return answer;
}

int main() {
    std::vector<int> a {0, 1, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 10};
    std::cout << lower_bound(a, 3) << std::endl;
    std::cout << upper_bound(a, 3) << std::endl;
}
