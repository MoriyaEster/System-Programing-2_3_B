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
        Fraction(int _numerator, int denominator);
        Fraction(float num);

        int getnumerator() const
        {
            return numerator;
        }
        int getdenominator() const
        {
            return denominator;
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

        friend Fraction& operator+(const float num, Fraction &frac);
        friend Fraction& operator-(const float num, Fraction &frac);
        friend Fraction& operator*(const float num, Fraction &frac);
        friend Fraction& operator/(const float num, Fraction &frac);
        friend bool operator==(const float num, Fraction &frac);
        friend bool operator!=(const float num, Fraction &frac);
        friend bool operator<(const float num, Fraction &frac);
        friend bool operator>(const float num, Fraction &frac);
        friend bool operator<=(const float num, Fraction &frac);
        friend bool operator>=(const float num, Fraction &frac);

        Fraction& operator++();
        Fraction& operator--();
        Fraction operator++(int);
        Fraction operator--(int);

        friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);
        friend std::istream &operator>>(std::istream &is, Fraction &frac);
    };
}