#include <iostream>
#include <vector>

template <typename T>
class Node {
    public:
        explicit Node (T data): data(data), next {} {}

        T data;
        Node<T> *next;
};

template <typename T>
class Stack {
    public:
        void push(T data) {
            head.emplace_back(data);
        }

        bool isEmpty() {
            return head.empty();
        }

        T top() {
            return head.back();
        }

        void pop() {
            head.pop_back();
        }

    private:
        std::vector<T> head;
};

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    while (!stack.isEmpty()) {
        std::cout << stack.top() << '\n';
        stack.pop();
    }
}

