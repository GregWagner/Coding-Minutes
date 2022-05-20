#include <iostream>
#include <stack>

bool duplicateParentheses(std::string str) { return false; }

int main() {
    std::cout << std::boolalpha;
    std::cout << (duplicateParentheses("((a+b)+((c+d)))") == true) << '\n';
    std::cout << (duplicateParentheses("(((a+(b)))+(c+d))") == true) << '\n';
}
