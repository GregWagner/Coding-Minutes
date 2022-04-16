/*
 * Given a string without spaces and a list of words, find
 * the minimum bars to be added to the string so that
 * all resulting words are found in the list.
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

int minBarsHelper(const std::string &s,
        const std::vector<std::string> &words, int index, 
        const std::unordered_set<std::string> &m) {
    if (s[index] == '\0') {
        return 0;
    }
    int answer = INT_MAX;
    std::string currentString = "";
    for (int j = index; s[j] != '\0'; ++j) {
        currentString += s[j];

        // at every string, check if prefix is present
        if (m.find(currentString) != m.end()) {
            int remainingAnswer = minBarsHelper(s, words, j + 1, m);
            if (remainingAnswer != -1) {
                answer = std::min(answer, 1 + remainingAnswer);
            }
        }
    }
    return (answer == INT_MAX ? -1 : answer);
}

int minBars(const std::string &s, const std::vector<std::string> &words) {
    std::unordered_set<std::string> m (words.begin(), words.end());
    
    return minBarsHelper(s, words, 0, m) - 1;
}

int main() {
    std::cout << std::boolalpha;

    std::string s = "thequickbrownfox";
    std::vector<std::string> words {"the", "quickbrown", "fox",
        "quick", "brown"};
    std::cout << (minBars(s, words) == 2) << '\n';

    s = "thequickbrownfoxjumpsoverthehighbridge";
    std::vector<std::string> words1 {"the", "fox", "thequickbrownfox",
        "jumps", "lazy", "lazyfox", "highbridge", "the", "over", "bridge",
        "high", "tall", "quick","brown"};
    std::cout << (minBars(s, words1) == 4) << '\n';
}
