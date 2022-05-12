/*
 * Implement a function that take an array of sorted 
 * integers and an integer value, and returns the lower bound of value.
 */
#include <iostream>
#include <vector>
#include <algorithm>

// 2 pointer binary search implementation (note: does not work if using
// size_t for left and right)
int lowerBound(const std::vector<int> &a, int value) {
    int answer {-1};
    int left {};
    int right = a.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (a[middle] > value) {
            right = middle - 1;
        } else {
            answer = a[middle];
            left = middle + 1;
        }
    }
    return answer;
}

// Note: this does not work
int lowerBound1(std::vector<int> A, int value) {
    auto position = std::upper_bound(A.begin(), A.end(), value);
    std::cout << position - A.begin() << '\n';
    return position - A.begin();
}

void print(const std::vector<int>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a {-1, -1, 2, 3, 5};
    print(a);
    std::cout << "Looking for 4\n";
    std::cout << (lowerBound(a, 4) == 3) << '\n';
//  std::cout << lowerBound1(a, 4) << " : should be 3\n";
//  std::cout << (lowerBound1(a, 4) == 3) << '\n';

    std::vector<int> b {1, 2, 3, 4, 6};
    print(b);
    std::cout << "Looking for 4\n";
    std::cout << (lowerBound(b, 4) == 4) << '\n';
//  std::cout << lowerBound1(b, 4) << " : should be 4\n";
//  std::cout << (lowerBound1(b, 4) == 4) << '\n';
}
