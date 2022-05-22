/*
 * Given a vector of pairs of a string and an integer representing names
 * and prices of different fruits. A string is also passed as a parameter
 * with name equals either "price" meaning to sort the fruits based of
 * thir prices or name.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::pair<std::string, int>> sortFruits(std::vector<std::pair<std::string, int>> v, std::string S) {
    if (S == "price") {
        std::sort(begin(v), end(v), [](auto a, auto b) { return a.second < b.second; });
    } else {
        std::sort(begin(v), end(v), [](auto a, auto b) { return a.first < b.first; });
    }
    return v;
}

int main() {
    std::vector<std::pair<std::string, int>> a { { "Mango", 100 }, { "Guava", 70 },
        { "Grapes", 40 }, { "Apple", 60 }, { "Banana", 30 } };
    auto answer = sortFruits(a, "name");
    for (const auto& s : answer) {
        std::cout << s.first << ": " << s.second << '\n';
    }
}
