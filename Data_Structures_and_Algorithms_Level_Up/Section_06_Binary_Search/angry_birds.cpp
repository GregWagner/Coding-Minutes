/*
 * Angry birds
 *
 * There is a long wire along a straight line which contains
 * N birds nests at position x1, x2, ..., xN.
 *
 * There a B (B <= N) birds which becomme angey towards each 
 * other once put into a nest. To leep the birds from 
 * hurting each other you want to assign birds to nests 
 * such that the minimum distance between any 2 birds is as
 * large as possible. What is the largeest minimum distance?
 *
 * n = 5 b = 3
 * nests are at [1, 2, 4, 8, 9]
 * Answer is 3
 *
 * Set start to 0 and end at nest[n - 1] - next[0] to represent distance
 * Do binary search and check if you can place all the birds at that 
 * distance. If you can't, then search to left. If you can it is a possible
 * answer, but search to the right to make sure.
 */
#include <iostream>
#include <vector>
#include <algorithm>

bool canPlaceBirds(int numberOfBirds, const std::vector<int>& nests, int separation) {
    int birdsPlaced {1};
    int location {nests[0]};

    for (size_t i {1}; i < nests.size() - 1; ++i) {
        int current_location = nests[i];
        if (current_location - location >= separation) {
            ++birdsPlaced;
            location = current_location;

            if (birdsPlaced == numberOfBirds) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<int> nests {1, 2, 4, 8, 9};
    int n = nests.size();
    int birds {3};

    std::sort(nests.begin(), nests.end());

    int start {};
    int end {nests[n - 1] - nests[0]};
    int answer {-1};

    while (start <= end) {
        int middle = (start + end) / 2;

        bool canPlace = canPlaceBirds(birds, nests, middle);
        if (canPlace) {
            // answer found, but try to maximum
            answer = middle;
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    std::cout << answer << '\n';
}
