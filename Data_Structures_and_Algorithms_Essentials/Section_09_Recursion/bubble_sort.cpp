#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& a, size_t n, size_t j) {
    if (n <= 1) {
        return;
    }

    // if we reached the end of this pass
    if (j == n - 1) {
        // reduce problem size and reset j to 0
        bubbleSort(a, n - 1, 0);
        return;
    }

    if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
    }
    bubbleSort(a, n, j + 1);
}

template <typename T>
void print(const std::vector<T> &a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a {6, 2, 7, 4, 8, 1, 3};
    bubbleSort(a, a.size(), 0);
    print(a);
}
