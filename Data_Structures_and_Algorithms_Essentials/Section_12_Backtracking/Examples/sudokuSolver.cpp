/*
 * Given a partially fiilled Sudoku matrix of 9x9,
 * write a function to fill the matrix using Sudoku Rules.
 */
#include <iostream>

void printSolution(int mat[][9], int n = 9) {
    for (int i {}; i < n; ++i) {
        for (int j {}; j < 9; ++j) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool isSafe(int mat[][9], int i, int j, int number, int n = 9) {
    // check the row and column
    for (int k {}; k < n; ++k) {
        if (mat[k][j] == number || mat[i][k] == number) {
            return false;
        }
    }

    // find the starting row and column of the subgrid that
    // this cell belongs to
    int sx { (i / 3) * 3 };
    int sy { (j / 3) * 3 };

    for (int x { sx }; x < sx + 3; ++x) {
        for (int y { sy }; y < sy + 3; ++y) {
            if (mat[x][y] == number) {
                return false;
            }
        }
    }
    return true;
}

bool solveSodoku(int mat[][9], int row, int col, int n = 9) {
    // if done with all rows
    if (row == n) {
        return true;
    }

    // go to the next row if we are at the last column
    if (col == n) {
        return solveSodoku(mat, row + 1, 0);
    }

    // skip if the col is already filled
    if (mat[row][col] != 0) {
        return solveSodoku(mat, row, col + 1);
    }

    // at this point we are at a cell that needs to be filled.
    // try out all possibilities
    for (int number { 1 }; number <= n; ++number) {
        if (isSafe(mat, row, col, number)) {
            mat[row][col] = number;
            if (solveSodoku(mat, row, col + 1)) {
                return true;
            }
        }
        // try the next number
    }
    // need to backtrack
    mat[row][col] = 0;
    return false;
}

int main() {
    int mat[9][9] { { 5, 3, 0, 0, 7, 0, 0, 0, 0 }, { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
        { 0, 9, 8, 0, 0, 0, 0, 6, 0 }, { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
        { 4, 0, 0, 8, 0, 3, 0, 0, 1 }, { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
        { 0, 6, 0, 0, 0, 0, 2, 8, 0 }, { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
        { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

    if (!solveSodoku(mat, 0, 0)) {
        std::cout << "No solution exists!\n";
    } else {
        printSolution(mat);
    }
}
