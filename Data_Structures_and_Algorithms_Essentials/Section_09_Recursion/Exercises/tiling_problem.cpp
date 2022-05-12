/*
 * Given N tiles of size 1xM. There is a floor of size
 * NXM which you have to cover with tiles. Find the
 * number of ways the floor can be completly covered
 * if you can place the tiles in both horizonal and
 * vertical manner.
 */
#include <iostream>

int tillingProblem(int n, int m) {
    // base case
    if (n < m) {
        return 1;
    }

    return tillingProblem(n - 1, m) + tillingProblem(n - m, m);
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (tillingProblem(4, 3) == 3) << '\n';
}
