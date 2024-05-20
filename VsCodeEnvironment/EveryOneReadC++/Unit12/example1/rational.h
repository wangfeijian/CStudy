#pragma once

#include <iostream>

namespace MyMath
{

    class Rational
    {
    public:
        Rational(int num, int denom);
        Rational operator+(const Rational &other);
        Rational operator-(const Rational &other);
        Rational operator*(const Rational &other);
        Rational operator/(const Rational &other);

    private:
        void Normalize();
        int numerator;
        int denominator;
        friend std::ostream &operator<<(std::ostream &os, const Rational &r);
    };

} // namespace MyMath