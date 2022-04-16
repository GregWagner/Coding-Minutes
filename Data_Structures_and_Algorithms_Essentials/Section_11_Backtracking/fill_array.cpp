#include <iostream>

void printArray(int *a, int n) {
    for (int i {}; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

// note a is shared accross all function calls
void fillArray(int *a, int index, int n, int value) {
    // base case
    if (index == n) {
        printArray(a, n);
        return;
    }

    // recursive case
    a[index] = value;
    fillArray(a, index + 1, n, value + 1);

    // backtracking step (always after the recursive function call)
    a[index] = -1 * a[index];

}

int main() {
    int a[100];
    fillArray(a, 0, 5, 1);
    printArray(a, n);
}
