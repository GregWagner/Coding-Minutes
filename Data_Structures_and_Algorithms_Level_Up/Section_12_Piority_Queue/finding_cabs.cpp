/*
 * Given N cartesian points in a 2D plane, each representing the 
 * location of a cab. You are standing at the origin and want
 * to know the names of the nearest k cars.
 *
 * 1) Sort by euclidian distance and print the k shortest.
 * O(n) to build heap
 * O(k log n) to get the k shortest
 * 2) Make heap of size k and add only items smaller than top
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Cab {
    std::string id;
    int x;
    int y;

    Cab(std::string id, int x, int y) : id {id}, x {x}, y {y} {}

    int distance() const {
        return x * x + y * y;
    }
};

struct CabCompare {
    bool operator()(const Cab &a, const Cab &b) {
        return a.distance() < b.distance();
    }
};

void printNearestCabs(std::vector<Cab> cabs, int k) {
    // create a mix heap of size k
    std::priority_queue<Cab, std::vector<Cab>, CabCompare> max_heap(
            cabs.begin(), cabs.begin() + k);

    for (int i {k}; i < cabs.size(); ++i) {
        auto cab = cabs[i];

        if (cab.distance() < max_heap.top().distance()) {
            max_heap.pop();
            max_heap.push(cab);
        }
    }

    std::vector<Cab> output;
    while (!max_heap.empty()) {
        output.push_back((max_heap.top()));
        max_heap.pop();
    }

    std::reverse(output.begin(), output.end());
    for (auto cab : output) {
        std::cout << cab.id << '\n';
    }
}

int main() {
    std::vector<Cab> cabs {
        {"C1", 1, 1},
        {"C2", 2, 1},
        {"C3", 3, 2},
        {"C4", 0, 1},
        {"C5", 2, 3} };
    printNearestCabs(cabs, 3);
}
