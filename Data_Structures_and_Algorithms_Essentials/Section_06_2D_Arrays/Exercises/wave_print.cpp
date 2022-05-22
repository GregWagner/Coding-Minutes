/*
 * Give a matrix, print in Reverse Wave Form
 */
#include <iostream>
#include <vector>

std::vector<int> WavePrint(int m, int n, std::vector<std::vector<int>> arr) {
    int lastRow { n - 1 };
    int col { m - 1 };
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
        for (int i { lastRow }; i >= 0; --i) {
            result.push_back(arr[i][col]);
        }
        --col;
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> a { { 1, 2, 3, 4 }, { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
    auto answer = WavePrint(4, 4, a);
    for (const auto ele : answer) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';

    std::vector<std::vector<int>> b { { 1, 9, 4, 10 }, { 3, 6, 90, 11 },
        { 2, 30, 85, 72 }, { 6, 31, 99, 15 } };
    answer = WavePrint(4, 4, b);
    for (const auto ele : answer) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
