/*
 * The planet Earth is under a threat from the aliens of the
 * outer space and your task is to defeat an enemy who is N
 * steps above you (assume yourself to be at ground level,
 * i.e. at the 0th level). You can take jumps in power of 2.
 * In order to defeat the enemy as quickly as possible you
 * have to reach the Nth step in the minimum number of moves.
 *
 * Count the nummber of bits set to 1
 */
#include <iostream>

int earthLevel(int k) {
  int count {};
  while (k) {
    // removes the last set bit from n
    k &= k - 1;
    ++count;
  }
  return count;
}

int main() {
  std::cout << std::boolalpha;
  std::cout << (earthLevel(7) == 3) << '\n';
}
