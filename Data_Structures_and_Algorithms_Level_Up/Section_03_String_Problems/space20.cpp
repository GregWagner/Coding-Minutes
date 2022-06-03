/*
 * Space20
 *
 * Given a string, write a function to replace all spaces with the string
 * '%20'. It is given that the string has sufficient space at the end to
 * hold the additional characters.
 *
 * Sample Input:
 *      hello word, how are you?
 * Sample Output:
 *      hello%20world,%20%20how%20are%20you?
 *
 * Solution:
 *  Find the number of spaces in the string
 *      You will need 2 times the number of spaces
 *  From the right, shift the total number of additional spaces
 *  if you reach a space, put in %20 and deccrement the number fo additional
 *  spaces neededd
 */
#include <cstring>
#include <iostream>

void replace_space(char* str) {
    // calcullate the number of spaces
    int spaces {};
    for (int i {}; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            ++spaces;
        }
    }

    // calculate new string size
    int index = strlen(str) + (2 * spaces);
    str[index] = '\0';

    for (int i = strlen(str) - 1; i >= 0; --i) {
        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        } else {
            str[index - 1] = str[i];
            --index;
        }
    }
}

int main() {
    char input[10000];
    std::cin.getline(input, 1000);
    replace_space(input);
    std::cout << input << '\n';
}
