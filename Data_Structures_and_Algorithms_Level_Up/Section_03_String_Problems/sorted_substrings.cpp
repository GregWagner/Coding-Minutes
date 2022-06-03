/*
 * Sorted Substrings
 *
 * You are given a string and you need to print all subsequences
 * of the string sorted by length and lexicographic sorted
 * order if the length is the same.
 *
 * Sample Input:
 *      abcd
 * Sample Output
 *      a, b, c, d, ab, ac, ad, bc, bd, cd, abc, abd, acd, bcd, abcd
 *
 * Recursion then sort
 *  Make 2 recusion calls
 *      1 including the current letter
 *      1 excluding the current letter
 */
#include <algorithm>
#include <iostream>
#include <vector>

void subsequence(const std::string& s, const std::string& o,
    std::vector<std::string>& v) {
    // base case
    if (s.empty()) {
        v.push_back(o);
        return;
    }

    char ch = s[0];
    std::string reduced_input = s.substr(1);
    subsequence(reduced_input, o + ch, v);
    subsequence(reduced_input, o, v);
}

bool compare(const std::string& s1, const std::string& s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main() {
    std::string s { "abcd" };
    std::string output;
    std::vector<std::string> v;

    subsequence(s, output, v);
    std::sort(v.begin(), v.end(), compare);

    for (auto const& e : v) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
