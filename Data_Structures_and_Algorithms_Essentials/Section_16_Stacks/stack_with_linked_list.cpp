#include <iostream>

template <typename T>
class Node {
public:
    explicit Node(T data)
        : data { data }
        , next {} {
    }

    T data;
    Node<T>* next;
};

template <typename T>
class Stack {
public:
    void push(T data) {
        auto node = new Node<T>(data);
        node->next = head;
        head = node;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    T top() {
        return head->data;
    }

    void pop() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node<T>* head {};
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
