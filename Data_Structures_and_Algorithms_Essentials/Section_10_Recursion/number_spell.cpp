/*
 * Given a number like 2021, convert it into a string like:
 * two zero two one
 */
#include <iostream>
#include <vector>

void convertInteger(int n) {
    static std::vector<std::string> spell {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};

    if (n == 0) {
        return;
    }
    convertInteger(n / 10);
    std::cout << spell[n % 10] << ' ';
}

int main() {
    convertInteger(1234);
    std::cout << '\n';
}
