#include <iostream>

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

std::string vowel(std::string S) {
    std::string answer;
    for (const auto c : S) {
        if (isVowel(c)) {
            answer += c;
        }
    }
    return answer;
}

int main() {
    std::cout << vowel("awbgidoggua") << '\n';
}
