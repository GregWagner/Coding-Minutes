/*
 * Order by length and the alphabetically
 */
#include <algorithm>
#include <iostream>
#include <vector>

void findSubsets(char *input, char *output, std::vector<std::string> &list,
                 int i = 0, int j = 0) {
    // base case
    if (input[i] == '\0') {
        output[j] = '\0';
        list.emplace_back(output);
        return;
    }

    // include the ith letter in the output
    output[j] = input[i];
    findSubsets(input, output, list, i + 1, j + 1);

    // backtracking case
    // exclude the ith letter in the output (overwrite output[j])
    findSubsets(input, output, list, i + 1, j);
}

int main() {
    std::vector<std::string> list;
    char output[100];
    char input[] = "abc";

    findSubsets(input, output, list);

    std::sort(begin(list), end(list), [](std::string &a, std::string &b) {
        return (a.length() == b.length() ? a < b : a.length() < b.length());
    });
    for (const auto &ele : list) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
