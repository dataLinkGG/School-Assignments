#include <iostream>

using namespace std;

template <class RealNumber> // a and b can be float, double, integer...
class ComplexNumber
{
private:
    RealNumber real,img;
public:
    ComplexNumber() {
        real = 0;
        img = 0;
    }
    ComplexNumber(RealNumber _real, RealNumber _img) {
        real = _real;
        img = _img;
    }
    RealNumber get_real_part() {
        return real;
    }
    RealNumber get_img_part() {
        return img;
    }
    ComplexNumber operator+(const ComplexNumber& z2) {
        ComplexNumber z;
        z.real = real + z2.real;
        z.img = img + z2.img;
        return z;
    }
    ComplexNumber operator-(const ComplexNumber& z2) {
        ComplexNumber z;
        z.real = real - z2.real;
        z.img = img - z2.img;
        return z;
    }
    ComplexNumber operator*(const ComplexNumber& z2) {
        ComplexNumber z;
        z.real = (real * z2.real - img * z2.img);
        z.img = (real * z2.img + img * z2.real);
        return z;
    }
    ComplexNumber operator/(const ComplexNumber& z2) {
        ComplexNumber z;
        z.real = (real*z2.real+img*z2.img)/(z2.real*z2.real+z2.img*z2.img);
        z.img = (img*z2.real-real*z2.img)/(z2.real*z2.real+z2.img*z2.img);
        return z;
    }
    void display_algebraic_form() {
        cout << "(" << real << ", " << img << ")";
        cout << endl;
    }
};

int main()
{
    ComplexNumber <float> z1(42,3); // 42 + 3i
    ComplexNumber <float> z2(25,9); // 25 + 9i

    ComplexNumber <float> z3; // 0 + 0i

    z3 = z1 + z2;
    z3.display_algebraic_form();

    z3 = z1 - z2;
    z3.display_algebraic_form();

    z3 = z1 * z2;
    z3.display_algebraic_form();

    z3 = z1 / z2;
    z3.display_algebraic_form();

    return 0;
}
