#include <stdio.h>
#include <iostream>
#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction(float num)
    : numerator(int(num)), denominator(int(num)) // must to change!!!
{
}

Fraction::Fraction(int _numerator, int _denominator)
    : numerator(_numerator), denominator(_denominator)
{
}

Fraction Fraction::operator+(const Fraction &other)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator-(const Fraction &other)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator*(const Fraction &other)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator/(const Fraction &other)
{
    return Fraction(1, 1);
}

bool Fraction::operator==(const Fraction &other)
{
    return true;
}
bool Fraction::operator!=(const Fraction &other)
{
    return true;
}
bool Fraction::operator<(const Fraction &other)
{
    return true;
}
bool Fraction::operator>(const Fraction &other)
{
    return true;
}
bool Fraction::operator<=(const Fraction &other)
{
    return true;
}
bool Fraction::operator>=(const Fraction &other)
{
    return true;
}

Fraction Fraction::operator+(const float other)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator-(const float other)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator*(const float other)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator/(const float other)
{
    return Fraction(1, 1);
}

bool Fraction::operator==(const float other)
{
    return true;
}
bool Fraction::operator!=(const float other)
{
    return true;
}
bool Fraction::operator<(const float other)
{
    return true;
}
bool Fraction::operator>(const float other)
{
    return true;
}
bool Fraction::operator<=(const float other)
{
    return true;
}
bool Fraction::operator>=(const float other)
{
    return true;
}

Fraction &ariel::operator+(const float num, Fraction &frac)
{
    return frac;
}
Fraction &ariel::operator-(const float num, Fraction &frac)
{
    return frac;
}
Fraction &ariel::operator*(const float num, Fraction &frac)
{
    return frac;
}
Fraction &ariel::operator/(const float num, Fraction &frac)
{
    return frac;
}

bool ariel::operator==(const float num, Fraction &frac)
{
    return true;
}
bool ariel::operator!=(const float num, Fraction &frac)
{
    return true;
}
bool ariel::operator<(const float num, Fraction &frac)
{
    return true;
}
bool ariel::operator>(const float num, Fraction &frac)
{
    return true;
}
bool ariel::operator<=(const float num, Fraction &frac)
{
    return true;
}
bool ariel::operator>=(const float num, Fraction &frac)
{
    return true;
}



Fraction &Fraction::operator++()
{
    return *this;
}
Fraction &Fraction::operator--()
{
    return *this;
}
Fraction Fraction::operator++(int num)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator--(int num)
{
    return Fraction(1, 1);
}

std::ostream &ariel::operator<<(std::ostream &os, const Fraction &frac)
{
    os << frac.getnumerator() << "/" << frac.getdenominator();
    return os;
}

std::istream &ariel::operator>>(std::istream &is, Fraction &frac)
{
    return is;
}


Fraction ariel::Fraction::reduceFraction(Fraction frac){
    int frac_nume = frac.getnumerator();
    int frac_denom = frac.getdenominator();

    int num_to_reduce = gcd(frac_nume, frac_denom);
    
    int new_frac_nume = frac_nume/num_to_reduce;
    int new_frac_denom = frac_denom/num_to_reduce;

    return Fraction(new_frac_nume, new_frac_denom);

}


int ariel::Fraction::gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
