/*
 * Find the last occurence of an element in an array
 *
 * Check the subproblem first
 */
#include <iostream>

int lastOccurance(int a[], int n, int key) {
    if (n == 0) {
        return -1;
    }

    int subIndex = lastOccurance(a + 1, n - 1, key);
    if (subIndex == -1) {
        if (a[0] == key) {
            return 0;
        }
        return -1;
    }
    return subIndex + 1;
}

int main() {
    int a[] { 1, 7, 5, 7, 6, 2 };
    int n = sizeof(a) / sizeof(int);
    int key { 7 };
    std::cout << lastOccurance(a, n, key) << '\n';
}
