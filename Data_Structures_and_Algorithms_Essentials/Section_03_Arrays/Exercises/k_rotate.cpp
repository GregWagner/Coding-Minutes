/*
 * This is an exercise
 * Given an integer, vector, and a value k, rotate the array
 * k times clockwise;
 */
#include <iostream>
#include <vector>

std::vector<int> kRotate(const std::vector<int> &a, int k) {
    std::vector<int> answer (a.size());
    for (size_t i {}; i < a.size(); ++i) {
        int newIndex = (i + k) % a.size();
//      std::cout << "Moving " << i  << " to " << newIndex << '\n';
        answer[newIndex] = a[i];
    }
    return answer;
}

void print(const std::vector<int>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a {1, 3, 5, 7, 9};
    auto answer = kRotate(a, 2);
    print(answer);
}
