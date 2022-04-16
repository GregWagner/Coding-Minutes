/*
 * Given:
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 
 * swap along diagonal:
 * 1 4 7
 * 2 5 8
 * 3 6 9
 *
 * i j
 * 0,1  1,0  2, 4
 * 0 2  2,0  3, 7
 * 1 2  2,1  8, 6
 * 
 * reverse each row:
 * 7 4 1
 * 8 5 2
 * 9 6 3
 */
#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size();
    for (size_t i {}; i < n; ++i) {
        for (size_t j {}; j < i; ++j) {
//          std::cout << "Swapping " << matrix[i][j] << " and " << matrix[j][i] << '\n';
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (size_t i {}; i < n; ++i) {
        std::reverse(begin(matrix[i]), end(matrix[i]));
    }
}

int main() {
    std::vector<std::vector<int>> a {{1, 2, 3},
        {4, 5, 6}, {7, 8, 9}};
    rotate(a);
    for (const auto& e : a) {
        for (const auto &b : e) {
            std::cout << b << ' ';
        }
        std::cout << '\n';
    }
}
