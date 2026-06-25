#include <iostream>
#include <cmath>
#include "circle.h"

int main() {
    Circle c;
    Point p;

    std::cin >> c.centre.x >> c.centre.y >> c.radius >> p.x >> p.y;

    double d = distance(&c, &p);

    if (std::fabs(d - c.radius) < EPSILON) {
        std::cout << "On Circle" << std::endl;
    } else if (d < c.radius) {
        std::cout << "Inside" << std::endl;
    } else {
        std::cout << "Outside" << std::endl;
    }

    return 0;
}