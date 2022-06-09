/*
 * Given n friends who want to go to a party, each one
 * can remain single or can be paired up with somme other
 * friend. Each friend can be paired only once. Found out
 * the total number of ways of which friends can remain single
 * or can be paired up.
 *
 * For 3 friends:
 * A, AB+C, AC+B, BC+A > 4
 * f(n - 1) + (n - 1) * f(n - 2)
 */
#include <iostream>

int pair(int n) {
    if (n <= 1) {
        return 1;
    }
    return pair(n - 1) + (n - 1) * pair(n - 2);
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (pair(1) == 1) << '\n';
    std::cout << (pair(2) == 2) << '\n';
    std::cout << (pair(3) == 4) << '\n';
}
