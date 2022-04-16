#include <iostream>

size_t countBits(unsigned n) {
    size_t count {};
    while (n) {
        count += n & 1;
        n>>=1;
    }
    return count;
}

size_t countBitsFast(unsigned n) {
    size_t count {};
    while (n) {
        // remove the last set bit
        n &= n-1;
        ++count;
    }
    return count;
}

int convertToBinary(unsigned n) {
    int answer {};
    unsigned power {1};
    while (n) {
        unsigned lastBit {n & 1};
        answer += power * lastBit;
        power *= 10;
        n >>= 1;
    }
    return answer;
}

int main() {
    std::cout << std::boolalpha;

    // Even or odd
    unsigned num {14};
    std::cout << num << " is " << (num & 1 ? "odd" : "even") << '\n';

    // get the ith bit
    num = 13;
    unsigned mask {1<<2};
    std::cout << "2nd bit of " << num << " is "
        << (num & mask ? "set" : "not set") << '\n';

    // clear the ith bit
    std::cout << "When 2nd bit of " << num << " is cleared, it is "
        << (num & ~mask) << '\n';

    // set the ith bit
    num = 0;
    std::cout << "When 2nd bit of " << num << " is set, it is "
        << (num | mask) << '\n';

    // update the ith bit
    num = 0;
    std::cout << "When 2nd bit of " << num << " is changed, it is "
        << (num ^ mask) << '\n';

    // clear last i bits
    num = 0b111111111111;
    mask = (~0<<3);
    std::cout << "Clearing the last 3 bits of " << num << " is "
        << (num & mask) << '\n';

    // clear range of bits
    mask = (~0<<(5+1)) | (1<<(2-1));
    std::cout << "Clearing bits from 2 to 5 of " << num << " is "
        << (num & mask) << '\n';

    /*
     * replace bits
     * Given 2 32-bit numbers M and M and two bit position i and j,
     * write a method to set all bits between i and j in N equal to M.
     * M becomes a substring of N located at and starting at j.
     */
    unsigned N {100000000};
    unsigned M {10101};
    unsigned i {2};
    unsigned j {6};

    // first clear specified bits
    mask = (~0<<(j+1)) | (1<<(i-1));
    N &= mask;
    // set the needed bits
    mask = M<<i;
    N |= mask;
    std::cout << N << '\n';
    
    // is number a two power
    num = 15;
    std::cout << num << (num & (num-1) ? " is not" : " is")
        << " a power of 2\n";

    // count bits set
    num = 12;
    std::cout << "Number of bits set in " << num << " is "
        << countBits(num) << '\n';

    // count bits hack
    std::cout << "Number of bits set in " << num << " is "
        << countBitsFast(num) << '\n';

    std::cout << num << " in binary is " << convertToBinary(num) << '\n';
}
