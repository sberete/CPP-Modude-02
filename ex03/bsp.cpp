#include "Point.hpp"
// « On utilise le signe du produit vectoriel pour vérifier que le point est du même côté de chaque arête du triangle. »
Fixed sign(Point const &p1, Point const &p2, Point const &p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
         - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    // Point sur un côté → false (exigé par le sujet)
    if (d1 == 0 || d2 == 0 || d3 == 0)
        return false;

    return !(has_neg && has_pos);
}

