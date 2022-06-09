/*
 * Example 1
 * Compute factorial of a number
 */
#include <iostream>

long factorial(long n) {
    if (n <= 1) {
        return n;
    }
    return n * factorial(n - 1);
}

int main() {
    std::cout << "5! = " << factorial(5) << '\n';
}
