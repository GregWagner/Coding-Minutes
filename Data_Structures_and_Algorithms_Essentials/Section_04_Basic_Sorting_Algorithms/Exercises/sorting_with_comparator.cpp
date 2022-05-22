/*
 * Given a vector and bool flag, sort the vector in acccodance to the
 * boolean value. true -> sort in non-descreasing order.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> sortingWithComparator(std::vector<int> a, bool flag) {

    if (flag) {
        std::sort(begin(a), end(a));
    } else {
        std::sort(begin(a), end(a), [](int a, int b) { return a > b; });
    }
    return a;
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
    auto b = sortingWithComparator(a, true);
    print(b);

    b = sortingWithComparator(a, false);
    print(b);
}
