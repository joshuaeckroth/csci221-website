---
layout: default
title: "HW06: Rational Overload"
due: "Fri Mar 27, 11:59pm"
categories: [assignments]
---

# HW06: Rational Overload

Implement a rational class (fractions) that overloads numerous operators. Make the testfile below pass all tests. Use the provided makefile. Refer to [cppreference](https://en.cppreference.com/w/cpp/language/operators) for guidance, particularly their Fractions example. Note, you don't need a gcd function like they have; our fractions do not need to be "reduced" (e.g., 5/10 does not convert to 1/2).

Here are the rules for various operations:

```
a/b + c/d = (a*d + b*c) / (b*d)
a/b - c/d = (a*d - b*c) / (b*d)
(a/b) * (c/d) = (a*c) / (b*d)
(a/b) / (c/d) = (a*d) / (c*b)
-(a/b) = (-a/b)
(a/b) < (c/d) means (a*d) < (c*b)
(a/b) == (c/d) means (a*d) == (c*b)

and we'll say *(a/b) means inverse: b/a
e.g., Rational a(5,2); Rational b = *a;
be sure to keep negative in numerator

// this should print as "5/3"
Rational myrational(5, 3);
cout << myrational << endl;
```

## main.cpp

```
#include <iostream>
#include "rational.h"
#include "gtest/gtest.h"
using namespace std;

TEST(rational, constructor)
{
    Rational a(5, 2);
    ASSERT_EQ(a.getNum(), 5);
    ASSERT_EQ(a.getDenom(), 2);
}

TEST(rational, minus)
{
    Rational a(5, 2);
    Rational b(3, 7);
    Rational c = a-b;
    ASSERT_EQ(c.getNum(), 29);
    ASSERT_EQ(c.getDenom(), 14);
}

TEST(rational, plus)
{
    Rational a(5, 2);
    Rational b(3, 7);
    Rational c = a+b;
    ASSERT_EQ(c.getNum(), 41);
    ASSERT_EQ(c.getDenom(), 14);
}

TEST(rational, negate)
{
    Rational b(3, 7);
    Rational c = -b;
    ASSERT_EQ(c.getNum(), -3);
    ASSERT_EQ(c.getDenom(), 7);
}

TEST(rational, complex_math)
{
    Rational a(5, 2);
    Rational b(3, 7);
    Rational c = *a+b*(-b/a);
    ASSERT_EQ(c.getNum(), 400);
    ASSERT_EQ(c.getDenom(), 1225);
}


TEST(rational, star)
{
    Rational b(3, 7);
    Rational c = *b;
    ASSERT_EQ(c.getNum(), 7);
    ASSERT_EQ(c.getDenom(), 3);
}

TEST(rational, comparison)
{
    Rational a(5, 2);
    Rational b(3, 7);
    Rational c(3, 7);
    ASSERT_EQ(a == a, true);
    ASSERT_EQ(a == c, false);
    ASSERT_EQ(a != c, true);
    ASSERT_EQ(a < b, false);
    ASSERT_EQ(a > b, true);
    ASSERT_EQ(a <= b, false);
    ASSERT_EQ(b <= c, true);
    ASSERT_EQ(a >= b, true);
    ASSERT_EQ(b >= c, true);
    ASSERT_EQ(c <= b, true);
    ASSERT_EQ(a <= a, true);
    ASSERT_EQ(a >= a, true);
}

TEST(rational, postincrement)
{
    Rational a(5, 2);
    Rational b = a++;
    ASSERT_EQ(a.getNum(), 7);
    ASSERT_EQ(a.getDenom(), 2);
    ASSERT_EQ(b.getNum(), 5);
    ASSERT_EQ(b.getDenom(), 2);
}

TEST(rational, preincrement)
{
    Rational a(5, 2);
    Rational b = ++a;
    ASSERT_EQ(a.getNum(), 7);
    ASSERT_EQ(a.getDenom(), 2);
    ASSERT_EQ(b.getNum(), 7);
    ASSERT_EQ(b.getDenom(), 2);
}

TEST(rational, postdecrement)
{
    Rational a(5, 2);
    Rational b = a--;
    ASSERT_EQ(a.getNum(), 3);
    ASSERT_EQ(a.getDenom(), 2);
    ASSERT_EQ(b.getNum(), 5);
    ASSERT_EQ(b.getDenom(), 2);
}

TEST(rational, predecrement)
{
    Rational a(5, 2);
    Rational b = --a;
    ASSERT_EQ(a.getNum(), 3);
    ASSERT_EQ(a.getDenom(), 2);
    ASSERT_EQ(b.getNum(), 3);
    ASSERT_EQ(b.getDenom(), 2);
}

TEST(rational, convert_double)
{
    Rational a(5, 2);
    double b = a;
    ASSERT_DOUBLE_EQ(b, 2.5);
}

TEST(rational, ostream)
{
    Rational a(5, 2);
    cout << a << endl;
    SUCCEED();
}

TEST(rational, istream)
{
    Rational a(5, 2);
    cout << "Enter two integers for numerator and denominator: ";
    cin >> a;
    cout << a << endl;
    SUCCEED();
}
```


## Makefile

```
GTEST_DIR = /opt/google-test/googletest
CXX = g++
CXXFLAGS = -std=c++11 -Wall -L$(GTEST_DIR)/lib -isystem $(GTEST_DIR)/include -Wextra -lpthread

all: test

test: main.o rational.o
    $(CXX) $(CXXFLAGS) -o test main.o rational.o $(GTEST_DIR)/lib/libgtest_main.a $(GTEST_DIR)/lib/libgtest.a

main.o: main.cpp rational.h
    $(CXX) $(CXXFLAGS) -c main.cpp

rational.o: rational.cpp rational.h
    $(CXX) $(CXXFLAGS) -c rational.cpp

.PHONY: clean
clean:
    rm -rf *.o test
```

