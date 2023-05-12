#include "Fixed.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point inside(1, 1);
    Point onEdge(2.5, 0);
    Point outside(10, 10);

    std::cout << "Inside point is " <<
