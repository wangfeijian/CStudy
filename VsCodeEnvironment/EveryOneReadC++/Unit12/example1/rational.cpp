#include "./rational.h"
#include <iostream>
namespace MyMath
{
    Rational::Rational(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
        Normalize();
    }

    Rational Rational::operator+(const Rational &other)
    {
        int a = this->numerator;
        int b = this->denominator;
        int c = other.numerator;
        int d = other.denominator;
        int numerator = a * d + b * c;
        int denominator = b * d;
        return Rational(numerator, denominator);
    }

    Rational Rational::operator-(const Rational &other)
    {
        Rational ras(-other.numerator, other.denominator);

        return operator+(ras);
    }

    Rational Rational::operator*(const Rational &other)
    {
        int a = this->numerator;
        int b = this->denominator;
        int c = other.numerator;
        int d = other.denominator;
        int numerator = a * c;
        int denominator = b * d;
        return Rational(numerator, denominator);
    }

    Rational Rational::operator/(const Rational &other)
    {
        Rational ras(other.denominator, other.numerator);
        return operator*(ras);
    }

    void Rational::Normalize()
    {
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }

        int a = abs(numerator);
        int b = abs(denominator);
        while (b > 0)
        {
            int t = a % b;
            a = b;
            b = t;
        }

        numerator /= a;
        denominator /= a;
    }

    std::ostream &operator<<(std::ostream &os, const Rational &r)
    {
        os << r.numerator << "/" << r.denominator;
        return os;
    }
} // namespace MyMath