#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& a) {
    bool swapMade {true};
    size_t endingIndex {a.size() - 1};
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
void print(const std::vector<T> &a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a {6, 2, 7, 4, 8, 1, 3};
    bubbleSort(a);
    print(a);
}
