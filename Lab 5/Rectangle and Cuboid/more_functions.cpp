#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "assignment.hpp"
#include "more_functions.hpp"

using namespace std;

Point::Point()
{
    x = y = z = 0;
}

Point::Point(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

Point::Point(const Point &point)
{
    x = point.x;
    y = point.y;
    z = point.z;
}

float Point::get_x()
{
    return x;
}

float Point::get_y()
{
    return y;
}

float Point::get_z()
{
    return z;
}

Vector::Vector() : Point()
{
    x1 = y1 = z1 = 0;
}

Vector::Vector(float _x1, float _y1, float _z1) : Point()
{
    x1 = _x1;
    y1 = _y1;
    z1 = _z1;
}

Vector::Vector(Point &_p1, Point &_p2)
{
    x = _p1.get_x();
    y = _p1.get_y();
    z = _p1.get_z();
    z1 = _p2.get_x();
    y1 = _p2.get_y();
    z1 = _p2.get_z();
}

float Vector::length ()
{
    return sqrt(pow(x1-x,2)+pow(y1-y,2)+ pow(z1-z,2));
}
