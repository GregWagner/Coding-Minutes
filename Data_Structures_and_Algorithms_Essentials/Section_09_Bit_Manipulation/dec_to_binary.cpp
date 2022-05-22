#include <iostream>

int convertToBinary(int n) {
    int answer {};
    int power { 1 };
    while (n) {
        int last_bit = n & 1;
        answer += power * last_bit;
        power *= 10;
        n >>= 1;
    }
    return answer;
}

int main() {

    int n {};
    ;
    std::cin >> n;
    std::cout << convertToBinary(n) << '\n';
}
