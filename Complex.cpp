
#include <cmath>
#include <iostream>
#include "Complex.h"

    Complex::Complex()
    {
        Real = 0;
        Im = 0;
    }

    Complex::Complex(double real, double im)
    {
        Real = real;
        Im = im;
    }

    Complex::Complex(const Complex &number)
    {
        Real = number.Real;
        Im = number.Im;
    }

    double Complex::GetRealPart() const
    {
        return Real;
    }

    double Complex::GetImPart() const
    {
        return Im;
    }

    Complex Complex::operator+(const Complex& number) const
    {
        return {Real + number.Real, Im + number.Im};
    }

    Complex Complex::operator-(const Complex& number) const
    {
        return {Real - number.Real, Im - number.Im};
    }

    Complex Complex::operator*(const Complex& number) const
    {
        return {Real * number.Real - Im * number.Im, Real * number.Im + Im * number.Real};
    }

    bool Complex::operator==(const Complex& number) const
    {
        if( std::fabs(this->Real - number.Real) < 1e-9 && 
            std::fabs((this->Im - number.Im)) < 1e-9 )
            return true;
        return false;
            
    }

    bool Complex::operator!=(const Complex& number) const
    {
        return (Real != number.Real || Im == number.Im);
    }


    double Complex::Abs() const
    {
        return std::sqrt(Real * Real + Im * Im);
    }


std::ostream &operator<<(std::ostream &out, const Complex &number)
    { 
            return out << "(" << number.GetRealPart() << "  " << number.GetImPart() << ")";    
    }

std::istream &operator>>(std::istream &in, Complex &number)
    {
        std::cout << "Enter real part of complex number " << std::endl;
        in >> number.Real;
        std::cout << "Enter image part of complex number " << std::endl;
        in >> number.Im;
        return in;
    }

