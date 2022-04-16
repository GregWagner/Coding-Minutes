/*
 * Given n cartesian points in a 2D place, find the number of
 * right hand triangles such that the base or perpendicular is
 * parallel to the x or y axis.
 *
 * Go through all points and for each point, check if there 
 * exists a point with the same x and another point with the 
 * same y.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

struct Point {
    int x;
    int y;
};

int countTriangles(std::vector<Point> points) {
    std::unordered_map<int, int> xCoordinates;
    std::unordered_map<int, int> yCoordinates;

    for (auto p : points) {
        ++xCoordinates[p.x];
        ++yCoordinates[p.y];
    }

    int count {};

    // Brue Force for 1 point + lookup for the other 2 points
    for (auto p : points) {
        int xCount = xCoordinates[p.x];
        int yCount = yCoordinates[p.y];

        // don't count the current point
        count += (xCount - 1) * (yCount - 1);
    }
    return count;
}

int main() {
    std::vector<Point> a {{1, 2}, {2, 0}, {2, 2}, {2, 3},{4, 2}};

    std::cout << std::boolalpha << (countTriangles(a) == 4) << '\n';
}
