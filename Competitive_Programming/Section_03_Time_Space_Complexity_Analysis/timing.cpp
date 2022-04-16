#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int n {};
    std::cin >> n;
    std::vector<int> a(n, 0);

    // initialize a reverse sorted array
    for (int i {}; i < n; ++i) {
        a[i] = n - 1;
    }

    auto start_time {clock()};
    std::sort(a.begin(), a.end());
    auto end_time {clock()};

    std::cout << "Sort took " << end_time - start_time << '\n';
}
