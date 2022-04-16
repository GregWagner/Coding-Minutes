/*
 * Example 4
 * Print number 1...n recursively in 
 *    * decreasing order
 *    * Increasing order
 *
 * Note: only one line is swapped between the 2
 */
#include <iostream>
#include <vector>

void print_increasing(int n) {
    if (n == 0) {
        return;
    }
    print_increasing(n - 1);
    std::cout << n << ' ';

}

void print_decreasing(int n) {
    if (n == 0) {
        return;
    }
    std::cout << n << ' ';
    print_decreasing(n - 1);
}

int main() {
    print_increasing(5);
    std::cout << "\n----------------\n";
    print_decreasing(5);
}
