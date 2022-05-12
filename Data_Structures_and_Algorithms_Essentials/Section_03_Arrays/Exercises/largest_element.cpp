#include <iostream>
#include <vector>

int largestElement(const std::vector<int> &arr) {
    int largest {arr[0]};
    for (const auto& e : arr) {
        largest = std::max(e, largest);
    }
    return largest;
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> v {-3, 4, 1, 2, 3};
    std::cout << (largestElement(v) == 4) << '\n';
    std::vector<int> v1 {-1, -2, -3, -3, 8};
    std::cout << (largestElement(v1) == 8) << '\n';
}
