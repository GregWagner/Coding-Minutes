/*
 * a^n
 * convert n to binary representation
 * For example 8^5 = 8^101
 * 1 * 8^1 + 8^4
 */
#include <iostream>

// O(log(n))
int fastExpo(int a, int n) {
    int answer {1};
    while (n) {
        int last_bit = n & 1;
        if (last_bit) {
            answer *= a;
        }
        a *= a;    // square the number
        n >>= 1;
    }
    return answer;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (fastExpo(3, 5) == 243) << '\n';
}

