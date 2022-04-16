/*
 * Given an n x m binary matrix
 * How many total islands are possible
 */
#include <iostream>

// globals
const int N = 100;
int a[N][N] = {
    {0, 0, 0, 1, 1},
    {0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
};
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void floodFill(int x, int y) {
    a[x][y] = 0;
    for (int i {}; i < 4; ++i) {
        int xx {x + dx[i]};
        int yy {y + dy[i]};
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == 1) {
            floodFill(xx, yy);
        }
    }
}

int main() {
    int totalCount {};
    n = 6;
    m = 5;

    for (int i {}; i < n; ++i) {
        for (int j {}; j < m; ++j) {
            if (a[i][j] == 1) {
                ++totalCount;
                floodFill(i, j);
            }
        }
    }
    std::cout << "There are " << totalCount << " separate islands\n";
}
