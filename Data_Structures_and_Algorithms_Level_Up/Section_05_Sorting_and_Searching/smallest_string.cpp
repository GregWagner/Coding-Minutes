/*
 * Smallest String
 *
 * Given a list of n string, you'd like to concatenate
 * them together in some order such that the resulting
 * string would be lexicographically smallest.
 *
 * Sample 3 c cb cba
 * output cba cb c
 *
 * Sample 3 a ab aba
 * output a aba ab
 *
 * Need to sort and check if x + y < x + y
 */
#include <iostream>
#include <algorithm>
#include <vector>

bool compare(std::string& x, std::string& y) {
    return x + y < y + x;
}

int main() {
    std::vector<std::string> a {"a", "ab", "aba"};
    std::sort(a.begin(), a.end(), compare);

    for (auto s : a) {
        std::cout << s;
    }
    std::cout << '\n';
}


