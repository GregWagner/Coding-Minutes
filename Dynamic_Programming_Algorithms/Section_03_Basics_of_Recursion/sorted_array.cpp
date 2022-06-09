/*
 * Example 3
 * Write a function to check if an array is sorted
 */
#include <iostream>
#include <vector>

bool isArraySorted(const std::vector<int>& n, unsigned index = 0) {
    if (index >= n.size()) {
        return true;
    }
    return (n[index] < n[index + 1]) && (isArraySorted(n, index + 1));
}

int main() {
    std::vector<int> n = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << std::boolalpha;
    std::cout << isArraySorted(n) << '\n';
}
