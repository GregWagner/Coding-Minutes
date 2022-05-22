#include <iostream>

int main() {
    size_t largestSize {};
    std::string largestString;

    std::string s;
    while (std::getline(std::cin, s)) {
        if (s.size() > largestSize) {
            largestSize = s.size();
            largestString = s;
        }
    }
    std::cout << "Largest String was " << largestString
              << ", which is " << largestSize << " characters long\n";
}
