#include <iostream>

bool isPalindrome(std::string str) {
    size_t left {};
    size_t right { str.size() - 1 };
    while (left < right) {
        if (str[left++] != str[right--]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isPalindrome("abcdcba") << '\n';
    std::cout << !isPalindrome("abcd") << '\n';
}
