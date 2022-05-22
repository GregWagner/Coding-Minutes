#include <algorithm>
#include <iostream>
#include <vector>

const int NOT_FOUND { -1 };

template <typename T>
int binary_search(const std::vector<T>& a, T key) {
    size_t start {};
    size_t end { a.size() };
    while (start < end) {
        size_t middle { (start + end) / 2 };
        if (a[middle] == key) {
            return static_cast<int>(middle);
        }
        if (a[middle] < key) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return NOT_FOUND;
}

int main() {
    std::vector<int> a { 10, 15, 12, 9, 6, 4, 3, 10, 8 };
    std::sort(std::begin(a), std::end(a));

    int key {};
    std::cin >> key;

    auto index = binary_search(a, key);

    if (index == NOT_FOUND) {
        std::cout << key << " is NOT found\n";
    } else {
        std::cout << key << " is present at index " << index << '\n';
    }
}
