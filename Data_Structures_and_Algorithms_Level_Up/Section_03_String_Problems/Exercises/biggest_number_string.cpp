#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(int a, int b) {
    std::string a_str = std::to_string(a);
    std::string b_str = std::to_string(b);

    return a_str + b_str > b_str + a_str;
}

std::string concatenate(std::vector<int> numbers) {
    std::sort(numbers.begin(), numbers.end(), cmp);

    std::string s = "";
    for (auto e : numbers) {
        s += std::to_string(e);
    }
    return s;
}

int main() {
    std::vector<int> a {10, 11, 20, 30, 3};
    std::cout << std::boolalpha << (concatenate(a) == "330201110") << '\n';
}
