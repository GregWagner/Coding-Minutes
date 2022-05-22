/*
 * Given an integer N, return an integer vector containing number
 * from 1 to N in increasing order.
 */
#include <iostream>
#include <vector>

std::vector<int> increasingNumbers(int N) {
    std::vector<int> results;
    for (int i { 1 }; i <= N; ++i) {
        results.push_back(i);
    }
    return results;
}

int main() {
    std::vector<int> answer = increasingNumbers(5);
    for (auto const ele : answer) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
