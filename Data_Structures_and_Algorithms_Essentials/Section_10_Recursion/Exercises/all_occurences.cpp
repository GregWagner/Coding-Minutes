#include <iostream>
#include <vector>

std::vector<int> findAllOccurences1(int k, std::vector<int> v) {
    std::vector<int> answer;
    for (size_t i {}; i < v.size(); ++i) {
        if (v[i] == k) {
            answer.push_back(i);
        }
    }
    return answer;
}

void findHelper(int key, const std::vector<int> in, int index,
    std::vector<int>& out) {
    if (index == in.size()) {
        return;
    }
    if (in[index] == key) {
        out.push_back(index);
    }
    findHelper(key, in, index + 1, out);
}

std::vector<int> findAllOccurences(int k, std::vector<int> v) {

    std::vector<int> results;

    findHelper(k, v, 0, results);

    return results;
}

int main() {
    std::vector<int> a { 1, 2, 5, 3, 1, 2, 3, 8, 6, 3, 6, 7, 9, 3 };
    auto answer = findAllOccurences(3, a);
    for (const auto ele : answer) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
