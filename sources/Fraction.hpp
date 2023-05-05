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
        Fraction()
        {
            numerator = 1;
            denominator = 1;
        }

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
        Fraction operator+(const Fraction &other);
        Fraction operator-(const Fraction &other);
        Fraction operator*(const Fraction &other);
        Fraction operator/(const Fraction &other);
        bool operator==(const Fraction &other);
        bool operator!=(const Fraction &other);
        bool operator<(const Fraction &other);
        bool operator>(const Fraction &other);
        bool operator<=(const Fraction &other);
        bool operator>=(const Fraction &other);

        Fraction operator+(const float other);
        Fraction operator-(const float other);
        Fraction operator*(const float other);
        Fraction operator/(const float other);
        bool operator==(const float other);
        bool operator!=(const float other);
        bool operator<(const float other);
        bool operator>(const float other);
        bool operator<=(const float other);
        bool operator>=(const float other);

        friend Fraction operator+(float num, const Fraction &frac);
        friend Fraction operator-(float num, const Fraction &frac);
        friend Fraction operator*(float num, const Fraction &frac);
        friend Fraction operator/(float num, const Fraction &frac);
        friend bool operator==(const float num, const Fraction &frac);
        friend bool operator!=(const float num, const Fraction &frac);
        friend bool operator<(const float num, const Fraction &frac);
        friend bool operator>(const float num, const Fraction &frac);
        friend bool operator<=(const float num, const Fraction &frac);
        friend bool operator>=(const float num, const Fraction &frac);

        Fraction &operator++();
        Fraction &operator--();
        Fraction operator++(int);
        Fraction operator--(int);

        friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);
        friend std::istream &operator>>(std::istream &is, Fraction &frac);

        int gcd(int a, int b);
        Fraction reduceFraction(Fraction frac);
        Fraction float_to_fraction(float num);
    };
}