/*
 * Given an array constains n numbers. All the numbers are
 * present twice except for one number which is only presennt
 * once. Find the unique number without taking any extra space
 * and in linear time.
 *
 * XOR all the values and the resulting value will be the
 * sole value
 */
#include <iostream>
#include <vector>

int xoring(std::vector<int> v) {
    int answer {};
    for (const auto& ele : v) {
        answer ^= ele;
    }
    return answer;
}

int main() {
    std::vector<int> v { 1, 2, 3, 1, 4, 2, 3 };
    std::cout << xoring(v) << '\n';
}
