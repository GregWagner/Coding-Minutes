/*
 * Write a function which collects daily price quotes
 * for some stock and returns the span of that stock's
 * price. The span of the stock's price today is defined as
 * thhe maximum nummber of consecutive days (starting from
 * today and going backwards) for which the price of the
 * stock was less than*  or equal to roday's price.`
 */
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> stockSpanner(std::vector<int>& stocks) {
    std::vector<int> answer(stocks.size(), 1);
    std::stack<int> s; // store indices o the days
    s.push(0);

    for (size_t i { 1 }; i < stocks.size(); ++i) {
        //  find the previous highest
        while (!s.empty() && stocks[s.top()] <= stocks[i]) {
            s.pop();
        }

        answer[i] = (s.empty() ? i + 1 : i - s.top());
        s.push(i);
    }
    return answer;
}

int main() {
    std::vector<int> a { 100, 80, 60, 70, 60, 75, 85 };
    auto answer = stockSpanner(a);
    for (const auto& e : answer) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
