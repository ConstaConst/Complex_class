

#include "Complex.h"
#include <iostream>

Complex::Complex(const double re, const double im):
real(re),
imagine(im)
{;}
Complex::Complex(const Complex& cpx):
real(cpx.real),
imagine(cpx.imagine)
{;}
Complex::Complex(const Complex& cpx, const double change):
real(cpx.real),
imagine(change)
{;}
Complex::Complex(const double change, const Complex &cpx):
real(change),
imagine(cpx.imagine)
{;}
Complex::Complex(const Complex &c_re, const Complex &c_im):
real(c_re.real),
imagine(c_im.imagine)
{;}

Complex& Complex::operator=(const Complex &cpx) {
    if (&cpx == this)
        return *this;
    real = cpx.real;
    imagine = cpx.imagine;
}

std::ostream &operator<<(std::ostream& os, const Complex &cpx) {
    os << cpx.real << " + " << cpx.imagine << "i";
    return  os;
}
std::istream &operator>>(std::istream &is, Complex &cpx) {
    is >> cpx.real;
    is.ignore(3);
    is >> cpx.imagine;
    is.ignore(1);
    return is;
}

const Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.real + b.real, a.imagine + b.imagine);
}
Complex& Complex::operator+=(const Complex &a) {
    return *this = *this + a;
}

const Complex operator-(const Complex &a, const Complex &b) {
    return Complex(a.real - b.real, a.imagine - b.imagine);
}
Complex& Complex::operator-=(const Complex &a) {
    return  *this = *this - a;
}

const Complex operator*(const Complex &a, const Complex &b) {
    return Complex(a.real * b.real - a.imagine * b.imagine,
                    a.real * b.imagine + a.imagine * b.real);
}
Complex& Complex::operator*=(const Complex &a) {
    return  *this = *this * a;
}

const Complex operator/(const Complex &a, const  Complex &b) {
    return Complex((a.real * b.real + a.imagine * b.imagine)/(b.real * b.real + b.imagine * b.imagine),
                   (b.real * a.imagine - a.real * b.imagine)/(b.real * b.real + b.imagine * b.imagine));
}
Complex& Complex::operator/=(const Complex &a) {
    return *this = *this / a;
}