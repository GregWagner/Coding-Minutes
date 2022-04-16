#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Helper function
bool outOfOrder(const std::vector<int> &a, int i) {
    int x {a[i]};

    // handle if looking at the first element in array
    if (i == 0) {
        return x > a[1];
    }

    // handle if looking at the last element in array
    if (i == static_cast<int>(a.size() - 1)) {
        return a[i - 1] > x;
    }

    return a[i - 1] > x || x > a[i + 1];
}

int subarrySort(std::vector<int> a) {
    int smallest {INT_MAX};
    int largest {INT_MIN};

    for (size_t i {}; i < a.size(); ++i) {
        int currentValue {a[i]};
        if (outOfOrder(a, i)) {
            smallest = std::min(smallest, currentValue);
            largest = std::max(largest, currentValue);
        }
    }

    // check if all elements were sorted
    if (smallest == INT_MAX) {
        return 0;
    }

    // now find the right index where the smallest and largest are
    int left {};
    while (smallest > a[left]) {
        ++left;
    }
    int right {static_cast<int>(a.size() - 1)};
    while (largest <= a[right]) {
        --right;
    }
    return std::abs(left - right) + 1;
}

int main() {          //0  1  2  3  4  5  6  7  8  9   10
    std::vector<int> a1 {2, 6, 4, 8, 10, 9, 15};
    std::vector<int> a {1};

    std::cout << subarrySort(a) << '\n';
}
