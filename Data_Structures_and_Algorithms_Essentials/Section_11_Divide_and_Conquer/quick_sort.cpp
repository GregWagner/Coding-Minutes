#include <iostream>
#include <vector>

template <typename T> T partition(std::vector<T> &a, int s, int e) {
    T pivot = a[e];
    int i = s - 1;
    for (int j{s}; j < e; ++j) {
        if (a[j] < pivot) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[e]);
    return i + 1;
}

template <typename T> void quickSort(std::vector<T> &a, int s, int e) {
    if (s >= e) {
        return;
    }

    T p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}

int main() {
    std::vector<int> a{10, 5, 2, 0, 7, 6, 4};
    quickSort(a, 0, a.size() - 1);

    for (const int x : a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
