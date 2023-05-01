#include "Fraction.hpp"
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cmath>
// using namespace ariel;
using namespace std;


/**
 * @about: Fraction class implementation, Task 3 - Systems programing N.2 course.
 * @author Itamar Kuznitsov.
 * @since 2023
*/


namespace ariel{

// constructor
Fraction:: Fraction(int numer, int denom)
    : numerator(numer), denominator(denom){
        if(denom == 0)
            throw std::invalid_argument("invalid denominator");
        // TODO(I): update sighn of the fraction.
        else if(denom < 0){
            this->numerator *= -1;
            this->denominator *= -1;
        }
        reduce_fraction(*this); 
    }


Fraction:: Fraction(const Fraction& f)
    :numerator(f.numerator), denominator(f.denominator){}


Fraction:: Fraction(const float &flo)
    :numerator(flo*1000), denominator(1000){
        reduce_fraction(*this); 
    }


Fraction:: Fraction()
    : numerator(0), denominator(1) {}

// destructor
Fraction:: ~Fraction(){}



// move constructor:
Fraction::Fraction(Fraction&& other) noexcept :
    numerator(other.numerator),
    denominator(other.denominator)
{
    other.numerator = 0;
    other.denominator = 1;
}

Fraction& Fraction::operator=(Fraction&& other) noexcept {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
        other.numerator = 0;
        other.denominator = 1;
    }
    return *this;
}



// getters:
int  Fraction:: getNumerator() const{
    return this->numerator;
}
int Fraction:: getDenominator() const{
    return this->denominator;
}


// return fraction in reduced form
Fraction Fraction:: reduce_fraction(const Fraction& fra){
    return Fraction();
}

// return given float as a fraction. 
Fraction Fraction:: float_to_fraction(float number){
    return Fraction();
}

// return given fraction as a float.
float Fraction:: fraction_to_float(Fraction fra){
    return 1;
}



// 2 fractions
Fraction operator+ (const Fraction& fra1, const Fraction& fra2){
    return Fraction();
}

Fraction operator- (const Fraction& fra1, const Fraction& fra2){
    return Fraction();
}

Fraction operator* (const Fraction& fra1, const Fraction& fra2){
    return Fraction();}

Fraction operator/(const Fraction& fra1, const Fraction& fra2){
    return Fraction();}

bool operator==(const Fraction& fra1, const Fraction& fra2){
    return 1;
}

bool operator>(const Fraction& fra1, const Fraction& fra2){
    return 1;
}

bool operator<(const Fraction& fra1, const Fraction& fra2){
    return 1;
}

bool operator>=(const Fraction& fra1, const Fraction& fra2){
    return 1;
}

bool operator<=(const Fraction& fra1, const Fraction& fra2){
    return 1;
}






// 1 float 1 fraction 
Fraction operator+ (const Fraction& fra, const float &flo){
    return Fraction();
}

Fraction operator- (const Fraction& fra, const float &flo){
    return Fraction();
}


Fraction operator* (const Fraction& fra, const float &flo){
    return Fraction();
}    
    
Fraction operator/(const Fraction& fra, const float &flo){
    return Fraction();
}


bool operator==(const Fraction& fra, const float &flo){
    return 1;
}

bool operator>(const Fraction& fra, const float &flo){
    return 1;
}

bool operator<(const Fraction& fra, const float &flo){
    return 1;
}

bool operator>=(const Fraction& fra, const float &flo){
    return 1;
}

bool operator<=(const Fraction& fra, const float &flo){
    return 1;
}






// 1 fraction 1 float
Fraction operator+ (const float &flo, const Fraction& fra){
    return Fraction();
}

Fraction operator- (const float &flo, const Fraction& fra){
    return Fraction();
}

Fraction operator* (const float &flo, const Fraction& fra){
    return Fraction();
} 

Fraction operator/(const float &flo, const Fraction& fra){
    return Fraction();
}

bool operator==(const float &flo, const Fraction& fra){
    return 1;
}

bool operator>(const float &flo, const Fraction& fra){
    return 1;
}

bool operator<(const float &flo, const Fraction& fra){
    return 1;
}

bool operator>=(const float &flo, const Fraction& fra){
    return 1;
}

bool operator<=(const float &flo, const Fraction& fra){
    return 1;
}

Fraction& Fraction:: operator=(const Fraction& fra){
    return *this;
}



// output overloading
ostream& operator<< (ostream& output, const Fraction& fra){
    output << fra.numerator << "/" << fra.denominator;
    return output;
}

// input overloading
istream& operator>> (istream& input , Fraction& fra){
    char slash;
    if(input >> fra.numerator >> slash >> fra.denominator){
        // not a fraction input
        if(slash != '/')
            input.setstate(ios::failbit);
        
        // denominator is 0:
        else if(fra.denominator == 0)
            input.setstate(ios::failbit);
    }
    return input;
}

}

// end of program.