/*
 * This is an exercisee
 * Given a sorted array and a number, find a pair in the
 * array whose sum is closest t x.
 */
#include <iostream>
#include <vector>
#include <climits>

// brute force
std::pair<int, int> closestSum1(const std::vector<int> &arr, int x) {
    int difference {9999};
    int first {};
    int second {};
    for (size_t i {}; i < arr.size(); ++i) {
        for (size_t j {i + 1}; j < arr.size(); ++j) {
            int sum {arr[i] + arr[j]};
            if (std::abs(sum - x) < difference) {
                difference = std::abs(sum - x);
                first = i;
                second = j;
            }
        }
    }
    return {arr[first], arr[second]};
}

// two pointer
std::pair<int, int> closestSum(const std::vector<int> &arr, int x) {
    int difference {INT_MAX};
    int first {};
    int second {};

    int left {};
    int right = arr.size() - 1;
    while (right > left) {
        int sum = arr[left] + arr[right];
        if (std::abs(sum - x) < difference) {
            difference = std::abs(sum - x);
            first = left;
            second = right;
            ++left;
        } else {
            --right;
        }
    }
    return {arr[first], arr[second]};
}


int main() {
    std::cout << std::boolalpha;

    std::vector<int> a = {10, 22, 28, 29, 30, 40};
    auto answer = closestSum(a, 54);
    std::cout << answer.first << ", " << answer.second << '\n';
    std::cout << (answer.first == 22 && answer.second == 30) << '\n';
}
