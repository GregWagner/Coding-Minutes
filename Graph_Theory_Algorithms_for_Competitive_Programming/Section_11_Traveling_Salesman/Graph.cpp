/*
 * Travelling Salesman (Hamitonian Cycle)
 * Finding the shortest round trip cost
 * Use to mimize the cost of the last mile delivery or
 * supply chain or vehicle routing problemm.
 *
 * Brute Force
 * Calculate and compare all possible permutations off routiutes
 * or paths to determine the shortest unique solution.
 *
 * DP Approach
 */

#include <iostream>
#include <vector>
#include <climits>

int tsp(std::vector<std::vector<int>>& distance, int setOfCities,
        int city, int n, std::vector<std::vector<int>>& dp) {
    // base case
    if (setOfCities == (1<<n) - 1) {
        // return the cost from the city to the orginal
        return distance[city][0]; 
    }

    // added for DP
    if (dp[setOfCities][city] != -1) {
        return dp[setOfCities][city];
    }

    int answer {INT_MAX};

    // otherwise tryy all possible options
    for (int choice {}; choice < n; ++choice) {
        // check if city is visited or not
        if ((setOfCities & (1<<choice)) == 0) {
            int subProblem = distance[city][choice] +
                tsp(distance, setOfCities | (1<<choice), choice, n, dp);
            answer = std::min(answer, subProblem);
        }
    }
    dp[setOfCities][city] = answer;
    return answer;
}

int main() {
    std::vector<std::vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };

    // added for DP 
    int n {4};
    std::vector<std::vector<int>> dp(1<<n, std::vector<int>(n, -1));

    std::cout << tsp(dist, 1, 0, 4, dp) << '\n';
}

