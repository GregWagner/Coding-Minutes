/*
 * Given a sentence, count the numer of alphabets, digits,
 * and spaces in the sentence.
 */
#include <iostream>
#include <cstring>

int main() {
    int alpha {};
    int spaces {};
    int digits {};

    auto ch  {std::cin.get()};
    while (ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            ++digits;
        } else if (ch == ' ') {
            ++spaces;
        } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            ++alpha;
        }
        ch = std::cin.get();
    }
    std::cout << "Alpha: " << alpha << "\nSpaces: " << spaces
        << "\nDigits: " << digits << '\n';
}
