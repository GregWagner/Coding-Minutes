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
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<char>> v(n, std::vector<char>(n, 0));

  for (int i{}; i < n; i++) {
    for (int j{}; j < n; j++) {
      std::cin >> v[i][j];
    }
  }

  for (int i{}; i < n; i++) {
    for (int j{}; j < n; j++) {
      std::cout << v[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  std::vector<std::vector<int>> M(n, std::vector<int>(n, 0));

  for (int i{}; i < n; i++) {
    M[i][0] = (v[i][0] == '#' ? 1 : 0);

    if (i != 0) {
      M[i][0] += M[i - 1][0];
    }
  }

  for (int i{}; i < n; i++) {
    M[0][i] = (v[0][i] == '#' ? 1 : 0);

    if (i != 0) {
      M[0][i] += M[0][i - 1];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (v[i][j] == '#') {
        M[i][j] = 1 + M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1];
      } else {
        M[i][j] = 0 + M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1];
      }
    }
  }

  for (int i{}; i < n; i++) {
    for (int j{}; j < n; j++) {
      std::cout << M[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  int answer{};

  for (int i{}; i < n - 1; i++) {
    int s1{1}, s2{}, s3{}, s4{};
    int minimum{};

    for (int j{}; j < n - 1; j++) {
      s1 = M[i][j];
      s2 = M[i][n - 1] - M[i][j];
      s3 = M[n - 1][j] - M[i][j];
      s4 = M[n - 1][n - 1] - (s1 + s2 + s3);

      minimum = std::min({s1, s2, s3, s4});
      answer = std::max(answer, minimum);
    }
  }

  std::cout << "max of min is: " << answer << '\n';
}
