#include <stdio.h>
#include <iostream>
#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction(float num)
{
    float_to_fraction(num);
}

Fraction::Fraction(int _numerator, int _denominator)
    : numerator(_numerator), denominator(_denominator)
{
}

Fraction::Fraction(double num)
{
    Fraction(float(num));
}

Fraction Fraction::operator+(const Fraction &other)
{
    int this_nume = this->getNumerator();
    int this_denom = this->getDenominator();
    int other_nume = other.getNumerator();
    int other_denom = other.getDenominator();

    int frac1_new_nume = this_nume * other_denom;
    int frac1_new_denom = this_denom * other_denom;
    int frac2_new_nume = other_nume * this_denom;
    int frac2_new_denom = other_denom * this_denom;

    Fraction new_frac = Fraction(frac1_new_nume + frac2_new_nume, frac1_new_denom);
    return new_frac;
}
Fraction Fraction::operator-(const Fraction &other)
{
    int this_nume = this->getNumerator();
    int this_denom = this->getDenominator();
    int other_nume = other.getNumerator();
    int other_denom = other.getDenominator();

    int frac1_new_nume = this_nume * other_denom;
    int frac1_new_denom = this_denom * other_denom;
    int frac2_new_nume = other_nume * this_denom;
    int frac2_new_denom = other_denom * this_denom;

    Fraction new_frac = Fraction(frac1_new_nume - frac2_new_nume, frac1_new_denom);
    return new_frac;
}
Fraction Fraction::operator*(const Fraction &other)
{
    int this_nume = this->getNumerator();
    int this_denom = this->getDenominator();
    int other_nume = other.getNumerator();
    int other_denom = other.getDenominator();

    Fraction new_frac = Fraction(this_nume * other_nume, this_denom * other_denom);
    return new_frac;
}
Fraction Fraction::operator/(const Fraction &other)
{
    int this_nume = this->getNumerator();
    int this_denom = this->getDenominator();
    int other_nume = other.getNumerator();
    int other_denom = other.getDenominator();

    Fraction new_frac = Fraction(this_nume * other_denom, this_denom * other_nume);
    return new_frac;
}

bool Fraction::operator==(const Fraction &other)
{
    if (this->operator-(other) == 0)
        return true;
    else
        return false;
}
bool Fraction::operator!=(const Fraction &other)
{
    if (this->operator-(other) != 0)
        return true;
    else
        return false;
}
bool Fraction::operator<(const Fraction &other)
{
    if (this->operator-(other) < 0)
        return true;
    else
        return false;
}
bool Fraction::operator>(const Fraction &other)
{
    if (this->operator-(other) > 0)
        return true;
    else
        return false;
}
bool Fraction::operator<=(const Fraction &other)
{
    if (this->operator-(other) <= 0)
        return true;
    else
        return false;
}
bool Fraction::operator>=(const Fraction &other)
{
    if (this->operator-(other) >= 0)
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
    int new_num = num * 1000;
    Fraction new_frac = Fraction(new_num, 1000);
    Fraction reduc_frac = reduceFraction(new_frac);
    return reduc_frac;
}
