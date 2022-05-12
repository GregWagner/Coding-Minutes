#include <iostream>
#include <vector>

void printVector(const std::vector<int> &a, int n) {
    for (int i {}; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

// note a is shared accross all function calls
void fillVector(std::vector<int> &a, int index, int n, int value) {
    // base case
    if (index == n) {
        printVector(a, 5);
        return;
    }

    // recursive case
    a[index] = value;
    fillVector(a, index + 1, n, value + 1);

    // backtracking step (always after the recursive function call)
    a[index] = -1 * a[index];

}

int main() {
    std::vector<int> a(100);
    fillVector(a, 0, 5, 1);
    printVector(a, 5);
}
