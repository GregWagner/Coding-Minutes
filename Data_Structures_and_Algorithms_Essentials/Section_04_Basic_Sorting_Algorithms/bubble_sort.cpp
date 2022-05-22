#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& a) {
    bool swapMade { true };
    size_t endingIndex { a.size() - 1 };
    while (swapMade) {
        swapMade = false;
        for (size_t i {}; i < endingIndex; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swapMade = true;
            }
        }
        --endingIndex;
    }
}

template <typename T>
void bubbleSort1(std::vector<T>& a) {
    size_t n = a.size();
    for (size_t i { 1 }; i < n - 1; ++i) {
        for (size_t j {}; j < n - i; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

template <typename T>
void print(const std::vector<T>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a { 6, 2, 7, 4, 8, 1, 3 };
    bubbleSort1(a);
    print(a);
}
