/*
 * Find the last occurence of an element in an array
 */
#include <iostream>
#include <vector>

template <typename T>
int last_occurence(std::vector<T> a, T key, int index) {
    if (index < 0) {
        return -1;
    }
    if (a[index] == key) {
        return index;
    }
    return last_occurence(a, key, index - 1);
}

int main() {
    std::vector<int> a {1, 7, 5, 7, 6, 2};
    int key {7};
    std::cout << last_occurence(a, key, a.size() - 1) << '\n';
}
