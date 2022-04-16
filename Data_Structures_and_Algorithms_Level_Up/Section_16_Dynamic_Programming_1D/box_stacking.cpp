/*
 * Given an array of boxes where each box is represented using 3
 * innteger denoting height, width, and depth of the box. The goal
 * is to stack up the boxes and maximuse the total height of the 
 * stack.
 *
 * You can't rotate any box (i.e. the integers in each box must
 * represent the width, depth, and height at all times.)
 *
 * A box must have strictly smaller width,, depth, and heigh
 * than any other boxes below it.
 */
#include <iostream>
#include <vector>
#include <algorithm>

bool canPlace(const std::vector<int> &a, const std::vector<int> &b) {

    return a[0] > b[0] && a[1] > b[1] && a[2] > b[2];
}

int boxStacking(std::vector<std::vector<int>> &boxes) {
    // sort by height
    std::sort(boxes.begin(), boxes.end(), [](std::vector<int> a, std::vector<int>b) {
            return a[2] > b[2]; });
    
    size_t n = boxes.size();
    std::vector<int> dp(n + 1, 0);

    for (int i {}; i < n; ++i) {
        dp[i] = boxes[i][2]; // set as hight of the ith box
    }

    for (int i {1}; i < n; ++i) {
        // check all boxes whose index is less than i
        for (int j {}; j < i; ++j) {
            if (canPlace(boxes[j], boxes[i])) {
                int currentHeight = boxes[i][2];
                dp[i] = std::max(dp[i], dp[j] + currentHeight);
            }
        }
    }
    int maxHeight {};
    for (int i {}; i < n; ++i) {
        maxHeight = std::max(maxHeight, dp[i]);
    }
    return maxHeight;
}

int main() {
    std::vector<std::vector<int>> boxes {
        {2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4},
        {2, 2, 1}, {4, 4, 5}};

    std::cout << std::boolalpha;
    std::cout << (boxStacking(boxes) == 10) << '\n'; 
    std::cout << boxStacking(boxes) << '\n'; 
}
