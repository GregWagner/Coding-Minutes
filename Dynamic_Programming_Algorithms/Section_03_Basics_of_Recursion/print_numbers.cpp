/*
 * Example 4
 * Print number 1...n recursively in
 *    * Decreasing order
 *    * Increasing order
 *
 * Note: only one line is swapped between the 2
 */
#include <iostream>

void printIncreasing(int n) {
    if (n == 0) {
        return;
    }
    printIncreasing(n - 1);
    std::cout << n << ' ';
}

void printDecreasing(int n) {
    if (n == 0) {
        return;
    }
    std::cout << n << ' ';
    printDecreasing(n - 1);
}

int main() {
    printIncreasing(5);
    std::cout << "\n----------------\n";
    printDecreasing(5);
}
