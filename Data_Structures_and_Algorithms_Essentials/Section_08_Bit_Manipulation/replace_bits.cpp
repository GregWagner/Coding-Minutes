/*
 * Given 2 32 bit numbers (n and m) and 2 bits positions (i and j),
 * write a method to set all bits between i and j in n equal to m.
 * m becomes a substring of N located at and starting at j.
 *
 * Example:
 *  n = 10000000000;
 *  m = 10101;
 *  i = 2; j = 6
 *  output 1001010100
 *
 *      65432
 *  10000000000
 *      10101
 *  -----------
 *  10001010100
 */
#include <iostream>

void clearBitsInRange(unsigned &n, unsigned i, unsigned j) {
    unsigned a = (~0)<<(j + 1);
    unsigned b = (1<<i) - 1;
    unsigned mask = a | b;
    n &= mask;
}

void replaceBits(unsigned& n, unsigned i, unsigned j, unsigned m) {
    clearBitsInRange(n, i, j);
    // or in m that is shiftd i times
    n |= m<<i;
}

int main() {
    unsigned n {15};
    replaceBits(n, 1, 3, 2);
    std::cout << n << '\n';
}
