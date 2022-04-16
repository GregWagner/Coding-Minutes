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
int visited[N][N];

int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void floodFill(int x, int y, int color) {
    a[x][y] = color;
    visited[x][y] = 1;
    for (int i {}; i < 4; ++i) {
        int xx {x + dx[i]};
        int yy {y + dy[i]};
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && 
                visited[xx][yy] == 0 && a[xx][yy] == 1) {
            floodFill(xx, yy, color);
        }
    }
}

int main() {
    int totalCount {};
    n = 6;
    m = 5;

    for (int i {}; i < n; ++i) {
        for (int j {}; j < m; ++j) {
            if (a[i][j] == 1 && visited[i][j] == 0) {
                ++totalCount;
                floodFill(i, j, totalCount);
            }
        }
    }
    std::cout << "There are " << totalCount << " separate islands\n";
    for (int i {}; i < n; ++i) {
        for (int j {}; j < m; ++j) {
            std::cout << a[i][j]  << ' ';
        }
        std::cout << '\n';
    }
}
