/*
 * You are playing a game with k friends. You have an array of N
 * coins, at each index i you have a coin of value a[i].
 * Your task is to divide the coins amoung the group of k friends
 * by doing consecutive segments (k-subarrys) of the array.
 * Each friend will get a total sum of the coins in that subarray.
 * Since all your friends are greedy, they will pick the largest 
 * k - 1 segments and you will get the smallest segment. Find out
 * the maximum valuue you can make by making an optimal partition.
 * Note: The coins array may or may not be sorted!
 *
 * i.e. Maximize the minimum
 * Search space is between the smallest coin and the sum of all coins.
 * Try to partition so each person gets (min + max) / 2
 * If false, search left, else try right
 */
#include <iostream>
#include <vector>

bool divideAmoungK(std::vector<int> &a, int k, int minCoins) {
    int partions {};
    int currentFriend {};

    for (size_t i {}; i < a.size(); ++i) {
        if (currentFriend + a[i] >= minCoins) {
            partions += 1;
            currentFriend = 0;
        } else {
            currentFriend += a[i];
        }
    }
    return partions >= k;
}

int k_partition(std::vector<int> &coins, int k) {
    int start {};
    int end {};
    for (auto i : coins) {
        end += i;
    }

    int answer {};
    while (start <= end) {
        int middle = (start + end) / 2;
        bool isPossible = divideAmoungK(coins, k, middle);
        if (isPossible) {
            answer = middle;        // possible answer
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return answer;
}

int main() {
    std::vector<int> coins {1, 2, 3, 4};
    std::cout << k_partition(coins, 3) << '\n';
}

