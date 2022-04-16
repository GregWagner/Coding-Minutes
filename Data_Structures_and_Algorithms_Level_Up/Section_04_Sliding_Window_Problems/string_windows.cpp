/*
 * String Window
 * Given 2 strings, one big string and one small string, find the smallest window
 * in the big string that contains all the ccharaccters of the small string. 
 *   - Window can have additional chanacters
 *   - If small string has duplicates, then those duplicates must be present with
 *     the same or higher count.
 * Input:
 *      s1 = helo_world             fizzbuzz        <= string
 *      s2 = lol                    fuzz            <= pattern
 * Output:
 *      llo                         fizzbu
 *
 * Need to create a frequency map of the patteern
 * if pattern = ocl then frequency map is
 *      o   1
 *      e   1
 *      l   1
 * Start going to the left on the big string one character at a time. and maintain
 * a hashmap of your window and check if the pattern is in the window. Once that
 * is found, look for the smallest window by moving from the start and removing
 * characters that aren't in the pattern. Once your window does not include the
 * pattern, restart expannding from the end.
 * Expansion then contraction
 */
#include <cstdint>
#include <iostream>
#include <vector>

std::string find_window(const std::string &s, const std::string &pattern) {
    const int MAX_COUNT {256};
    // using array as a frequencce map
    std::vector<int> FP(MAX_COUNT, 0);
    std::vector<int> FS(MAX_COUNT, 0);

    for (auto const &c : pattern) {
        FP[c]++;
    }

    // sliding window algorithm
    size_t count {};
    int start {};        // to use for left contracction
    int startIndex {-1}; // starting index for best window so far
    size_t minSoFar {INT16_MAX};

    for (size_t i {}; i < s.size(); ++i) {
        char c = s[i];
        // expand the window by including current character
        FS[c]++;

        // count how many characters have been matched till now
        if (FP[c] != 0 && FS[c] <= FP[c]) {
            ++count;
        }

        // check if all characters in the pattern have been matched
        // in the current window. If so, then start contracting
        if (count == pattern.size()) {
            // start contracing from the left to remove unneeded characters
            // Note: an unneeded character is either not in the pattern or
            //       the frequency is higher than required
            while (FP[s[start]] == 0 || FS[s[start]] > FP[s[start]]) {
                --FS[s[start]];
                ++start;
            }
            // at this poiint count is still equal to pattern.size() since
            // we only removed characters that were not needed
            size_t windowSize = i - start + 1;
            if (windowSize < minSoFar) {
                minSoFar = windowSize;
                startIndex = start;
            }
        }
    }
    if (startIndex == -1) {
        return "No window found";
    }
    return s.substr(startIndex, minSoFar);
}

int main() {
    std::string s1 {"hello"};
    std::string s2 {"eo"};
    std::cout << find_window(s1, s2) << '\n'; // ello

    s1 = "fizzbuzz";
    s2 = "fuzz";
    std::cout << find_window(s1, s2) << '\n';
}
