/* Count the number of binary strings with no
 * consecutive ones that can be formed using a
 * binary string of length n.
 *
 * n = 2 -> 00, 01, 10
 *
 * Set first 2 bits to 10 and solve subproblem
 * Set first bit to 0 and solve subproblem
 */
#include <iostream>

int countBinaryStrings(int n) {
    if (n <= 0) {
        return 1;
    }
    return countBinaryStrings(n - 2) + countBinaryStrings(n - 1);
}

int main() {
    std::cout << countBinaryStrings(2) << '\n';
    std::cout << countBinaryStrings(3) << '\n';
    std::cout << countBinaryStrings(4) << '\n';
}
