#include <iostream>
#include <cmath>

int main() {
    struct Point {
        double x;
        double y;
    };
    Point p1 {4.0, 7.0};
    Point p2 {1.0, 2.0};
    std::cout << "Point 1 is at: " << p1.x << ", " << p1.y << "\n";
    std::cout << "Point 2 is at: " << p2.x << ", " << p2.y << std::endl;

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    double dx2 = dx * dx;
    double dy2 = dy * dy;
    double sum = dx2 + dy2;

    double distance = std::sqrt(sum);
    std::cout << "The distance between points is " << distance << std::endl;
    return 0;
}
