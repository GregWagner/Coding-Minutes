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

int mem_fib(int n) {
    ++count;
    if (n <= 2) {
        return 1;
    }
    // memoisation part
    if (memo[n] != -1) {
        return memo[n];
    }
    // recursive relation part
    return memo[n] = mem_fib(n - 1) + mem_fib(n - 2);
}

int tab_fib(int n) {
    std::vector<int> tab(n + 1);
    tab[1] = tab[2] = 1;
    for (int i {3}; i <= n; ++i) {
        ++count;
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    return tab[n];
}

int main() {
    int n {20};
    std::cout << "fib(" << n << "): " << fib(n)
        <<", there were " << count << " recursive calls\n";

    count = 0;
    memo.resize(n + 1, -1);
    std::cout << "mem_fib(" << n << "): " << mem_fib(n)
        <<", there were " << count << " recursive calls\n";

    count = 0;
    std::cout << "tab_fib(" << n << "): " << tab_fib(n)
        <<", there were " << count << " recursive calls\n";
    
}
