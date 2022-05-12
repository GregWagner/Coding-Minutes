/*
 * For each group of consecutive repeating characters:
 *  If the groups length is 1, append the character to s
 *  Otherwise append the character followed by the gourp's length
 *
 * Return the length of the new string and replace the input string
 * with the resuts.
 */
#include <iostream>
#include <vector>

int compress(std::vector<char>& chars) {
    std::vector<char> output;
    for (size_t i {}; i < chars.size(); ++i) {
        auto ch {chars[i]};
        int count {1};
        while (chars[i + 1] == ch) {
            ++count;
            ++i;
        }
        output.push_back(ch);
        output.push_back(std::to_string(count)[0]);
    }
    chars.clear();

    for (const auto& c : output) {
        chars.push_back(c);
    }
    return chars.size();
}

void print(std::vector<char>& chars) {
    for (const auto& c : chars) {
        std::cout << c << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<char> a {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    std::cout << compress(a) << '\n';
    print(a);
}
