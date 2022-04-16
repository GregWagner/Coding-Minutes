/*
 * Maximize the min
 *
 * Brute Force (O(n^4))
 * Make a cut at every i, j and then compute the number of trees in 
 * each quadrant and find the max
 *
 * Using 2D Prefix Sums O(n^2)
 * Maximum the minimum
 * Create an auxilary matrix and let M[x, y] be the # of mano trees in
 * the rectangle between (0,0) and (x, y). You can calculate M[x, y] as
 * follows:
 *                                    /-> don't count common trees
 *  M[x, y] = M[x-1, y] + M[x, y-1] - M[x-1, y-1]
 *  Then add 1 if there is a tree at (x, y)
 *
 * Thus, M[x,y] is the number of mango trees in the top left rectangle
 * formed by the cut. Using M[x,y], we can also calculate the number of
 * mango trees in the top right and bottom left rectangles defined by (x,y).
 *
 * Top left rectange:
 *  M[x, y]           : Number of mangos in rectange defined by (0, 0)
 *                      and (x, y)
 * Top right rectange:
 *  M[x, N] - M[x, y] : Number of mangos in rectangle defined by (0, N)
 *                      and (x, y)
 * Bottom left rectangle:
 *  M[N, y] - M[x, y] : Number of mangos in rectangle defined by (x, y)
 *                      and (N, 0)
 * Bottom right rectange:
 *  M[N, N] - Top Left - Top Right - Bottom righ
 *
 * Finally, we subtract these three quantities from total number of mango
 * trees to get number of mangos in fourth rectangle (bottom right), defined
 * by (x,y) and (N,N).
 */
#include <iostream>

int main() {

}
