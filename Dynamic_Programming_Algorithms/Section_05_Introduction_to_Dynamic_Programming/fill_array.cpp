/*
 * What is the number of ways to fill an array with
 * 0's and 1's such that there are no consecutive 1's.
 *
 * Note: This is really just the fibonacci problem
 *
 * State:
 *  f(index) -> number of ways of filling array
 */
#include <iostream>

int fun(int index, int n, bool previousIndexAOne = false) {
    if (index == n + 1) {
        return 1;
    }

    int answer {};
    // place 0
    answer += fun(index + 1, n, false);

    // place 1 (can only do if we previously added a zero)
    if (!previousIndexAOne) {
        answer += fun(index + 1, n, true);
    }
    return answer;
}

int main() {
    for (int i { 1 }; i < 10; ++i) {
        std::cout << fun(1, i) << '\n';
    }
}
