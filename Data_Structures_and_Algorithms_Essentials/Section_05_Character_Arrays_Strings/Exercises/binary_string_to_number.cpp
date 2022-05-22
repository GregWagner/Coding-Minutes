#include <algorithm>
#include <iostream>

int binaryToDecimal(std::string s) {
    int result {};
    int multiplier { 1 };
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '1') {
            result += multiplier;
        }
        multiplier *= 2;
    }

    return result;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (binaryToDecimal("111") == 7) << '\n';
    std::cout << (binaryToDecimal("1100") == 12) << '\n';
}
