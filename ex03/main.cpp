#include "Point.hpp"

void test(const std::string& description, const Point& a, const Point& b, const Point& c, const Point& p)
{
    std::cout << description << " : " << (bsp(a, b, c, p) ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main()
{
    // Triangle de base
    Point A(0, 0);
    Point B(10, 0);
    Point C(0, 10);

    std::cout << "=== BASIC TRIANGLE ===" << std::endl;

    test("Point inside", A, B, C, Point(2, 2));
    test("Point outside", A, B, C, Point(20, 20));
    test("Point on edge", A, B, C, Point(5, 0));
    test("Point on vertex", A, B, C, Point(0, 0));

    std::cout << std::endl;

    // Triangle inversé (ordre horaire)
    Point D(0, 0);
    Point E(0, 10);
    Point F(10, 0);

    std::cout << "=== REVERSED TRIANGLE ===" << std::endl;

    test("Inside reversed", D, E, F, Point(2, 2));
    test("Outside reversed", D, E, F, Point(8, 8));

    std::cout << std::endl;

    // Triangle dégénéré (aligné)
    Point G(0, 0);
    Point H(5, 5);
    Point I(10, 10);

    std::cout << "=== DEGENERATE TRIANGLE ===" << std::endl;

    test("Aligned point", G, H, I, Point(6, 6));

    return 0;
}
