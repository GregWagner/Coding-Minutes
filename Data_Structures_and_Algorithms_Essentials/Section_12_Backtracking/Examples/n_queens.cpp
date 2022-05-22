/*
 * Place N cheess queens on an NxN chessboard
 * so that no two queens attack each other.
 *
 * On failure, backtrack to previous row and try next column
 *
 * Possible variables
 * - print one configuration
 * - print all configurations
 * - count the number of possible configurations
 */
#include <iostream>

void printBoard(int n, int board[][20]) {
    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool validSpot(int n, int board[][20], int x, int y) {
    // check columns
    for (int k {}; k < x; ++k) {
        if (board[k][y]) {
            return false;
        }
    }

    // check left diagonal
    int i { x };
    int j { y };
    while (i >= 0 && j >= 0) {
        if (board[i][j]) {
            return false;
        }
        --i;
        --j;
    }

    // right diagonal
    i = x;
    j = y;
    while (i >= 0 && j < n) {
        if (board[i][j]) {
            return false;
        }
        --i;
        ++j;
    }
    return true;
}

int countSolveNQueen(int n, int board[][20], int row = 0) {
    // base case
    if (row == n) {
        return 1;
    }

    // recursive case - try to place a queen in every row
    int count {};
    for (int col {}; col < n; ++col) {
        if (validSpot(n, board, row, col)) {
            board[row][col] = 1;
            count += countSolveNQueen(n, board, row + 1);

            // need to backtrack - i.e. try next column
            board[row][col] = 0;
        }
    }
    return count;
}

bool solveNQueen(int n, int board[][20], int row = 0) {
    // base case
    if (row == n) {
        printBoard(n, board);
        return true;
    }

    // recursive case - try to place a queen in every row
    for (int col {}; col < n; ++col) {
        if (validSpot(n, board, row, col)) {
            board[row][col] = 1;
            if (solveNQueen(n, board, row + 1)) {
                return true;
            }

            // need to backtrack - i.e. try next column
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[20][20] {};
    solveNQueen(10, board);
    int board1[20][20] {};
    std::cout << "Count: " << countSolveNQueen(8, board1) << '\n';
}
