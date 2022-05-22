/*
 * Print all subarrays of a given array
 */
#include <iostream>
#include <vector>

template <typename T>
void printSubArrays(const std::vector<T>& a) {
    for (size_t startingIndex {}; startingIndex < a.size(); ++startingIndex) {
        for (size_t endingIndex { startingIndex }; endingIndex < a.size(); ++endingIndex) {
            // iterate from start index to end index
            for (size_t index { startingIndex }; index < endingIndex; ++index) {
                std::cout << a[index] << ' ';
            }
            std::cout << '\n';
        }
    }
}

int main() {
    std::vector<int> a { 10, 20, 30, 40, 50, 60 };
    printSubArrays(a);
}
