#include <iostream>
#include <stack>

int main() {
    std::stack<std::string> books;

    books.push("C++");
    books.push("Java");
    books.push("Python");
    books.push("OS");

    while (!books.empty()) {
        std::cout << books.top() << '\n';
        books.pop();
    }
}
