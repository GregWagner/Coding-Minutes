/*
 * Write a function to check if a number is odd or even
 */
#include <iostream>

int main() {
    int x { 2 };
    std::cout << x << (((x & 1) == 1) ? " is odd" : " is even") << '\n';
    std::cout << x << (((x & 1) == 0) ? " is even" : " is odd") << '\n';

    x = 33;
    std::cout << x << (((x & 1) == 1) ? " is odd" : " is even") << '\n';
    std::cout << x << (((x & 1) == 0) ? " is even" : " is odd") << '\n';
}
