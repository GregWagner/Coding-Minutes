/* 
 * Given a long route containing NSEW directions, find the shortest
 * path to reach the location.
 * Example
 *      SNNNEWE -> NNE
 */
#include <iostream>
#include <sstream>

std::pair<int, int> calculatePosition(const std::string& route) {
    int xPosition {};
    int yPosition {};

    for (const auto c : route) {
        if (c == 'N') {
            ++yPosition;
        } else if (c == 'S') {
            --yPosition;
        } else if (c == 'E') {
            ++xPosition;
        } else {
            --xPosition;
        }
    }
    return {xPosition, yPosition};
}

void printFinalPosition(std::pair<int, int> position) {
    std::ostringstream output;

    int xPosition {position.first};
    int yPosition {position.second};

    bool goingNorth = yPosition > 0;
    while (yPosition--) {
        output << (goingNorth ? 'N' : 'S');
    }

    bool goingEast = xPosition > 0;
    while (xPosition--) {
        output << (goingEast ? 'E' : 'W');
    }
    std::cout << output.str() << '\n';
}

int main() {
    std::string route;
    std::cin >> route;

    auto finalPosition = calculatePosition(route);
    printFinalPosition(finalPosition);
}
