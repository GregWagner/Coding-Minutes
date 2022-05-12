/*
 * Given an integer N, print all binary strings of
 * size N without consecutive ones.
 *
 * Brute force - generate all binary strings then
 * remove the invalid ones
 */
#include <iostream>
#include <vector>

void helper(std::vector<std::string> &a, int n) {
    if (n == 0) {
        return;
    }
}

std::vector<std::string> binaryStrings(int n) {
    std::vector<std::string> a;
    helper(a, n);
    return a;
}

int main() {
    auto answer = binaryStrings(3);
    for (const auto &value : answer) {
        std::cout << value << '\n';
    }
}
