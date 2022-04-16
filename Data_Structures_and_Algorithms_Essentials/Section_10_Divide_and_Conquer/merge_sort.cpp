#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T> &a, int startingIndex, int endingIndex) {
    int i {startingIndex};
    int m {(startingIndex + endingIndex) / 2};
    int j {m + 1};

    std::vector<T> temp;

    while (i <= m && j <= endingIndex) {
        if (a[i] < a[j]) {
            temp.push_back(a[i++]);
        } else {
            temp.push_back(a[j++]);
        }
    }

    // copy the remaning elements
    while (i <= m) {
        temp.push_back(a[i++]);
    }
    while (j <= endingIndex) {
        temp.push_back(a[j++]);
    }

    // copy back to orginal array
    for (int k {}, i {startingIndex}; i <= endingIndex; ++i, ++k) {
        a[i] = temp[k];
    }
}

template <typename T>
void mergeSort(std::vector<T> &a, int startingIndex, int endingIndex) {
    if (startingIndex >= endingIndex) {
        return;
    }

    int middleIndex = (startingIndex + endingIndex) / 2;
    mergeSort(a, startingIndex, middleIndex);
    mergeSort(a, middleIndex + 1, endingIndex);

    merge(a, startingIndex, endingIndex);
}

int main() {
    std::vector<int> a {10, 5, 2, 0, 7, 6, 4};
    mergeSort(a, 0, a.size() - 1);
    for (auto const &ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
