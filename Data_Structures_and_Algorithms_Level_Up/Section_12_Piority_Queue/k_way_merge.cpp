/*
 * Merge k sorted arrays to produce a single sorted array with the
 * same elements.
 * k-way merges are used in external sorting procedures. External
 * sorting algorithms are a class of sorting algorithms that can
 * handle massive amounts of data.
 *
 * 1) Combine into single array and then sort
 * 2) Use min heap to find the minimum of k elements
 */
#include <iostream>
#include <queue>
#include <functional>
#include <vector>

std::vector<int> mergeKArrays(std::vector<std::vector<int>> arrays) {
    size_t k {arrays.size()};

    // store element, element index, and array index
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
        std::greater<std::vector<int>>> heap;

    std::vector<int> output;

    for (size_t i {}; i < k; ++i) {
        heap.push({arrays[i][0], i, 0});
    }

    // start poping and pushing more elements
    while (!heap.empty()) {
        auto top = heap.top();
        heap.pop();

        int element = top[0];
        int a_index = top[1];
        int e_index = top[2];

        output.push_back(element);

        if (e_index + 1 < arrays[a_index].size()) {
            heap.push({arrays[a_index][e_index + 1], a_index, e_index + 1});
        }
    }
    return output;
}

int main() {
    std::vector<std::vector<int>> a {
        {10, 15, 20, 30},
        {2, 5, 8, 14, 24},
        {0, 11, 60, 90} };

    auto results = mergeKArrays(a);
    for (auto x : results) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
