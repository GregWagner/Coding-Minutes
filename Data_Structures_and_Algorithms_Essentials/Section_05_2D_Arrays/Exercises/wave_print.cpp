/*
 * Give a matrix, print in Reverse Wave Form
 */

#include <iostream>
#include <vector>

std::vector<int> print(int arr[][4], int n, int m) {
    int lastRow {n - 1};
    int col {m - 1};
    std::vector<int> result;

    while (col >= 0) {
        // last colum done
        for (int i {}; i <= lastRow; ++i) {
            result.push_back(arr[i][col]);
        }
        --col;
        if (col < 0) {
            break;
        }

        // next colum up
        for (int i {lastRow}; i >= 0; --i) {
            result.push_back(arr[i][col]);
        }
        --col;
    }
    return result;
}

int main() {
    int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8},
        {9, 10, 11, 12}, {13, 14, 15, 16}};
    auto answer = print(a, 4, 4);
    for (const auto ele : answer) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
