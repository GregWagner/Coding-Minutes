// This is not working fully

#include <iostream>

std::string breakPalindrome(std::string palindrome) {
    if (palindrome.size() == 0) {
        return "";
    }

    std::string answer = "";
    for (size_t i {}; i < palindrome.size(); ++i) {
        if (palindrome[i] == 'a') {
            answer += "a";
        } else {
            char c =  char(palindrome[i] - 1);
            answer += c + palindrome.substr(i);
            return answer;
        }
    }
    return "";
}

int main() {
    std::cout << std::boolalpha;
    std::string s = "abccba";
    std::cout << (breakPalindrome(s) == "aaccba") << '\n';
    s = "a";
    std::cout << (breakPalindrome(s) == "") << '\n';
    s = "b";
    std::cout << (breakPalindrome(s) == "a") << '\n';
    std::cout << breakPalindrome(s) << '\n';
}
