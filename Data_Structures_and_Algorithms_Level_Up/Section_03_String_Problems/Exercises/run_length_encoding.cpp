#include <iostream>

std::string compressString(const std::string& str) {
    std::string answer = "";

    for (size_t i {}; i < str.size(); ++i) {
        int count { 1 };
        char c = str[i];
        while (i < str.size() && str[i] == str[i + 1]) {
            ++count;
            ++i;
        }
        answer += c + std::to_string(count);
    }
    return (str.size() <= answer.size()) ? str : answer;
}

int main() {
    std::cout << std::boolalpha;
    std::string s = "bbbaaaadexxxxxx";
    std::cout << (compressString(s) == "b3a4d1e1x6") << '\n';
    s = "abc";
    std::cout << (compressString(s) == "abc") << '\n';
}
