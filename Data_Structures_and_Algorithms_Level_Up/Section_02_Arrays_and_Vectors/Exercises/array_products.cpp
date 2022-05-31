
/*
 * Array Products
 * Implement a fucntion that takes in a vector of integer and returns a
 * vector of the same length where each element in the output array is
 * equl to the product of every other number in the input array.
 * Solve this problem without using division.
 */
#include <iostream>
#include <vector>

// Expected Complexity O(N)
std::vector<int> productArray(const std::vector<int>& arr) {
    // Create an output Array
    int n = arr.size();
    std::vector<int> output(n, 1);

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            if (i != j) {
                output[j] *= arr[i];
            }
        }
    }
    return output;
}

int main() {
    std::vector<int> a { 1, 2, 3, 4, 5 };
    auto answer = productArray(a);
    for (auto ele : answer) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
