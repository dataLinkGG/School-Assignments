#ifndef MORE_FUNCTIONS_HPP
#define MORE_FUNCTIONS_HPP

using namespace std;

class Point
{
protected:
    float x,y,z;
public:
    Point();
    Point(float, float, float);
    Point(const Point &); // copy constructor
    float get_x();
    float get_y();
    float get_z();
};

class Vector : Point
{
protected:
    float x1,y1,z1;
public:
    Vector(); //: Point();
    Vector(float,float,float); // : Point();
    Vector(Point &,Point &);
    float length ();
};

#endif // HEADER_H
