#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <climits>
#include "Fraction.hpp"

using namespace ariel;
using namespace std;

Fraction::Fraction(float num)
{
    if (num == 0.0)
    {
        numerator = 0;
        denominator = 1;
    }
    int new_num = num * 1000;
    Fraction new_frac = Fraction(new_num, 1000);
    Fraction reduc_frac = reduceFraction(new_frac);
    numerator = reduc_frac.getNumerator();
    denominator = reduc_frac.getDenominator();
}

Fraction::Fraction(int _numerator, int _denominator)
{

    if (_denominator == 0)
    {
        throw invalid_argument("can't devide by zero");
    }

    if (_denominator < 0)
    {
        _denominator *= -1;
        _numerator *= -1;
    }

    int gcd_value = abs(gcd(_numerator, _denominator));

    numerator = _numerator / gcd_value;
    denominator = _denominator / gcd_value;
}

Fraction::Fraction(double num)
{
    *this = Fraction(float(num));
}

Fraction Fraction::operator+(const Fraction &other) const
{
    long long lcm = (denominator * other.denominator) / gcd(denominator, other.denominator);
    long long new_numerator = (numerator * (lcm / denominator)) + (other.numerator * (lcm / other.denominator));
    long long new_denominator = lcm;

    // Check for integer overflow before creating the new fraction object
    if (new_numerator > INT_MAX || new_numerator < INT_MIN || new_denominator > INT_MAX || new_denominator < INT_MIN)
    {
        throw overflow_error("Overflow error: the result of the multiplication is out of range for an int.");
    }
    if (new_denominator < 0)
    {
        new_denominator *= -1;
        new_numerator *= -1;
    }
    return reduceFraction(Fraction((int)new_numerator, (int)new_denominator));
}

Fraction Fraction::operator-(const Fraction &other) const
{
    long long new_nume = ((long long)numerator * other.denominator) - ((long long)other.numerator * denominator);
    long long new_denom = (long long)denominator * other.denominator;
    if (new_nume > INT_MAX || new_nume < INT_MIN || new_denom > INT_MAX || new_denom < INT_MIN)
    {
        throw std::overflow_error("Overflow error: the result of the multiplication is out of range for an int.");
    }

    if (new_denom < 0)
    {
        new_denom *= -1;
        new_nume *= -1;
    }
    return reduceFraction(Fraction((int)new_nume, (int)new_denom));
}

Fraction Fraction::operator*(const Fraction &other) const
{

    long long new_nume = (long long)this->getNumerator() * (long long)other.getNumerator();
    long long new_denom = (long long)this->getDenominator() * (long long)other.getDenominator();

    // Check for overflow
    if (new_nume > INT_MAX || new_nume < INT_MIN || new_denom > INT_MAX || new_denom < INT_MIN)
    {
        throw overflow_error("Overflow error: the result of the multiplication is out of range for an int.");
    }

    if (new_denom < 0)
    {
        new_denom *= -1;
        new_nume *= -1;
    }

    return reduceFraction(Fraction((int)new_nume, (int)new_denom));
}

Fraction Fraction::operator/(const Fraction &other) const
{
    if (other.getNumerator() == 0)
    {
        throw runtime_error("can't devide by zero");
    }
    long long this_nume = this->getNumerator();
    long long this_denom = this->getDenominator();
    long long other_nume = other.getNumerator();
    long long other_denom = other.getDenominator();

    long long new_nume = (long long)this_nume * other_denom;
    long long new_denom = (long long)this_denom * other_nume;

    if (new_nume > INT_MAX || new_nume < INT_MIN || new_denom > INT_MAX || new_denom < INT_MIN)
    {
        throw std::overflow_error("Overflow error: the result of the multiplication is out of range for an int.");
    }

    if (new_denom < 0)
    {
        new_denom *= -1;
        new_nume *= -1;
    }

    return reduceFraction(Fraction((int)new_nume, (int)new_denom));
}

// ************************************************************//

bool Fraction::operator==(const Fraction &other) const
{
    Fraction reduced_this = reduceFraction(*this);
    Fraction reduced_other = reduceFraction(other);

    return (reduced_this.getNumerator() == reduced_other.getNumerator() && reduced_this.getDenominator() == reduced_other.getDenominator());
}

bool Fraction::operator!=(const Fraction &other) const
{
    return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const
{

    double this_value = (double)numerator / denominator;
    double other_value = (double)other.numerator / other.denominator;
    return this_value < other_value;
}

bool Fraction::operator>(const Fraction &other) const
{
    return other < *this;
}

bool Fraction::operator<=(const Fraction &other) const
{
    return (*this < other) || (*this == other);
}

bool Fraction::operator>=(const Fraction &other) const
{
    return (*this > other) || (*this == other);
}

// ************************************************************//

Fraction Fraction::operator+(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator+(other_frac);
}
Fraction Fraction::operator-(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator-(other_frac);
}
Fraction Fraction::operator*(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator*(other_frac);
}
Fraction Fraction::operator/(const float other)
{
    if (other == 0.0)
    {
        throw std::runtime_error("can't devide by zero");
    }
    Fraction other_frac = Fraction(other);
    return this->operator/(other_frac);
}

// ************************************************************//

bool Fraction::operator==(const float other)
{
    return *this == Fraction(other);
}

bool Fraction::operator!=(const float other)
{
    return !(*this == Fraction(other));
}

bool Fraction::operator<(const float other)
{
    return *this < Fraction(other);
}

bool Fraction::operator>(const float other)
{
    return *this > Fraction(other);
}

bool Fraction::operator<=(const float other)
{
    return *this <= Fraction(other);
}

bool Fraction::operator>=(const float other)
{
    return *this >= Fraction(other);
}

// ************************************************************//

Fraction ariel::operator+(float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator+(frac);
}
Fraction ariel::operator-(const float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator-(frac);
}
Fraction ariel::operator*(const float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator*(frac);
}
Fraction ariel::operator/(const float num, const Fraction &frac)
{
    if (frac.getNumerator() == 0)
    {
        throw std::runtime_error("can't devide by zero");
    }
    Fraction other_frac = Fraction(num);
    return other_frac.operator/(frac);
}

// ************************************************************//

bool ariel::operator==(const float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator==(frac);
}
bool ariel::operator!=(const float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator!=(frac);
}
bool ariel::operator<(const float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator<(frac);
}
bool ariel::operator>(const float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator>(frac);
}
bool ariel::operator<=(const float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator<=(frac);
}
bool ariel::operator>=(const float num, const Fraction &frac)
{
    Fraction other_frac = Fraction(num);
    return other_frac.operator>=(frac);
}

// ************************************************************//

Fraction &Fraction::operator++()
{
    long long new_nume = (long long)numerator + (long long)denominator;
    if (new_nume > INT_MAX || new_nume < INT_MIN)
    {
        throw std::overflow_error("Overflow error: the result of the operation is out of range for an int.");
    }
    numerator = (int)new_nume;
    return *this;
}

Fraction &Fraction::operator--()
{
    long long new_nume = (long long)numerator - (long long)denominator;
    if (new_nume > INT_MAX || new_nume < INT_MIN)
    {
        throw std::overflow_error("Overflow error: the result of the operation is out of range for an int.");
    }
    numerator = (int)new_nume;
    return *this;
}

Fraction Fraction::operator++(int num)
{
    Fraction this_frac = *this;
    this->operator++();
    return this_frac;
}

Fraction Fraction::operator--(int num)
{
    Fraction this_frac = *this;
    this->operator--();
    return this_frac;
}

// ************************************************************//

ostream &ariel::operator<<(ostream &os, const Fraction &frac)
{

    os << frac.getNumerator() << "/" << frac.getDenominator();
    return os;
}

istream &ariel::operator>>(istream &is, Fraction &frac)
{
    int numerator;
    int denominator = 0;

    is >> numerator;
    is >> denominator;

    if (denominator == 0)
    {
        throw runtime_error("there are no arguments");
    }
    frac.setNumerator(numerator);
    frac.setDenominator(denominator);

    if (frac.getDenominator() < 0)
    {
        frac.setNumerator(numerator * -1);
        frac.setDenominator(denominator * -1);
    }
    return is;
}

// ************************************************************//

int ariel::Fraction::gcd(int a, int b) const
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

Fraction ariel::Fraction::reduceFraction(const Fraction &frac) const
{
    int num = frac.getNumerator();
    int den = frac.getDenominator();

    if (den < 0)
    {
        den *= -1;
        num *= -1;
    }
    int gcd_value = gcd(num, den);

    return Fraction(num / gcd_value, den / gcd_value);
}
