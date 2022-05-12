/*
 * Spiral Print
 * Write a function that takes in an nxm 2D array and prints
 * all array element in spiral order. Start from top let corner
 * and goes to the right, then procees in a spiral pattern until
 * every elemment is visisted.
 *
 * 1  2  3  4
 * 5  6  7  8
 * 9  10 11 12
 * 13 14 15 16
 *
 * 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 *
 * ToDo: Check if odd number of rows/columns works
 */
#include <iostream>

void print(int a[][4], int rows, int cols) {
  int startingRow{};
  int endingRow{rows - 1};
  int startingCol{};
  int endingCol{cols - 1};

  while ((startingCol <= endingCol) && (startingRow <= endingRow)) {
    // print upper row
    for (int col{startingCol}; col <= endingCol; ++col) {
      std::cout << a[startingRow][col] << ' ';
    }

    // print right column
    for (int row{startingRow + 1}; row <= endingRow; ++row) {
      std::cout << a[row][endingCol] << ' ';
    }

    // print lower row
    for (int col{endingCol - 1}; col >= startingCol; --col) {
      // avoid  duplicate printing of elements
      if (startingRow != endingRow) {
        std::cout << a[endingRow][col] << ' ';
      }
    }

    // print left colum
    for (int row{endingRow - 1}; row >= startingRow + 1; --row) {
      // avoid  duplicate printing of elements
      if (startingCol != endingCol) {
        std::cout << a[row][startingCol] << ' ';
      }
    }

    ++startingRow;
    --endingRow;
    ++startingCol;
    --endingCol;
  }
  std::cout << '\n';
}

int main() {
  int a[][4] = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};

  print(a, 4, 4);
}
