#include <iostream>

std::string normalize(const std::string &sentence) {
    std::string copy = "";

    bool firstLetter = true;
    for (char c : sentence) {
        if (firstLetter && c != ' ') {
            copy += std::toupper(c);
            firstLetter = false;
        } else if (c == ' ') {
            copy += ' ';
            firstLetter = true;
        } else {
            copy += std::tolower(c);
        }
    }
    return copy;
}

int main() {
    std::string s = "This is SO MUCH FUN!";
    std::cout << normalize(s) << '\n';
    s = "   abc   def   ghi  ";
    std::cout << normalize(s) << '\n';
}
