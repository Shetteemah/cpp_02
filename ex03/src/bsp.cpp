#include "Fixed.hpp"

static float crossProduct(const Point& a, const Point& b) {
    return a.x * b.y - b.x * a.y;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Point v1(b.x - a.x, b.y - a.y);
    Point v2(c.x - a.x, c.y - a.y);
    Point v3(point.x - a.x, point.y - a.y);

    float dot11 = v1.x * v1.x + v1.y * v1.y;
    float dot12 = v1.x * v2.x + v1.y * v2.y;
    float dot13 = v1.x * v3.x + v1.y * v3.y;
    float dot22 = v2.x * v2.x + v2.y * v2.y;
    float dot23 = v2.x * v3.x + v2.y * v3.y;

    float invDenom = 1 / (dot11 * dot22 - dot12 * dot12);
    float u = (dot22 * dot13 - dot12 * dot23) * invDenom;
    float v = (dot11 * dot23 - dot12 * dot13) * invDenom;

    if (u >= 0 && v >= 0 && u + v < 1) {
        Point t1(c.x - a.x, c.y - a.y);
        Point t2(point.x - a.x, point.y - a.y);
        float cross = crossProduct(t1, t2);
        if (cross == 0) {
            return false;
        }
        return true;
    }
    return false;
}
