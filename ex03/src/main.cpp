#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point inside(1, 1);
    Point onEdge(2.5, 0);
    Point outside(10, 10);

    std::cout << "Inside point is " << (bsp(a, b, c, inside) ? "inside" : "outside") << " the triangle.\n";
    std::cout << "On-edge point is " << (bsp(a, b, c, onEdge) ? "inside" : "outside") << " the triangle.\n";
    std::cout << "Outside point is " << (bsp(a, b, c, outside) ? "inside" : "outside") << " the triangle.\n";

    return 0;
}
