#include <iostream>
#include <vector>

template <typename T>
void print(const std::vector<T>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void selectionSort(std::vector<T>& a) {
    for (size_t i {}; i < a.size() - 1; ++i) {
        // find the smallest unsorted value
        size_t smallestPosition = i;
        for (size_t j { i }; j < a.size(); ++j) {
            if (a[j] < a[smallestPosition]) {
                smallestPosition = j;
            }
        }
        // put smallest in correct spot
        std::swap(a[i], a[smallestPosition]);
        //      print(a);
    }
}

int main() {
    std::vector<int> a { 6, 2, 7, 4, 8, 1, 3 };
    print(a);
    selectionSort(a);
    print(a);
}
