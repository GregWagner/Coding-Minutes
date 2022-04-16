/*
 * Given n cartesian points in a 2D plane, find the number
 * of axis parallel rectanges that can be formed.
 */
#include <iostream>
#include <set>
#include <vector>

struct Point {
    int x;
    int y;
};

class Compare {
    public:
        bool operator()(const Point &p1, const Point &p2) const {
            return (p1.x == p2.x ? p1.y < p2.y: p1.x < p2.x);
        }
};

int countRectangles(std::vector<Point> points) {
    std::set<Point, Compare> s {points.begin(), points.end()};

    int count {};

    // Brue Force for 2 points + lookup for the other 2 points
    for (size_t i {}; i < points.size(); ++i) {
        for (size_t j {i + 1}; j < points.size(); ++j) {
            if (points[i].x == points[j].x || points[i].y == points[j].y) {
                continue;
            }
            if (s.count({points[i].x, points[j].y}) > 0 &&
                    s.count({points[j].x, points[i].y}) > 0) {
                ++count;
            }
        }
    }
    return count / 2;
}

int main() {
    std::vector<Point> a {
        {0, 0}, {0, 1}, {1, 1}, {1, 0},
        {2, 1}, {2, 0}, {3, 1}, {3, 0} };

    std::cout << std::boolalpha << (countRectangles(a) == 6) << '\n';
}
