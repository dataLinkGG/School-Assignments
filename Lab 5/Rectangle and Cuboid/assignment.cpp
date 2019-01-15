#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "assignment.hpp"
#include "more_functions.hpp"

using namespace std;

Rec::Rec()
{
    s1 = s2 = 0;
}

Rec::Rec(int _s1, int _s2)
{
    s1 = _s1; s2 = _s2;
}

float Rec::diag()
{
    return sqrt(pow(s1,2)+pow(s2,2));
}

float Rec::area()
{
    return s1 * s2;
}

void Rec::edit()
{
    cout << "s1: ";
    cin >> s1;
    cout << "s2: ";
    cin >> s2;
}

void Rec::dsp_sides()
{
    cout << " s1 = " << s1 << endl;
    cout << " s2 = " << s2 << endl;
}

void Rec::modify(float _s1, float _s2)
{
    s1 = _s1;
    s2 = _s2;
}

Cub::Cub() : Rec()
{
    s3 = 0;
}

Cub::Cub(int _s1, int _s2, int _s3) : Rec(_s1,_s2)
{
    s3 = _s3;
}

float Cub::diag()
{
    return sqrt(pow(s1,2)+pow(s2,2)+pow(s3,2));
}

float Cub::area()
{
    return 2 * ( s1 * s2 + s1 * s3 + s2 * s3 );
}

float Cub::volume()
{
        return s1 * s2 * s3;
}

void Cub::edit()
{
    cout << "s1: ";
    cin >> s1;
    cout << "s2: ";
    cin >> s2;
    cout << "s3: ";
    cin >> s3;
}

void Cub::modify(float _s1, float _s2, float _s3)
{
    s1 = _s1;
    s2 = _s2;
    s3 = _s3;
}

void Cub::dsp_sides()
{
    cout << " s1 = " << s1 << endl;
    cout << " s2 = " << s2 << endl;
    cout << " s3 = " << s3 << endl;
}

ostream& operator<<(ostream& os, const Rec& c)
{
    cout << "<" << c.s1 << ",0> x " << "<0," <<c.s2 << ">";
    return os;
}

ostream& operator<<(ostream& os, const Cub& c)
{
    printf("<%f,0,0> x <0,%f,0> x <0,0,%f>",c.s1,c.s2,c.s3);
    return os;
}
