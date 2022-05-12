/*
 * Given n friends, each one can remain single or can
 * be paired up with some other friend. Each friend
 * can be paired only once. Find the total number of
 * ways in which friends can remain single or can be
 * paried up.
 */
#include <iostream>

int friendsPairing(int n) {
    if (n <= 2) {
        return n;
    }
    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (friendsPairing(3) == 4) << '\n';
}
