/*
 * Given N sticks and an array length when length[i] represents the
 * length of each stick. Your task is to make a maximum numbber of pairs
 * of thesee sticks such that the difference between the length of 2 
 * sticks is at most D. A stick can' be part of more than one pair of sticks.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int pairSticks(vector<int> length, int D) {
    std::sort(begin(length), end(length));

    int count {};
    for (size_t i {}; i < length.size() - 1; ++i) {
        if (std::abs(length[i] - length[i + 1]) <= D) {
            ++count;
            ++i;
        }
    }
    return count;
}

void print(const std::vector<int> &a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cout << std::boolalpha;

    // 1st and 3rd, 2nd and 5th
    std::vector<int> a {1, 3, 3, 9, 4};
    print(a);
    std::cout << pairSticks(a, 2) << '\n';
    std::cout << (pairSticks(a, 2) == 2) << '\n';
}
