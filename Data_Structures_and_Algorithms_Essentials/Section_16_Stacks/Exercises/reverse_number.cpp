#include <iostream>
#include <stack>

int reverse(int n) {
    std::stack<int> s;
    while (n) {
        s.push(n % 10);
        n /= 10;
    }

    int result {};
    int mult { 1 };
    while (!s.empty()) {
        int temp = s.top() * mult;
        result += temp;
        s.pop();
        mult *= 10;
    }
    return result;
}

int main() {
    std::cout << reverse(456) << '\n';
}
