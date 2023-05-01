#pragma once
#include <iostream>
// using namespace ariel;
using namespace std;


/**
 * @about: Fraction header file for Fraction class, Task 3 - Systems programing N.2 course.
 * @author Itamar Kuznitsov.
 * @since 2023
*/



namespace ariel{
    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        // constructor
        Fraction(int, int);
        Fraction(const Fraction &);
        Fraction(const float &flo);
        Fraction();

        // destructor
        ~Fraction();

        // Move constructor
        Fraction(Fraction&& other) noexcept;

        // Move assignment operator
        Fraction& operator=(Fraction&& other) noexcept;
        Fraction& operator=(const Fraction &fra);

        // assistance functions
        static Fraction reduce_fraction(const Fraction &fra);
        static Fraction float_to_fraction(float number);
        static float fraction_to_float(Fraction fra);
        int getNumerator() const;
        int getDenominator() const;


        // 2 fractions
        friend Fraction operator+(const Fraction &fra1, const Fraction &fra2);
        friend Fraction operator-(const Fraction &fra1, const Fraction &fra2);
        friend Fraction operator*(const Fraction &fra1, const Fraction &fra2);
        friend Fraction operator/(const Fraction &fra1, const Fraction &fra2);
        friend bool operator==(const Fraction &fra1, const Fraction &fra2);
        friend bool operator>(const Fraction &fra1, const Fraction &fra2);
        friend bool operator<(const Fraction &fra1, const Fraction &fra2);
        friend bool operator>=(const Fraction &fra1, const Fraction &fra2);
        friend bool operator<=(const Fraction &fra1, const Fraction &fra2);

        // 1 fraction 1 float
        friend Fraction operator+(const Fraction &fra, const float &flo);
        friend Fraction operator-(const Fraction &fra, const float &flo);
        friend Fraction operator*(const Fraction &fra, const float &flo);
        friend Fraction operator/(const Fraction &fra, const float &flo);
        friend bool operator==(const Fraction &fra, const float &flo);
        friend bool operator>(const Fraction &fra, const float &flo);
        friend bool operator<(const Fraction &fra, const float &flo);
        friend bool operator>=(const Fraction &fra, const float &flo);
        friend bool operator<=(const Fraction &fra, const float &flo);

        // 1 float 1 fraction   
        friend Fraction operator+(const float &flo, const Fraction &fra);
        friend Fraction operator-(const float &flo, const Fraction &fra);
        friend Fraction operator*(const float &flo, const Fraction &fra);
        friend Fraction operator/(const float &flo, const Fraction &fra);
        friend bool operator==(const float &flo, const Fraction &fra);
        friend bool operator>(const float &flo, const Fraction &fra);
        friend bool operator<(const float &flo, const Fraction &fra);
        friend bool operator>=(const float &flo, const Fraction &fra);
        friend bool operator<=(const float &flo, const Fraction &fra);

        // stdin & stdout: 
        friend std::ostream &operator<<(std::ostream &output, const Fraction &fra);
        friend std::istream &operator>>(std::istream &input, Fraction &fra);

        // prefix increment:
        Fraction &operator++()
        {
            this->numerator += this->denominator;
            *this = reduce_fraction(*this);
            return *this;
        }

        // postfix increment: int indicates postfix increment
        Fraction operator++(int)
        {
            // save the currunt fraction, update the original and return the first one.
            Fraction tmp_fraction(*this);

            this->numerator += this->denominator;
            *this = reduce_fraction(*this);
            return tmp_fraction;
        }

        // prefix increment:
        Fraction &operator--()
        {
            this->numerator -= this->denominator;
            *this = reduce_fraction(*this);
            return *this;
        }

        // postfix increment: int indicates postfix increment
        Fraction operator--(int)
        {
            // save the currunt fraction, update the original and return the first one.
            Fraction tmp_fraction(*this);

            this->numerator -= this->denominator;
            *this = reduce_fraction(*this);
            return tmp_fraction;
        }
    };
}