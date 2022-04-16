/*
 * Given N ropes each having a different size, join the ropes
 * together. The cost of joining 2 rops of different size x and
 * y is (x + y). Find the mimumum cost to join all the ropes
 * together.
 *
 * Greedy - join smallest ropes
 */
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int joinRopes(const std::vector<int> &a) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap (a.begin(), a.end());

    int cost {};
    while (heap.size() > 1) {
        int firstRope = heap.top();
        heap.pop();
        int secondRope = heap.top();
        heap.pop();
        cost += firstRope + secondRope;
        heap.push(firstRope + secondRope);
    }
    return cost;
}

int main() {
    std::vector<int> a {4, 3, 2, 6};
    std::cout << std::boolalpha;
    std::cout << (joinRopes(a) == 29) << '\n';
}
