/*
 * Given a string, find all permutations of the string.
 *
 * input  abc
 * output abc, acb, bac, bca, cab, cba
 *
 * There will be 6! permutations
 */
#include <iostream>

void findPermutations(std::string &s, size_t i = 0) {
    // base case
    if (i == s.length() - 1) {
        std::cout << s << '\n';
        return;
    }

    for (size_t j{i}; j < s.length(); ++j) {
        std::swap(s[i], s[j]);
        // recursive call
        findPermutations(s, i + 1);

        // backtracking step (restore orginal string)
        std::swap(s[i], s[j]);
    }
}

int main() {
    std::string s{"abc"};
    findPermutations(s);
}
