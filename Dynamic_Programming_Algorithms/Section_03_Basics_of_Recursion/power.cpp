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
int fastPower(int a, int n) {
    if (n == 0) {
        return 1;
    }

    int temp = fastPower(a, n / 2);
    temp *= temp;
    return (n & 1 ? a * temp : temp);
}

int main() {
    std::cout << power(2, 3) << '\n';
    std::cout << fastPower(2, 3) << '\n';
}
