/*
 * Check Subsets
 *
 * Given 2 non-empty strings, write a function that determines if the second
 * string is a subsequence of the first one.
 *
 * Sample Input:
 *  codingminutes
 *  cines
 * Output
 *  Yes
 *
 * Solution
 * Use 2 pointers. One going through S1 and one through S2
 */
#include <iostream>

std::string isSubsets(const std::string& s1, const std::string& s2) {
    int i = s1.size() - 1;
    int j = s2.size() - 1;

    while (i >= 0 && j >= 0) {
        //      std::cout << "Checking: " << s1[i] << " and " << s2[j] << '\n';
        if (s1[i] == s2[j]) {
            --j;
        }
        --i;
    }
    return (j < 0 ? "yes" : "no");
}

int main() {
    std::string s1 = "coding minutes";
    std::string s2 = "cines";

    std::cout << isSubsets(s1, s2) << '\n';
}
