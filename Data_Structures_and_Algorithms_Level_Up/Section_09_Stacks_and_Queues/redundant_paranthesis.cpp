/*
 * Given a string of balanced expressions, find if it 
 * contains redundat parenthese or not. A set of parentheses
 * are redundant if the same sub-expression is surrounded by
 * unnecessary or multiple brackets.
 */
#include <iostream>
#include <stack>

bool checkRedundant(std::string str) {
    std::stack<char> s;

    for (auto c : str) {
        if (c != ')' && c != ' ') {
            s.push(c);
        } else if (c == ')') {
            bool operatorFound {}; 
            while (!s.empty() && s.top() != '(') {
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;
                }
                s.pop();
            }
            s.pop();   // eat opening bracket
            if (!operatorFound) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::string s1 = "((a + b))";
    std::cout << checkRedundant(s1) << '\n';
    std::string s2 = "(a + (b) / c)";
    std::cout << checkRedundant(s2) << '\n';
    std::string s3 = "(a + b * (c - d))";
    std::cout << !checkRedundant(s3) << '\n';
}
