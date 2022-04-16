/*
 * Given a 4xn board and tiles of size 4x1, count
 * the number of ways to tile the given board using
 * the 4x1 tiles.
 *
 * A tile can either be placed horizontally (as a 1x4 tile)
 * or vertically (as a 4x1 tile)
 */
#include <iostream>

int tile(int n) {
    if (n <= 3) {
        return 1;
    }
    return tile(n - 1) + tile(n - 4);
}
