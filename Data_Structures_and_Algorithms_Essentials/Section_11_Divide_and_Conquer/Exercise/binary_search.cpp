/*
 * Given a sorted array, return the index of an element
 * in the array. Return -1 if the element is not present
 */
#include <iostream>
#include <vector>

int helper(const std::vector<int>& v, int key, int start, int end) {
    if (start >= end) {
        return -1;
    }
    int middle = (start + end) / 2;
    if (v[middle] == key) {
        return middle;
    }
    if (v[middle] > key) {
        return helper(v, key, start, middle);
    } else {
        return helper(v, key, middle + 1, end);
    }
}

int binarySearch(std::vector<int> v, int x) {
    return helper(v, x, 0, v.size());
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a { 1, 3, 5, 7, 9 };
    std::cout << (binarySearch(a, 3) == 1) << '\n';
    std::cout << (binarySearch(a, 9) == 4) << '\n';
    std::cout << (binarySearch(a, 100) == -1) << '\n';
}
