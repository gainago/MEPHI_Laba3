#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>
#include <iostream>
class Complex
{
private:
    double Real;
    double Im;
public:
    Complex();

    Complex(double real, double im);

    Complex(const Complex &number);

    double GetRealPart() const;

    double GetImPart() const;

    Complex operator+(const Complex& number) const;

    Complex operator-(const Complex& number) const;

    Complex operator*(const Complex& number) const;

    bool operator==(const Complex& number) const;

    bool operator!=(const Complex& number) const;

    Complex& operator=(const Complex &number)
    = default;

    friend std::istream &operator>>(std::istream &in, Complex &number);

    double Abs() const;
};

std::ostream &operator<<(std::ostream &out, const Complex &number);

std::istream &operator>>(std::istream &in, Complex &number);

#endif