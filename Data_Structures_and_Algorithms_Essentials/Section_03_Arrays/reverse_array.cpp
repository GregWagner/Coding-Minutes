#include <algorithm>
#include <iostream>
#include <vector>

// Reverse array using 2 pointers
// O(1) space, O(n) time
template <typename T>
void reverse_array(std::vector<T>& a) {
    size_t left {};
    size_t right { a.size() - 1 };
    while (left < right) {
        std::swap(a[left++], a[right--]);
    }
}

template <typename T>
void print_array(const std::vector<T>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a { 10, 20, 30, 45, 60, 80, 90 };

    print_array(a);
    reverse_array(a);
    print_array(a);
}
