#include <iostream>

void towerOfHanio(int n, char from, char helper, char to) {
    if (n == 0) {
        return;
    }
    towerOfHanio(n - 1, from, to, helper);
    std::cout << "Move " << from << " to " << to << '\n';
    towerOfHanio(n - 1, helper, from, to);
}

int main() {
    towerOfHanio(3, 'A', 'B', 'C');
}
