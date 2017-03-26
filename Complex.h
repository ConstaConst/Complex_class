/**
 * Вариант 13.
«Комплексное число» – Complex. Класс должен содержать несколько конструкторов.
Реализовать методы для сложения, вычитания, умножения, деления и вывода на экран.
Создать два вектора размерности n из комплексных координат. Передать их в функцию,
которая выполняет сложение комплексных векторов.
 */

#ifndef HW_5_COMPLEX_H
#define HW_5_COMPLEX_H

#include <iostream>


class Complex {
public:
    Complex(const double re = 0, const double im = 0);
    Complex(const Complex &cpx);
    Complex(const Complex &c_re, const Complex &c_im);
    Complex(const Complex &cpx, const double change);
    Complex(const double change, const Complex &cpx);

    Complex &operator=(const Complex &cpx);

    friend std::ostream &operator<<(std::ostream &os, const Complex &cpx);
    friend std::istream &operator>>(std::istream &is, Complex &cpx);

    friend const Complex operator+(const Complex &a, const Complex &b);
    Complex &operator+=(const Complex &a);

    friend const Complex operator-(const Complex &a, const Complex &b);
    Complex &operator-=(const Complex &a);

    friend const Complex operator*(const Complex &a, const Complex &b);
    Complex &operator*=(const Complex &a);

    friend const Complex operator/(const Complex &a, const Complex &b);
    Complex &operator/=(const Complex &a);


private:
    double real;
    double imagine;
};

#endif //HW_5_COMPLEX_H
