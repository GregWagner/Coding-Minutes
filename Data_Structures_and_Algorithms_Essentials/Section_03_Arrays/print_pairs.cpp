/*
 * Print all the pairs of an array
 */
#include <iostream>
#include <vector>

template <typename T>
void printAllPairs(const std::vector<T>& a) {
    for (size_t i {}; i < a.size(); ++i) {
        for (size_t j { i + 1 }; j < a.size(); ++j) {
            std::cout << a[i] << ", " << a[j] << '\n';
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<int> a { 10, 20, 30, 40, 50, 60 };

    printAllPairs(a);
}
