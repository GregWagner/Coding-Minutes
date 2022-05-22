/*
 * Given N carrtesian points in a 2D plan where each represents
 * the location of a car. You are at the origin, and you want
 * to know the names of the nearest k cars.
 *
 * N = 5, K = 3
 * C1 1 1
 * C2 2 1
 * c3 3 2
 * C4 0 1
 * C5 2 3
 *
 * Output:  C4, C1, C2
 *
 * Brute Force (O(n log n + k))
 * Sort cars by distance from the origin and get the smallest k distances.
 *
 * min heap (key is the distance)
 * O(n + k log n)
 *
 * Best - O(k + (n - k) log k)
 * Build a MAX heap of size k
 * Push in k elements
 * For all the rest of the elements:
 *    If the element is smaller than the max element in the heap
 *    replace the max element with it
 */
#include <algorithm>
#include <iostream>
#include <queue>

class Car {
public:
    Car(const std::string& id, int x, int y)
        : id { id }
        , x { x }
        , y { y } {
    }

    int distance() const {
        return x * x + y * y;
    }

    std::string getId() const {
        return id;
    }

private:
    std::string id;
    int x {};
    int y {};
};

struct CarCompare {
    bool operator()(const Car& a, const Car& b) {
        return a.distance() < b.distance();
    }
};

void printNearestCars(const std::vector<Car>& cars, size_t k) {
    // create a max heap of size k
    std::priority_queue<Car, std::vector<Car>, CarCompare> maxHeap(
        cars.begin(), cars.begin() + k);

    for (size_t i { k }; i < cars.size(); ++i) {
        auto car = cars[i];
        if (car.distance() < maxHeap.top().distance()) {
            maxHeap.pop();
            maxHeap.push(car); // this will heapify
        }
    }

    std::vector<Car> results;
    while (!maxHeap.empty()) {
        results.push_back(maxHeap.top());
        maxHeap.pop();
    }
    std::reverse(begin(results), end(results));
    for (const auto& car : results) {
        std::cout << car.getId() << '\n';
    }
}

int main() {
    std::vector<Car> cars;
    cars.emplace_back("C1", 1, 1);
    cars.emplace_back("C2", 2, 1);
    cars.emplace_back("C3", 3, 2);
    cars.emplace_back("C4", 0, 1);
    cars.emplace_back("C5", 2, 3);

    printNearestCars(cars, 3);
}
