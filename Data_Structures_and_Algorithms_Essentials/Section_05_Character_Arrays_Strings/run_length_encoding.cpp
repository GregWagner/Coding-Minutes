/*
 * Run length encoding for string compression
 * If compressed string is bigger than orignal, return
 * orignal string.
 * Input:   aaabbccddee
 * Output:  a3b2c2d2e2
 *
 * Input:   abcd
 * Output:  abcd
 */
#include <iostream>
#include <sstream>

std::string compressString(std::string s) {
    size_t n = s.length();

    std::ostringstream output;
    for (size_t i {}; i < n; ++i) {
        size_t count { 1 };
        while ((i < n - 1) && (s[i] == s[i + 1])) {
            ++count;
            ++i;
        }
        output << s[i] << count;
    }

    return (n < output.str().length() ? s : output.str());
}

int main() {
    std::string s1 { "aaabbccddee" };
    std::cout << compressString(s1) << '\n';

    std::string s2 { "abcd" };
    std::cout << compressString(s2) << '\n';
}
