#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

using namespace std;

class Rec
{
protected:
    float s1,s2; // lenght of the sides
public:
    Rec();
    Rec(int, int);
    float diag();
    float area();
    void edit();
    void modify(float, float);
    void dsp_sides();
    friend ostream& operator<<(ostream& os, const Rec& r);
};

class Cub : public Rec
{
protected:
    float s3;  // lenght of the side
public:
    Cub(); //: Rec();
    Cub(int, int, int); //: Rec(_s1,_s2);
    float diag();
    float area();
    float volume();
    void edit();
    void modify(float,float,float);
    void dsp_sides();
    friend ostream& operator<<(ostream& os, const Cub& r);
};

#endif // HEADER_H
