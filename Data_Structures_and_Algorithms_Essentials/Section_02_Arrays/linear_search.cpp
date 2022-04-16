#include <iostream>
#include <vector>

template <typename T>
int linear_search(const std::vector<T> &a, T key) {
    int answer {-1};  
    for (size_t index {}; index < a.size(); ++index) {
        if (a[index] == key) {
            return index;
        }
    }
    return answer;
}

int main() {
    std::vector<int> a {10, 15, 12, 9, 6, 4, 3, 10, 8};

    int key {};
    std::cin >> key;

    auto index = linear_search(a, key);

    if (index == -1) {
        std::cout << key << " is NOT found\n";
    } else {
        std::cout << key << " is present at index " << index << '\n';
    }
}
