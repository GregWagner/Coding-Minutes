/*
 * Unique String
 *
 * Given a string, write a function to find the largest
 * substring with unique characters (no duplicates)
 *
 * Sample Input:
 *      prateekbhaiya
 *      aabcb
 * Output
 *      ekbhaiy
 *      abc
 *
 * Brute Force 
 *
 * Optimze by storing the last occurence of the current charactter
 * Move left and if the character @ j+1 is part of the window, start
 * a new window. Otherwise include it in the window (i.e. expand your
 * current window) and move left.
 * - need a hashmap to keep track of characters in current window
 *
 * Example
 * a b c a e b a
 * a b c            3
 *   b c a e        4
 *     c a e b      4
 *       a e b      3
 *         e b a    3
 *           b a    2
 *             a    1
 */
#include <iostream>
#include <unordered_map>

std::string uniqueSubstring(const std::string &str) {
    size_t i {};
    size_t j {};
    size_t windowLength {};
    size_t maxWindowLength {};
    int windowStart {-1};
    std::unordered_map<char, size_t> hash; 

    while (j < str.size()) {
        char c = str[j];

        // check if this character is part of the current window
        if (hash.count(c) != 0 && hash[c] >= i) {
            // start a new window at the location after the duplicaate character
            i = hash[c] + 1;
            windowLength = j - i;   // exclude the current character it will be included below
        }
        hash[c] = j;
        ++windowLength;
        ++j;

        if (windowLength > maxWindowLength) {
            maxWindowLength = windowLength;
            windowStart = i;
        }
    }
    return str.substr(windowStart, maxWindowLength);
}

int main() {
    std::string input {"abcaeba"};

    std::cout << uniqueSubstring(input) << '\n';
}

