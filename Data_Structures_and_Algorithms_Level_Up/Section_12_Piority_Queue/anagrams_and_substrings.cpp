/*
 * 2 strings are anagrams of each other if the letters
 * of one string can be rearranged to form te other string.
 * Given a string, find the number of paris of substrings
 * of the string that are anagrams of each other.
 *
 * Create a frequency map of the hash of each substring.
 */
#include <iostream>
#include <vector>
#include <map>

std::vector<int> geetHashValue(const std::string &s, int i, int j) {
    std::vector<int> freq(26, 0);

    for (int k {i}; k <= j; ++k) {
        ++freq[s[k] - 'a'];
    }
    return freq;
}

int anagramsSubstrings(std::string s) {
    std::map<std::vector<int>, int> m;

    // Generate all substring
    for (size_t i {}; i < s.length(); ++i) {
        for (size_t j {i}; j < s.length(); ++j) {
            // generate the hash
            auto hash = geetHashValue(s, i, j);
            // hash the hash values to club all anagrams
            // into a single bucket
            ++m[hash];
        }
    }

    // from freq count, count the pairs
    int answer {};
    for (auto p : m) {
        int freq {p.second};
        if (freq >= 2) {
            answer += (freq) * (freq - 1) / 2;
        }
    }
    return answer;
}


int main() {
    std::cout << std::boolalpha;
    std::string s1 = "abba";
    std::cout << (anagramsSubstrings(s1) == 4) <<'\n';
    s1 = "abcd";
    std::cout << (anagramsSubstrings(s1) == 0) <<'\n';
}
