/*
 * Find the first occurence of an element in an array
 */
#include <iostream>
#include <vector>

template <typename T>
int first_occurence(std::vector<T> a, T key, int index=0) {
    if (index == a.size()) {
        return -1;
    }
    if (a[index] == key) {
        return index;
    }
    return first_occurence(a, key, index + 1);
}

int main() {
    std::vector<int> a {1, 7, 5, 7, 6, 2};
    int key {7};
    std::cout << first_occurence(a, key) << '\n';
}
