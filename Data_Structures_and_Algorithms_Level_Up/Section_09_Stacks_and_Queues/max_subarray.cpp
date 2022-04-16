/*
 * Given an array and an integer k, find the max for
 * each and every contiguouous subarray of size k
 */
#include <iostream>
#include <vector>
#include <deque>

void maxSubArray(std::vector<int> a, int k) {
    std::deque<int> q(k);   // store indexes

    // Process the first K elements
    for (int i {}; i < k; ++i) {
        // remove if we receive a larger element
        while (!q.empty() && a[i] > a[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    // Process the remaining elements
    for (int i {k}; i < a.size(); ++i) {
        std::cout << a[q.front()] << ' ';
        // remove elements fro the left when index is outside window
        while (!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        while (!q.empty() && a[i] >= a[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a {1, 2, 3, 1, 4, 5, 2, 3, 5};
    maxSubArray(a, 3);
}
