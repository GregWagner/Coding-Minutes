/*
 * Given coordinates of N points on X-Y axis, your task is to sort them
 * accordance to the x-corrdinate. If the x-coordinates are the same
 * then compare y-coordinates.
 */
#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, int> &a, const std::pair<int, int>& b) {
    if (a.first == b.first) {
        return (a.second < b.second);
    }
    return a.first < b.first;
}

std::vector<std::pair<int, int>> sortingWithComparator(std::vector<std::pair<int, int>> v)
{
    std::sort(begin(v), end(v), compare);
    return v;
}

template <typename T>
void print(const std::vector<T> &a) {
    for (const auto& ele : a) {
        std::cout << '(' << ele.first << ", " << ele.second << ')' << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::pair<int, int>> a {{3, 4}, {2, 3}, {3, 7}, {1, 5}, {3, 4}};
    auto b = sortingWithComparator(a);
    print(b);
}
