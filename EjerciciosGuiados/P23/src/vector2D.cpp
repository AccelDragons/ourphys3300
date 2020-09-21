#include "vector2D.h"

float vector2D::lengthSquared()
{
    return x * x + y * y;
}

float vector2D::length()
{
    return sqrt(x * x + y * y);
}

void vector2D::operator+=(const vector2D& v)
{
    x += v.x;
    y += v.y;
}
