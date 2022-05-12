/*
 * Find the first occurence of an element in an array
 */
#include <iostream>
#include <vector>

int firstOccurance(int a[], int n, int key) {
  if (n == 0) {
    return -1;
  }

  if (a[0] == key) {
    return 0;
  }

  int subIndex = firstOccurance(a + 1, n - 1, key);
  if (subIndex != -1) {
    return subIndex + 1;
  }
  return -1;
}

int main() {
  int a[]{1, 4, 5, 7, 6, 2};
  int n = sizeof(a) / sizeof(int);
  int key{7};
  std::cout << firstOccurance(a, n, key) << '\n';
}
