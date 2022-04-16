/*
 * Given an MxN grid, find the number of
 * ways to reach the bottom right corner 
 * starting from the top left. At each cell 
 * you can move right or down
 *
 * At each cell, there are 2 sub-problems.
 * Going right and going down.
 * f(x, y) = f(x + 1, y) + f(x, y + 1)
 *
 * Note: There is a math trick to this. Calculate
 * the number of permutations of m-1 + n-1 moves.
 *    (m + n - 2)!
 * -----------------
 *  (m - 1)!(n - 1)!
 */
#include <iostream>

int gridWays(int i, int j, int m, int n) {
    // base case - at the bottom right
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    if (i >= m || j >= m) {
        return 0;
    }
    return gridWays(i + 1, j, n, m) + gridWays(i, j + 1, n, m);
}

int main() {
    std::cout << gridWays(0, 0, 3, 3) << '\n';
}
