#include <iostream>
#include <string>
#include <unordered_map>

int firstUniqChar(const std::string &s) {
    std::unordered_map<char, int> hash;

    for (auto c : s) {
        (hash.find(c) == hash.end()) ? hash[c] = 1 : ++hash[c];
    }

    for (size_t i {}; i < s.size(); ++i) {
        if (hash[s[i]] == 1) {
            return  i;
        }
    }
    return -1;
}

int main() {
    std::cout << std::boolalpha;
    std::string s = "codingminutes";
    std::cout << (firstUniqChar(s) == 0) << '\n';
    s = "aabb";
    std::cout << (firstUniqChar(s) == -1) << '\n';
}
