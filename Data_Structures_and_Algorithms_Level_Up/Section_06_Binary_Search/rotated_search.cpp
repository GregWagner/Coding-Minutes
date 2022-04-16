/*
 * Rotated Search
 *
 * Write a function that takes a sorted array of distinct
 * integers which is rotated about a pivot point and find
 * the index of any given element.
 *
 * [7, 9, 10, 1, 2, 3, 4, 5, 6] element = 4
 * output 6
 *
 * Note - you don't need to find the pivot
 *
 */
#include <iostream>
#include <vector>

int search(std::vector<int> a, int key) {
    int start {};
    int end = a.size() - 1;

    while (start <= end) {
        int middle = (start + end) / 2;
        if (a[middle] == key) {
            return middle;
        } else if (a[start] <= a[middle]) {
            // on the left (from start to middle is sorted)
            if (key >= a[start] && key <= a[middle]) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        } else {
            // on the right (from middle to end is sorted)
            if (key >= a[middle] && key <= a[end]) {
                start = middle + 1;
            } else {
                end = middle - 1;

            }
        }
    }
    return -1;
}

int main() {
    std::vector<int> a {4, 5, 6, 7, 0, 1, 2, 3};
    std::cout << search(a, 6) << std::endl;
}
