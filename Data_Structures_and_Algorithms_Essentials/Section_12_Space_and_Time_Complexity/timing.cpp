#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

int main() {
    int n {};
    std::cin >> n;

    std::cout << "Enter the number of elements: ";
    std::vector<int> a(n);

    for (int i {}; i < n; ++i) {
        a[i] = n - i;
    }

    auto start_time {clock()};
    std::sort(begin(a), end(a));
    auto end_time {clock()};

    auto time = end_time - start_time;
    std::cout <<  "It took " << time << " clicks ("
        << ((float)time)/CLOCKS_PER_SEC << " seconds)\n";
}
