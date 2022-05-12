/*
 * Count the number of set bits in a number
 */
#include <iostream>

int fast_count_bits(unsigned n) {
    int count {};
    while (n) {
        // removes the last set bit from n
        n &= n - 1;
        ++count;
    }
    return count;
}

int count_bits(unsigned n) {
    int count {};
    while (n) {
        count += n & 1;
        n = n>>1;
    }
    return count;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (count_bits(9) == 2) << '\n';
    std::cout << (fast_count_bits(9) == 2) << '\n';
}
