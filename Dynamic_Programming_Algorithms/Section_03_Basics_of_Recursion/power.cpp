/*
 * Write a function to find the power of a number, 
 * both number and power are given as inputs.
 */
#include <iostream>

int power(int a, int n) {
    if (n == 0) {
        return 1;
    }
    return a * power(a, n - 1);
}

// O(log n) space and time
int fast_power(int a, int n) {
    if (n == 0) {
        return 1;
    }

    int temp = fast_power(a, n / 2);
    temp *= temp;
    if (n & 1) {
        // n is odd
        return a * temp;
    }
    return temp;
}

int main() {
    std::cout << power(2, 3) << '\n';
    std::cout << fast_power(2, 3) << '\n';
}
