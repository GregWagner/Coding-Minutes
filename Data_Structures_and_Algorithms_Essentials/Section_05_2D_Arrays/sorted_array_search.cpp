/*
 * Search for an element in row wise and column wise in a 
 * sorted 2D array.
 *
 * Brute Force - search each row O(n^2)
 * Binary Search each row O(n * logn))
 * Best - staircase search )(n + m)
 *   start at last col of first row.
 *      if equal return
 *      if key < value move left
 *      if key > value move down
 */
#include <iostream>

std::pair<int, int> search(int a[][4], int n, int m, int key) {
    if (key < a[0][0] || key > a[n - 1][m - 1]) {
        return {-1, -1};
    }

    int row {};
    int col {m - 1};

    while (row < n && col >= 0) {
        std::cout << "Checking " << row << ", " << col << ": " << a[row][col] << '\n';
        if (a[row][col] == key) {
            return {row, col};
        }
        a[row][col] < key ? ++row : --col;
    }
    return {-1, -1};
}

int main() {
    int a[][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};
    auto answer = search(a, 4, 4, 33);
    std::cout << answer.first << ' '  << answer.second << '\n';
}
