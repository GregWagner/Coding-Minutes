/*
 * Given 2 strings, check if one string is a palindrome of the other.
 * (contains the sames character, and only the otder is different).
 */
#include <iostream>
#include <unordered_map>

bool arePermutation(const std::string& A, const std::string& B) {
    if (A.size() != B.size()) {
        return false;
    }
    std::unordered_map<char, int> hash;
    for (const auto c : A) {
        ++hash[c];
    }

    for (const auto c : B) {
        if (hash.find(c) == hash.end()) {
            return false;
        }
        --hash[c];
    }
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (arePermutation("test", "ttew") == false) <<'\n';
    std::cout << (arePermutation("abcd", "dcba") == true) <<'\n';
}
