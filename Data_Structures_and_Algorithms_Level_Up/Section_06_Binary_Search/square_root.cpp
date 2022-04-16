/*
 * Square roots
 *
 * Given two integers N and P, find the square root of N
 * up to P places.
 *
 * n = 10, p = 3
 * 3.162
 *
 * Monotonic Search Space
 * for example: square root of 10 is between 0 and 10
 * So do a binary search between 0 and 10.
 * You are looking for a the largest number which when squared is 10
 */
#include <iostream>

double square_root(int n, int p) {
    int start {0};
    int end = {n};
    double answer {};
   
    // do a binary search to the integer part
    while (start <= end) {
        int middle = (start + end) / 2;

        if (middle * middle == n) {
            return middle;
        }
        if (middle * middle < n) {
            answer = middle;   // this might be the answer
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    // do a linear search for the floating point part.
    double inc = 0.1;
    for (int places{}; places < p; ++places) {
        while (answer * answer <= n) {
            answer += inc;
        }
        // take one step back
        answer -= inc;
        inc /= 10;
    }
    return answer;
}

int main() {
    int n, p;
    std::cin >> n >> p;
    std::cout << "Square root of " << n << " is " << square_root(n, p) << '\n';
}
