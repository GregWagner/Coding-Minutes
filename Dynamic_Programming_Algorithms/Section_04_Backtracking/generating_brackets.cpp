/*
 * Generating brackets
 *
 * Write a function to generate all possible n pairs of balancced
 * parentheses '(' and ')'
 */
#include <iostream>

void generateBrackets(std::string output, int n, int open=0, int close=0, int index=0) {
    if (index == 2 * n) {
        std::cout << output << '\n';
        return;
    }

    if (open < n) {
        generateBrackets(output + '(', n, open + 1, close, index + 1);
    }
    if (close < open) {
        generateBrackets(output + ')', n, open, close + 1, index + 1);
    }
}

int main() {
    std::string output;
    generateBrackets(output, 4);
}
