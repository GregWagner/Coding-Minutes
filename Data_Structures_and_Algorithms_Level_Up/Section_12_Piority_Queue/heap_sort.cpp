#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main() {
    int a[] {10, 15, 20, 13, 6, 90};
    std::priority_queue<int> heap;
    //std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

    for (int x : a) {
        heap.push(x);
    }

    while (!heap.empty()) {
        std::cout << heap.top() << ' ';
        heap.pop();
    }
    std::cout << '\n';
}
