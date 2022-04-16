#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::pair<int,int> minDifference(std::vector<int> a, std::vector<int> b) {
    std::pair<int, int> answer;
    int minSoFar {INT_MAX};

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    size_t i {};
    size_t j {};
    while (i < a.size() && j < b.size()){
        if (std::abs(a[i] - b[j]) < minSoFar) {
            answer.first = a[i];
            answer.second = b[j];
            minSoFar = std::abs(a[i] - b[j]);
        } 
        a[i] < b[j] ? ++i : ++j;
    }
    return answer;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a {23, 5, 10, 17, 30};
    std::vector<int> b {26, 134, 135, 14, 19};

    auto answer = minDifference(a, b);
    std::cout << (answer.first == 17 && answer.second == 19) << '\n';
}
