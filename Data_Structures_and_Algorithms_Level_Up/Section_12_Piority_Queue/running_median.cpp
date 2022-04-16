/*
 * Given a running stream of integer, output the median
 * (middle number) of numbers read so far after every input.
 */
#include <iostream>
#include <queue>
#include <functional>
#include <vector>

int main() {
    std::priority_queue<int> leftHeap; // max heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> rightHeap; // min heap

    std::vector<int> a {5, 2, 3, 0, 12, 18, 20, 22};  
    leftHeap.push(10);
    float median {10};
    std::cout << median << '\n';

    for (auto data : a) {
        if (leftHeap.size() > rightHeap.size()) {
            if (data < median) {
                // rebalance
                rightHeap.push(leftHeap.top());
                leftHeap.pop();

                leftHeap.push(data);
            } else {
                rightHeap.push(data);
            }
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        } else if (leftHeap.size() == rightHeap.size()) {
            if (data < median) {
                leftHeap.push(data);
                median = leftHeap.top();
            } else {
                rightHeap.push(data);
                median = rightHeap.top();
            }
        } else {
            if (data < median) {
                leftHeap.push(data);
            } else {
                // reblance
                leftHeap.push(rightHeap.top());
                rightHeap.pop();

                rightHeap.push(data);
            }
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        std::cout << median << '\n';
    }
}
