#include "doctest.h"
#include "sources/Fraction.hpp"
#include <stdexcept>

using namespace ariel;
using namespace doctest;

/**
 * @about: Test file(using doctest) for Fraction class, Task 3 - Systems programing N.2 course.
 * @author Itamar Kuznitsov.
 * @since 2023
*/



// check fraction initialization cases.
TEST_CASE("Fraction initialization")
{
    CHECK_NOTHROW(Fraction(5, 3)); // valid
    CHECK_NOTHROW(Fraction(14, 21));

    CHECK_THROWS(Fraction(3, 0));     // invalid
    CHECK_NOTHROW(Fraction(0, 3));    // valid
    CHECK_NOTHROW(Fraction(0.1234));  // valid
    CHECK_NOTHROW(Fraction(-0.1234)); // valid
    CHECK_NOTHROW(Fraction(-1, -2));  // valid
    CHECK_NOTHROW(Fraction(-0, 3));   // valid
    CHECK_NOTHROW(Fraction(-1, 3));   // valid
    CHECK_NOTHROW(Fraction(1, -3));   // valid

    Fraction a(1, 4), b(0.1234);
    CHECK(((a.getNumerator() == 1) && (a.getDenominator() == 4)));
    CHECK(((b.getNumerator() == 123) && (b.getDenominator() == 1000)));
}

// check basic operators functionality with float.
TEST_CASE("Fraction basic operators functionality with float")
{
    Fraction a(1, 2);
    CHECK((a + 1) == Fraction(3, 2));
    CHECK((a + 0.5) == Fraction(1, 1));

    CHECK((a - 0.5) == Fraction(0, 1));

    CHECK((a * 1) == a);
    CHECK((a * 0) == Fraction(0, 1));
    CHECK(a > 0);
    CHECK(a >= 0.5);
    CHECK(a < 2);
    CHECK(a <= 0.5);

    CHECK((a / 1) == a);
    CHECK((0 / a) == Fraction(0, 1));
}

// check basic operators functionality with another fraction.
TEST_CASE("Fraction basic operators functionality with another fraction")
{
    Fraction a(1, 2), b(1, 2);
    CHECK((a + b) == Fraction(1, 1));
    CHECK((a + b + b) == Fraction(3, 2));
    CHECK((a - b) == Fraction(0, 1));
    CHECK((a * b) == Fraction(1, 4));
    CHECK((a / b) == Fraction(1, 1));

    CHECK(a > Fraction(0, 1));
    CHECK(a >= Fraction(1, 2));
    CHECK(a < Fraction(2, 1));
    CHECK(a <= Fraction(1, 2));
}

// check basic operators functionality fraction+float.
TEST_CASE("Fraction basic operators functionality fraction+float")
{
    Fraction a(1, 2), b(1, 2);
    CHECK((a + b - 1) == Fraction(0, 1));
    CHECK((a + b + b - 1) == Fraction(1, 2));
    CHECK((a - b + 1) == Fraction(1, 1));
    CHECK((a * 1 * b) == Fraction(1, 4));
    CHECK((a * 0 * b) == Fraction(0, 1));
    CHECK((a / b + 1) == Fraction(2, 1));
    CHECK((a + b + 2.421) == 3.421);
}

// check ++/-- operators.
TEST_CASE("Fraction with ++/-- operators")
{
    Fraction a(0, 1), b(50, 1);
    for (int i = 0; i < 50; i++)
    {
        CHECK((a++) == Fraction(i, 1));
    }

    for (int i = 50; i > 0; i--)
    {
        CHECK((b--) == Fraction(i, 1));
    }
    CHECK(--(++a) == a);
}

// check oppertor == with fraction and float.
TEST_CASE("Check equality")
{
    Fraction a(1, 2);
    Fraction b(1, 5);
    Fraction c(2, 4);
    Fraction d(1, 5);
    Fraction e(-1, 2);
    Fraction f(-1, -2);

    CHECK(b == d);
    CHECK(a == c);
    CHECK_FALSE(a == b);
    CHECK(a == 0.5);
    CHECK(0.5 == a);
    CHECK_FALSE(a == 0.6);
    CHECK_FALSE(0.8 == a);
    CHECK_NE(a,e);
    CHECK_EQ(a,f);
}

// check fraction after multiple operations.
TEST_CASE("Fraction multiple operators")
{
    Fraction a(1, 2), b(1, 2), c(1, 4);
    CHECK((a + b) * a == Fraction(1, 2));
    CHECK(a + c == Fraction(3, 4));
    CHECK(c + a == Fraction(3, 4));
    CHECK(b + c == Fraction(3, 4));
    CHECK(c + c == Fraction(1, 2));
    CHECK(c + c == Fraction(0.5));
}

// check fraction made from float + fraction .
TEST_CASE("Check float to fraction process")
{
    Fraction a(3, 10);
    float b = 0.1001;
    Fraction c = a + b;
    CHECK(c == Fraction(4, 10));
    CHECK(((c.getNumerator() == 2) && (c.getDenominator() == 5)));
}