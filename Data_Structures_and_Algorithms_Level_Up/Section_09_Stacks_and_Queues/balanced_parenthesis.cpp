/*
 * Given an expression string, write a program to check
 * all pairs of parenthesis are valid.
 */
#include <iostream>
#include <stack>

bool valid(std::string& str) {
    std::stack<char> s;
    for (auto c : str) {
        switch(c) {
            case '(':
            case '[':
            case '{':
                s.push(c);
                break;

            case ')':
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    return false;
                }
                break;

            case '}':
                if (!s.empty() && s.top() == '{') {
                    s.pop();
                } else {
                    return false;
                }
                break;

            case ']':
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    return false;
                }
                break;

            default:
                break;
        }
    }
    return s.empty();
}

int main() {
    std::cout << std::boolalpha;
    std::string s = "((a+b) * x - d)";
    std::cout << valid(s) << '\n';
    std::string s1 = "((a + b] + c) * (d - e)";
    std::cout << !valid(s1) << '\n';
}
