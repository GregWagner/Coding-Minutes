#include <iostream>
#include <vector>

template <typename T> bool isSorted(std::vector<T> a, unsigned start = 0) {
  // if there is only element, it is sorted
  if (start == a.size() - 1) {
    return true;
  }
  return (a[start] < a[start + 1]) && isSorted(a, start + 1);
}

int main() {
  std::cout << std::boolalpha;
  std::vector<int> a{1, 2, 3, 4, 7, 6};
  std::cout << isSorted(a) << '\n';
}
