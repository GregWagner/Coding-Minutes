// difference is only changing location of 1 line
#include <iostream>

void dec(int n) {
    if (n == 0) {
        return;
    }
    std::cout << n << " ";
    dec(n - 1);
}

void inc(int n) {
    if (n == 0) {
        return;
    }
    inc(n - 1);
    std::cout << n << " ";
}

int main() {
    dec(5);
    std::cout << "-------------\n";
    inc(5);
    std::cout << '\n';
}
