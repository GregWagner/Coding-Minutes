/*
 * Given three numbers x, y, and mod, compute x
 * raised to power y module mod (x^y) % mod.
 *
 * Use the distributive property of division
 * (a * b) % c = ((a % c) * (b % c)) % c
 */
#include <iostream>

int power(int x, int y, int mod) {
  int answer{1};
  while (y) {
    if (y & 1) {
      answer = (answer * x) % mod;
    }
    x = (x * x) % mod;
    y >>= 1;
  }
  return answer;
}

int main() {
  std::cout << std::boolalpha;
  std::cout << (power(12, 25, 10007) == 9603) << '\n';
}
