#include <iostream>
#include <queue>

int main() {
    int arr[] {10, 15, 20, 13, 6, 90};
    int n {sizeof(arr) / sizeof(int)};

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int> maxHeap;

    for (auto x : arr) {
        minHeap.push(x);
        maxHeap.push(x);
    }

    std::cout << "Min Heap:\n";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << '\n';
        minHeap.pop();
    }
    std::cout << "Max Heap:\n";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << '\n';
        maxHeap.pop();
    }
}
