#include <iostream>
#include <vector>

int count {};
std::vector<int> memo;

int fib(int n) {
    ++count;
    if (n <= 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int memFib(int n) {
    ++count;
    if (n <= 2) {
        return 1;
    }
    // memoisation part
    if (memo[n] != -1) {
        return memo[n];
    }
    // recursive relation part
    return memo[n] = memFib(n - 1) + memFib(n - 2);
}

int tabFib(int n) {
    std::vector<int> tab(n + 1);
    // base cases
    tab[1] = tab[2] = 1;
    for (int i { 3 }; i <= n; ++i) {
        ++count;
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    return tab[n];
}

int main() {
    int n { 20 };
    std::cout << "fib(" << n << "): " << fib(n)
              << ", there were " << count << " recursive calls\n";

    count = 0;
    memo.resize(n + 1, -1);
    std::cout << "memFib(" << n << "): " << memFib(n)
              << ", there were " << count << " recursive calls\n";

    count = 0;
    std::cout << "tabFib(" << n << "): " << tabFib(n)
              << ", there were " << count << " recursive calls\n";
}
