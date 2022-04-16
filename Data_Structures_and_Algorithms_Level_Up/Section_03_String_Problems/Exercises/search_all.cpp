/*
 * Search All!
 *
 * Implement a function that returns a list of all occurrences of a given 
 * substring inside a big string.
 * Return an emppty vector is smaller string is not present in larger string.
 *
 */
#include <string>
#include <iostream>
#include <vector>

std::vector<int> stringSearch(std::string big, std::string small) {
    std::vector<int> result;

    size_t index = big.find(small);
    while (index != std::string::npos) {
        result.push_back(index);
        index = big.find(small, index + 1);
    }
    return result;
}

int main() {
    std::string big = "I liked the movie, acting in movie was great!";
    std::string small = "movie";

    auto answer = stringSearch(big, small);
    for (auto e : answer) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
