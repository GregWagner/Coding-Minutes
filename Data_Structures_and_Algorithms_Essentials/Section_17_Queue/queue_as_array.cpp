#include <iostream>

class Queue {
public:
    Queue(int defaultSize = 5)
        : maxSize(defaultSize)
        , rear { defaultSize - 1 } {
        arr = new int[maxSize];
    }

    ~Queue() {
        delete[] arr;
    }

    bool full() const {
        return currentSize == maxSize;
    }

    bool empty() const {
        return currentSize == 0;
    }

    void push(int data) {
        if (full()) {
            std::cerr << "Queue is full\n";
            return;
        }
        // move the rear pointer to the next index
        rear = (rear + 1) % maxSize;
        arr[rear] = data;
        ++currentSize;
    }

    void pop() {
        if (empty()) {
            std::cerr << "Queue is empty\n";
            return;
        }
        // move the front pointer forward
        front = (front + 1) % maxSize;
        --currentSize;
    }

    int getFront() {
        if (empty()) {
            std::cerr << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

private:
    int* arr;
    int currentSize {};
    int maxSize {};

    int front {};
    int rear {};
};

int main() {
    Queue q(7);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    q.pop();
    q.pop();
    q.push(10);

    while (!q.empty()) {
        std::cout << q.getFront() << '\n';
        q.pop();
    }
}
