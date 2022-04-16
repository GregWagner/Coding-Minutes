#include <iostream>

void tower_of_hanio(int n, char from, char helper, char to) {
    if (n == 0) {
        return;
    }
    tower_of_hanio(n - 1, from, to, helper);
    std::cout << "Move " << from << " to " << to << '\n';
    tower_of_hanio(n - 1, helper, from, to);
}

int main() {
    tower_of_hanio(3, 'A', 'B', 'C');
}
