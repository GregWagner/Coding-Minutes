#include <iostream>
#include <vector>

std::vector<std::vector<int>> printPascal(int n) {
    std::vector<std::vector<int>> answer;

    std::vector<int> newRow;
    answer.push_back(newRow);
    answer[0].push_back(1);

    for (int row { 1 }; row < n; ++row) {
        std::vector<int> newRow;
        answer.push_back(newRow);
        for (int col {}; col < row; ++col) {
            if (col == 0) {
                // std::cout << "1 Row: " << row << ", Col: " << col << ": 1\n";
                answer[row].push_back(1);
            } else {
                int nextValue { answer[row - 1][col - 1] + answer[row - 1][col] };
                // std::cout << "2 Row: " << row << ", Col: " << col << ": " <<
                // nextValue
                // << '\n';
                answer[row].push_back(nextValue);
            }
        }
        if (row != 0) {
            // std::cout << "3 Row: " << row << ": 1\n";
            answer[row].push_back(1);
        }
    }
    return answer;
}

int main() {
    auto answer { printPascal(5) };

    std::cout << "-----------------------------\n";
    for (const auto& row : answer) {
        for (const auto& col : row) {
            std::cout << col << ' ';
        }
        std::cout << '\n';
    }
}
