#include <vector>
#include <iostream>

std::vector<std::vector<int>> makeZeroes(std::vector<std::vector<int>> arr) {
    std::vector<size_t> rows;
    std::vector<size_t> cols;
    // find and save the rows and columns with zeros.
    for (size_t i {}; i < arr.size(); ++i) {
        for (size_t j {}; j < arr[i].size(); ++j) {
            if (arr[i][j] == 0) {
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }

    for (size_t i {}; i < rows.size(); ++i) {
        size_t row = rows[i];
        for (size_t j {}; j < arr[0].size(); ++j) {
            arr[row][j] = 0;
        }
    }
    for (size_t i {}; i < cols.size(); ++i) {
        size_t col = cols[i];
        for (size_t j {}; j < arr.size(); ++j) {
            arr[j][col] = 0;
        }
    }


    return arr;
}

int main() {
    std::vector<std::vector<int>> a {{5, 4, 3, 9}, 
        {2, 0, 7, 6}, {1, 3, 4, 0}, {9, 8, 3, 4}};
    auto answer = makeZeroes(a);
    for (const auto &s : answer) {
        for (const auto &x : s) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }

}
