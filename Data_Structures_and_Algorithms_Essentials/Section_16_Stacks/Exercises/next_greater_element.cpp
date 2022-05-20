#include <iostream>
#include <stack>
#include <vector>

std::vector<int> nextGreaterElement(std::vector<int> v) {
    std::stack s;
    std::vector<int> answer(v.size());

    return answer;
}

int main() {
    std::vector<int> a{4, 5, 2, 25};
    auto answer = nextGreaterElement(a);
    for (const auto &e : answer) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
