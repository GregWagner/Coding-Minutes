#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <typename T>
class Heap {
public:
    Heap(int defaultSize = 10) {
        v.resize(defaultSize + 1);
        v.push_back(-1); // index 0 not used
    }

    // O(log n)
    void push(int data) {
        // add to the end of the heap
        v.push_back(data);

        // perculate up to correct place
        int index { v.size() - 1 };
        int parent { index / 2 };
        while (index > 1 && v[index] < v[parent]) {
            std::swap(v[index], v[parent]);
            index = parent;
            parent /= 2;
        }
    }

    // get the minimum node
    T top() const {
        return v[1];
    }

    // remove the minimum node
    void pop() {
        std::swap(v[1], v[v.size() - 1]);
        v.pop_back();

        heapify(1); // fix the heap
    }

    bool empty() {
        return v.size() == 1;
    }

private:
    std::vector<T> v;

    // O(log n)
    void heapify(int index) {
        int left { 2 * index };
        int right { left + 1 };
        int minIndex { index };
        if (left < v.size() && v[left] < v[index]) {
            minIndex = left;
        }
        if (right < v.size() && v[right] < v[minIndex]) {
            minIndex = right;
        }

        if (minIndex != index) {
            std::swap(v[index], v[minIndex]);
            heapify(minIndex);
        }
    }
};

#endif
