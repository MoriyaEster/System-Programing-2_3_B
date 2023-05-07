#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>

namespace ariel
{

    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int _numerator, int _denominator);
        Fraction(float num);
        Fraction(double num);
        Fraction();

        int getNumerator() const
        {
            return this->numerator;
        }
        int getDenominator() const
        {
            return this->denominator;
        }

        void setNumerator(int num)
        {
            this->numerator = num;
        }
        void setDenominator(int num)
        {
            this->denominator = num;
        }

        // Operators
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;

        Fraction operator+(float other);
        Fraction operator-(float other);
        Fraction operator*(float other);
        Fraction operator/(float other);
        bool operator==(float other);
        bool operator!=(float other);
        bool operator<(float other);
        bool operator>(float other);
        bool operator<=(float other);
        bool operator>=(float other);

        friend Fraction operator+(float num, const Fraction &frac);
        friend Fraction operator-(float num, const Fraction &frac);
        friend Fraction operator*(float num, const Fraction &frac);
        friend Fraction operator/(float num, const Fraction &frac);
        friend bool operator==(float num, const Fraction &frac);
        friend bool operator!=(float num, const Fraction &frac);
        friend bool operator<(float num, const Fraction &frac);
        friend bool operator>(float num, const Fraction &frac);
        friend bool operator<=(float num, const Fraction &frac);
        friend bool operator>=(float num, const Fraction &frac);

        Fraction &operator++();
        Fraction &operator--();
        Fraction operator++(int);
        Fraction operator--(int);

        friend std::ostream &operator<<(std::ostream &outs, const Fraction &frac);
        friend std::istream &operator>>(std::istream &inputs, Fraction &frac);

        int gcd(int aaa, int bbb) const;
        Fraction reduceFraction(const Fraction &frac) const;
    };
}