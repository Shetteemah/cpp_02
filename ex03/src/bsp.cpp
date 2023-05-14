#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

static float crossProduct(const Point &a, const Point &b)
{
    return a.getX() * b.getY() - b.getX() * a.getY();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point v1(b.getX() - a.getX(), b.getY() - a.getY());
    Point v2(c.getX() - a.getX(), c.getY() - a.getY());
    Point v3(point.getX() - a.getX(), point.getY() - a.getY());

    float dot11 = v1.getX().toFloat() * v1.getX().toFloat() + v1.getY().toFloat() * v1.getY().toFloat();
    float dot12 = v1.getX().toFloat() * v2.getX().toFloat() + v1.getY().toFloat() * v2.getY().toFloat();
    float dot13 = v1.getX().toFloat() * v3.getX().toFloat() + v1.getY().toFloat() * v3.getY().toFloat();
    float dot22 = v2.getX().toFloat() * v2.getX().toFloat() + v2.getY().toFloat() * v2.getY().toFloat();
    float dot23 = v2.getX().toFloat() * v3.getX().toFloat() + v2.getY().toFloat() * v3.getY().toFloat();

    float invDenom = 1 / (dot11 * dot22 - dot12 * dot12);
    float u = (dot22 * dot13 - dot12 * dot23) * invDenom;
    float v = (dot11 * dot23 - dot12 * dot13) * invDenom;

    if (u >= 0 && v >= 0 && u + v < 1)
    {
        Point t1(c.getX() - a.getX(), c.getY() - a.getY());
        Point t2(point.getX() - a.getX(), point.getY() - a.getY());
        float cross = crossProduct(t1, t2);
        if (cross == 0)
        {
            return false;
        }
        return true;
    }
    return false;
}
