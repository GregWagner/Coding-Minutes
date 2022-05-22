#include <iostream>
#include <queue>

class Stack {
public:
    void push(int x) {
        // insert item in the non empty queue
        q1.empty() ? q2.push(x) : q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            // shift the elements from q2 to q1
            while (!q2.empty()) {
                int item = q2.front();
                q2.pop();
                // don't put last item on the other queue
                if (q2.empty()) {
                    break;
                }
                q1.push(item);
            }
        } else {
            // shift the elements from q1 to q2
            while (!q1.empty()) {
                int item = q1.front();
                q1.pop();
                // don't put last item on the other queue
                if (q1.empty()) {
                    break;
                }
                q2.push(item);
            }
        }
    }

    int top() {
        if (q1.empty()) {
            // shift the elements from q2 to q1
            while (!q2.empty()) {
                int item = q2.front();
                q1.push(item);
                q2.pop();
                if (q2.empty()) {
                    return item;
                }
            }
        } else {
            // shift the elements from q1 to q2
            while (!q1.empty()) {
                int item = q1.front();
                q1.pop();
                q2.push(item);
                if (q1.empty()) {
                    return item;
                }
            }
        }
        return -1;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    std::queue<int> q1;
    std::queue<int> q2;
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << '\n';
}
