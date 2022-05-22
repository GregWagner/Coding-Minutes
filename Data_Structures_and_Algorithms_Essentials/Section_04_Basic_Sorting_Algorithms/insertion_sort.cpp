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
void insertationSort(std::vector<T>& a) {
    if (a.size() <= 1) {
        return;
    }

    for (size_t i { 1 }; i < a.size(); ++i) {
        int currentValue { a[i] };
        size_t j = i;
        while ((j > 0) && (a[j - 1] > currentValue)) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = currentValue;
    }
}

int main() {
    std::vector<int> a { 6, 2, 7, 4, 8, 1, 3 };
    insertationSort(a);
    print(a);
}
