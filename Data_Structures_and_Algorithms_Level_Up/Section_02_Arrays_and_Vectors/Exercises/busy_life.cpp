#include <algorithm>
#include <iostream>
#include <vector>

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second;
}

int countActivites(std::vector<std::pair<int, int>>& activities) {

    // sort by ending time
    std::sort(activities.begin(), activities.end(), cmp);
#if 0
    for (auto e : activities) {
        std::cout << e.first << ", " << e.second << '\n';
    }
    std::cout << '\n';
#endif
    int count {};
    int endingTime {};
    for (auto e : activities) {
        //      std::cout << "Checking " << e.first << ", " << e.second << '\n';
        if (e.first >= endingTime) {
            ++count;
            endingTime = e.second;
            //          std::cout << "Adding count: " << count << ", EndingTime: " << endingTime << '\n';
        }
    }
    //  std::cout << count << '\n';
    return count;
}

int main() {
    std::vector<std::pair<int, int>> a {
        { 7, 9 }, { 0, 10 }, { 4, 5 }, { 8, 9 }, { 4, 10 }, { 5, 7 }
    };
    std::cout << std::boolalpha << (countActivites(a) == 3) << '\n';
}
