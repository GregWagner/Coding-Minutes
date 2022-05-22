#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int>& s, int data) {
    if (s.empty()) {
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(temp);
}

void reverseStack(std::stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << '\n';
}

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    std::cout << "Insert At Bottom\n";
    insertAtBottom(s, 99);
    printStack(s);

    std::cout << "Reverse\n";
    reverseStack(s);
    printStack(s);
}
