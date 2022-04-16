/*
 * FizzBuzz Test
 *
 * Write a fizzbuzz function that returns a vector<string> with the numbers
 * from 1 to n with the following restrictions:
 *  * for multiples of 3 store "Fizz" instead of the number
 *  * for multiples of 5 store "Buzz" instead of the number
 *  * for numbers which are multiples of both 3 and 5 store "FizzBuzz"
 * You may use the std::to_string(number) method to conver  a number into
 * a string.
 */
#include <iostream>
#include <vector>

std::vector<std::string> fizzbuzz(int n) {
    std::vector<std::string> results;

    const int FIZZ_BUZZ_NUMBER {15};
    const int FIZZ_NUMBER {3};
    const int BUZZ_NUMBER {5};

    for (int i {1}; i <= n; ++i) {
        if (i % FIZZ_BUZZ_NUMBER == 0) {
            results.emplace_back("FizzBuzz");
        } else if (i % FIZZ_NUMBER == 0) {
            results.emplace_back("Fizz");
        } else if (i % BUZZ_NUMBER == 0) {
            results.emplace_back("Buzz");
        } else {
            results.emplace_back(std::to_string(i));
        }
    }
    return results;
}

int main() {
    int input {};
    std::cout << "Enter the number to fizz-buzz: ";
    std::cin >> input;
    auto results = fizzbuzz(input);
    for (auto const &element : results) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}
