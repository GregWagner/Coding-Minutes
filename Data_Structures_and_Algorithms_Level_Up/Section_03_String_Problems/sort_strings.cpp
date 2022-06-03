/*
 * Sort Strings
 *
 * Given a list of n strings, each containing digits and spaces, and the number of
 * spaces are the same for each entry, te goal is to implement a varation of the
 * sort command. None of the strings contain consecutive spaces. Also no strings
 * starts with a space nor ends with one. Spaces are used to divide strings into
 * columns, which can be used as keys in comparisons.
 *
 * The program has to support these parameters:
 *  key: integer denoting the column used as a key in comparisons. The left most
 *      column is denoted by 1.
 *
 *  reversed: boolean variable indicating whether to reverse the results.
 *
 *  comparison-type: either lexicongraphic or numeric. Lexicographic 122 < 13)
 *      numeric means we compare the strings by thier numerical values (13 < 122).
 *      If the type is numerica and numeric values of keys of Si and Sj are equal
 *      this Si is considered strickly smaller since it commes first.
 *
 * Sample Input:
 * 3
 * 92 022
 * 82 12
 * 77 13
 * 2 false numeric
 *
 * Output
 * 82 12
 * 77 13
 * 92 022
 *
 * Logic:
 * 1) Extract keys from eveery string using tokenization and save as
 *      pair(string, key)
 * 2) Do the sort
 * 3) Reverse if needed
 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

std::string extractStringAtKey(std::string& str, int key) {
    std::stringstream ss(str);
    std::string token;
    while (key--) {
        std::getline(ss, token, ' ');
    }
    return token;
}

int main() {
    int n {};
    std::cin >> n;
    std::cin.get(); // eat the extra /n

    std::vector<std::string> a;
    for (int i {}; i < n; ++i) {
        std::string temp;
        std::getline(std::cin, temp);
        a.push_back(temp);
    }

    int key {};
    std::string reversal;
    std::string ordering;
    std::cin >> key >> reversal >> ordering;

    // extract the key for comparision
    std::vector<std::pair<std::string, std::string>> pairs;
    for (auto s : a) {
        pairs.emplace_back(s, extractStringAtKey(s, key));
    }

    // sort
    if (ordering == "numeric") {
        std::sort(pairs.begin(), pairs.end(),
            [](auto const& a, auto const& b) {
                return std::stoi(a.second) < std::stoi(b.second);
            });
    } else {
        std::sort(pairs.begin(), pairs.end(),
            [](auto const& a, auto const& b) { return a.second < b.second; });
    }

    // reverse if needed
    if (reversal == "true") {
        std::reverse(pairs.begin(), pairs.end());
    }

    // output the strings
    for (auto const& p : pairs) {
        std::cout << p.first << '\n';
    }
}
