#include <iostream>

long long fact(long long n) {
    if (n <= 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
    std::cout << fact(5) << '\n';
}
