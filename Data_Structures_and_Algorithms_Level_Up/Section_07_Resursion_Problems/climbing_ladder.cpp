/*
 * Climbing Ladder
 *
 * Givven a ladder containing n steps, you can take a jump 
 * of 1, 2, or 3 steps at each step. Find the number of ways
 * to climb the ladder.
 */
#include <iostream>

int countWays(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main() {
    int n;
    std::cout << "Enter number of steps: ";
    std::cin >> n;

    std::cout << "There are " << countWays(n) << " ways to reach the top.\n";
}
