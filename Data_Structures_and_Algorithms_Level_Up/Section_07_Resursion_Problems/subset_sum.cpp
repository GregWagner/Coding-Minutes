/*
 * Subset sum
 *
 * Given a set of non-negative integers, and a value sum,
 * determine if there is a subset of the given set with the
 * sum equal to the given sum
 *
 * a = [10, 12, 15, 6, 19, 20]
 * sum = 16
 * Yes
 */
#include <iostream>
#include <vector>

int subset_sum(std::vector<int> a, int index, int targetSum) {
    if (index == a.size()) {
        if (targetSum == 0) {
        return 1;
        } 
        return 0;
    }

    int include = subset_sum(a, index + 1, targetSum - a[index]);
    int exclude = subset_sum(a, index + 1, targetSum);

    return include + exclude;
}

int main() {
    std::vector<int> a {1, 2, 3, 4, 5};
    std::cout << std::boolalpha << (subset_sum(a, 0, 6) == 3) << '\n';
}
