/*
 * Given a vector of pairs representing coordinates x and y of different
 * cabs on an x=y plane, sort them according to their distance from the
 * origin in non-descreasing order (i.e. the cab with the shortest
 * distance from the origin wil be first).
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

double distance(const std::pair<int, int>& v) {
    return std::sqrt(v.first * v.first + v.second * v.second);
}

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return distance(a) < distance(b);
}

std::vector<std::pair<int, int>> sortCabs(std::vector<std::pair<int, int>> v) {
    std::sort(begin(v), end(v), compare);
    return v;
}

int main() {
    std::vector<std::pair<int, int>> v = { { 2, 3 }, { 1, 2 }, { 3, 4 }, { 1, 4 } };
    auto x = sortCabs(v);
    for (const auto& s : x) {
        std::cout << s.first << ", " << s.second << '\n';
    }
}
