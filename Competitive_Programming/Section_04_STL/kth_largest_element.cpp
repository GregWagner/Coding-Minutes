#include <iostream>
#include <vector>
#include <algorithm>

int findKthLargest(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a {3, 2, 3, 1, 2, 4, 5, 5, 6};
    std::cout << (findKthLargest(a, 4) == 4) << '\n';
    std::cout << findKthLargest(a, 4) << '\n';
}
