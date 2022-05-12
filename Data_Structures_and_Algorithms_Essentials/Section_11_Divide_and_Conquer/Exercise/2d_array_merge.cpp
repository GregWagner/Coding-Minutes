/*
 * Implemennt merge sort for 1 2D array. In case of
 * off dimeennsion, the first givision contains
 * more numbers than the second one. The complete
 * execution of merge sort arranges the elements in
 * increasing order either moving row-wise or
 * column-wise
 */
#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>> &a) {
    for (const auto &v : a) {
        for (const auto &e : v) {
            std::cout << e << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

std::vector<std::vector<int>> mergeSort(int m, int n,
                                        std::vector<std::vector<int>> v) {
    return {};
}

int main() {
    std::vector<std::vector<int>> a{
        {18, 4, 16, 8}, {23, 13, 20, 11}, {28, 24, 26, 25}, {1, 30, 15, 19}};
    auto answer = mergeSort(4, 4, a);
    printMatrix(answer);

    std::vector<std::vector<int>> b{{18, 9, 11}, {1, 4, 15}, {13, 23, 20}};
    answer = mergeSort(3, 3, b);
    printMatrix(answer);
}
