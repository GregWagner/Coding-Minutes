#include <iostream>
#include <vector>

std::vector<int> findAllOccurences(int k, std::vector<int> v){
    std::vector<int> answer;
    for (size_t i {}; i < v.size(); ++i) {
        if (v[i] == k) {
            answer.push_back(i);
        }
    }
    return answer;
}

int main() {
    std::vector<int> a {1, 2, 5, 3, 1, 2, 3, 8, 6, 3, 6, 7, 9};
    auto answer = findAllOccurences(3, a);
    for (const auto ele : answer) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
