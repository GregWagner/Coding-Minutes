/*
 * String Tokenization
 *
 * Tokenizing a string denotes splitting a string with
 * respect to some delimiter(s) like white space.
 */
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>

void usingSstream() {
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);

    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    for (auto const &e : tokens) {
        std::cout << e << ", ";
    }
    std::cout << '\n';
}

/*
 * strtok internally maintains the state of the string you
 * passed in
 */
void usingStrtok() {
    char input[1000];
    std::cin.getline(input, 1000);

    char* token = std::strtok(input, " ");
    while (token) {
        std::cout << token << '\n';
        token = std::strtok(nullptr, " ");
    }
}

char *mystrtok(char *str, char delimiter) {
    static char* input = nullptr;
    if (str) {
        input = str;
    }
    if (!input) {
        return nullptr;
    }

    int i {};
    char *token = new char[strlen(input) + 1];
    while (input[i] != '\0') {
        if (input[i] != delimiter) {
            token[i] = input[i];
        } else {
            token[i] = '\0';
            // update static value
            input = input + i + 1;
            return token;
        }
        ++i;
    }
    token[i] = '\0';
    input = nullptr;
    return token;
}

int main() {
//  usingSstream();
   usingStrtok();

}
