/*
 * Given a string, find alll subsets (i.e. subsequence not substring)
 * of the given string.
 *
 * Brute force requires 2 recursive calls
 *
 * input  abc
 * output "", a, b, c, ab, ac, bc, abc
 *
 * for each character
 * Include the character and exclude the character
 */
#include <iostream>

void findSubsets(char* input, char* output, int i = 0, int j = 0) {
    // base case
    if (input[i] == '\0') {
        output[j] = '\0';
        std::cout << output << '\n';
        return;
    }

    // recursive cases

    // include the ith letter in the output
    output[j] = input[i];
    findSubsets(input, output, i + 1, j + 1);

    // backtracking case
    // exclude the ith letter in the output (overwrite output[j])
    findSubsets(input, output, i + 1, j);
}

int main() {
    char output[100];
    char input[] = "abc";

    findSubsets(input, output);
}
