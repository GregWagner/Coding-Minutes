#include <iostream>
#include <vector>

template <typename T>
bool isSorted(std::vector<T> a, int start=0) {
    if (start == a.size() - 1) {
        return true;
    }
    if (a[start] > a[start + 1]) {
        return false;
    }
    return isSorted(a, start + 1);
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a {1, 2, 3, 4, 6, 5};
    std::cout << isSorted(a) << '\n';
}
