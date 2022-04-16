/*
 * Given a running stream of character, output the 
 * first non repeating character in the string formed
 * so far after everynew character you get in input.
 * Output -1 iif such a character doesn't exist.
 *
 * a a b c c b c d
 * a -1 b b b -a -a d
 *
 * Brute force - use map to map character to frequency
 *
 * Optimal - use queue with hashmap (frequency)
 * When freq > 1 remove iif at front of queue
 */
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

std::vector<char> FindFirstNonRepeatingCharacter(std::string s) {
    std::queue<char> q;
    std::unordered_map<char, int> freq;
    std::vector<char> answer;

    for (auto c : s) {
        q.push(c);
        freq.count(c) == 0 ? freq[c] = 1 : ++freq[c];
        // remove all character from front of queue until
        // you find a character with frequency of 1
        while (!q.empty()) {
            char current = q.front();
            if (freq[current] > 1) {
                q.pop();
            } else {
                answer.push_back(current);
                break;
            }
        }
        if (q.empty()) {
            answer.push_back('0');
        }
    }
    return answer;
}

int main() {
    std::string s = "aabcbcd";
    auto answer = FindFirstNonRepeatingCharacter(s);
    for (auto e : answer) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
