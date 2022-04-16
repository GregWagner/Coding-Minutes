/*
 * Phone Keypad
 *
 * Given a number n and a modern phone keypad. Find
 * all possible strings generated using that number.
 *
 * 23
 * AD, AE, AF< BD< BE< BF, CD, CE, CF
 */
#include <iostream>
#include <vector>

std::vector<std::string> keypad {"", "", "ABC", "DEF", "GHI", "JKL", "MNO",
    "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(std::string input, std::string output, int index=0) {
    if (index == input.size()) {
        std::cout << output << '\n';
        return;
    } 

    int currentDigit = input[index] - '0';
    if (currentDigit == 0 || currentDigit == 1) {
        printKeypadOutput(input, output, index + 1);
    }

    for (int i {}; i < keypad[currentDigit].size(); ++i) {
        printKeypadOutput(input, output + keypad[currentDigit][i], index + 1);
    }


}

int main() {
    std::string input;
    std::cin >> input;

    std::string output;
    printKeypadOutput(input, output);
}

