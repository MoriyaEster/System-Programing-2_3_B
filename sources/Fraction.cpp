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
    float_to_fraction(num);
}

Fraction::Fraction(int _numerator, int _denominator)
    : numerator(_numerator), denominator(_denominator)
{
    if (_denominator == 0)
    {
        throw invalid_argument("can't devide by zero");
    }
}

Fraction::Fraction(double num)
{
    Fraction(float(num));
}

Fraction Fraction::operator+(const Fraction &other)
{

    int lcm = (denominator * other.denominator) / gcd(denominator, other.denominator);
    int new_numerator = (numerator * (lcm / denominator)) + (other.numerator * (lcm / other.denominator));
    int new_denominator = lcm;

    Fraction result(new_numerator, new_denominator);
    result = reduceFraction(result);

    return result;
}

Fraction Fraction::operator-(const Fraction &other)
{
    long long new_nume = ((long long)numerator * other.denominator) - ((long long)other.numerator * denominator);
    long long new_denom = (long long)denominator * other.denominator;
    Fraction new_frac = Fraction(new_nume, new_denom);
    return reduceFraction(new_frac);
}
Fraction Fraction::operator*(const Fraction &other)
{
    // Multiply numerators and denominators
    long long new_nume = (long long)this->getNumerator() * (long long)other.getNumerator();
    long long new_denom = (long long)this->getDenominator() * (long long)other.getDenominator();

    // Check for overflow
    if (new_nume > INT_MAX || new_nume < INT_MIN || new_denom > INT_MAX || new_denom < INT_MIN)
    {
        throw std::overflow_error("Overflow error: the result of the multiplication is out of range for an int.");
    }

    // Create and reduce new fraction
    Fraction new_frac(new_nume, new_denom);
    new_frac = reduceFraction(new_frac);

    return new_frac;
}
Fraction Fraction::operator/(const Fraction &other)
{
    if (other.getNumerator() == 0)
    {
        throw invalid_argument("can't devide by zero");
    }
    int this_nume = this->getNumerator();
    int this_denom = this->getDenominator();
    int other_nume = other.getNumerator();
    int other_denom = other.getDenominator();

    Fraction new_frac = Fraction(this_nume * other_denom, this_denom * other_nume);
    return new_frac;
}

bool Fraction::operator==(const Fraction &other)
{
    if ((this->operator-(other)).getNumerator() == 0)
        return true;
    else
        return false;
}
bool Fraction::operator!=(const Fraction &other)
{
    if ((this->operator-(other)).getNumerator() != 0)
        return true;
    else
        return false;
}
bool Fraction::operator<(const Fraction &other)
{
    if ((this->operator-(other)).getNumerator() < 0)
        return true;
    else
        return false;
}
bool Fraction::operator>(const Fraction &other)
{
    if ((this->operator-(other)).getNumerator() > 0)
        return true;
    else
        return false;
}
bool Fraction::operator<=(const Fraction &other)
{
    if ((this->operator-(other)).getNumerator() <= 0)
        return true;
    else
        return false;
}
bool Fraction::operator>=(const Fraction &other)
{
    if ((this->operator-(other)).getNumerator() >= 0)
        return true;
    else
        return false;
}

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
        throw std::invalid_argument("can't devide by zero");
    }
    Fraction other_frac = Fraction(other);
    return this->operator/(other_frac);
}

bool Fraction::operator==(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator==(other_frac);
}
bool Fraction::operator!=(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator!=(other_frac);
}
bool Fraction::operator<(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator<(other_frac);
}
bool Fraction::operator>(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator>(other_frac);
}
bool Fraction::operator<=(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator<=(other_frac);
}
bool Fraction::operator>=(const float other)
{
    Fraction other_frac = Fraction(other);
    return this->operator>=(other_frac);
}

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
        throw std::invalid_argument("can't devide by zero");
    }
    Fraction other_frac = Fraction(num);
    return other_frac.operator/(frac);
}

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

Fraction &Fraction::operator++()
{
    this->numerator += this->denominator;
    return *this;
}
Fraction &Fraction::operator--()
{
    this->numerator -= this->denominator;
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

std::ostream &ariel::operator<<(std::ostream &os, const Fraction &frac)
{
    os << frac.getNumerator() << "/" << frac.getDenominator();
    return os;
}

std::istream &ariel::operator>>(std::istream &is, Fraction &frac)
{
    return is;
}

int ariel::Fraction::gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

Fraction ariel::Fraction::reduceFraction(Fraction frac)
{
    int frac_nume = frac.getNumerator();
    int frac_denom = frac.getDenominator();

    int num_to_reduce = gcd(frac_nume, frac_denom);

    int new_frac_nume = frac_nume / num_to_reduce;
    int new_frac_denom = frac_denom / num_to_reduce;

    return Fraction(new_frac_nume, new_frac_denom);
}

Fraction ariel::Fraction::float_to_fraction(float num)
{
    if (num == 0.0)
    {
        return Fraction(0, 1);
    }
    cout << "num = " << num << endl;
    int new_num = num * 1000;
    cout << "new_num = " << new_num << endl;
    Fraction new_frac = Fraction(new_num, 1000);
    Fraction reduc_frac = reduceFraction(new_frac);
    cout << "reduc_frac.getNumerator = " << reduc_frac.getNumerator() << " reduc_frac.getDenominator = " << reduc_frac.getDenominator() << endl;
    return reduc_frac;
}
