/*
 * Sparse Search
 *
 * Given a sorted array of strings that is interspersed with
 * empty strings, write a method to find the location of 
 * a given string
 *
 * Modified binary search
 * From the midpoint find the nearest non-empty location by 
 * a linear search in both directions.
 */
#include <iostream>
#include <vector>

int search(std::vector<std::string>& a, std::string key) {
    int start {};
    int end = a.size() - 1;

    while (start <= end) {
        int middle = (start + end) / 2;

        int left {middle};
        int right {middle};
        while (a[middle] == "") {
            --left;
            ++right;
            if (left >= 0 && a[left] != "") {
                middle = left;
                break;
            }
            if (right < a.size() && a[right] != "") {
                middle = right;
                break;
            }
        }
        // middle now points to a non-empty string
        if (a[middle] == key) {
            return middle;
        }
        if (a[middle] < key) {
            start = middle + 1;
        } else {
           end = middle - 1; 
        }
    }
    return -1;
}

int main() {
    std::cout << std::boolalpha;
    std::vector<std::string> a {"ai", "", "",
        "bat", "", "", "car", "cat", "", "", "dog", ""};
    std::cout << (search(a, "ai") == 0) << '\n';
    std::cout << (search(a, "bat") == 3) << '\n';
    std::cout << (search(a, "dog") == 10) << '\n';
}
