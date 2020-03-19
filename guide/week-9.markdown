---
title: Week 9 notes
layout: default
categories: [studyguides]
---

# Week 9 notes

We revisited the Pair class but with more operator overloads.

## pair.h

```
#include <string>
using namespace std;

// A Pair has two double values: x, y
// We want some convenience functions
// like Pair a, Pair b, define a+b, a-b, etc.

class Pair {

    public:
        Pair(double x, double y);
        Pair(const Pair &other);

        Pair operator+(const Pair &other) const;
        Pair operator+(int val) const;
        Pair operator~() const;
        double& operator[](const int idx);
        Pair operator++(int);
        Pair& operator++();
        void print() const;
        operator double() const;
        bool operator!() const;

        friend ostream& operator<<(ostream &stream, const Pair& p);

    private:
        double x, y;
};

ostream& operator<<(ostream&, const Pair&);
```

## pair.cpp

```
#include "pair.h"
#include <iostream>
using namespace std;

Pair::Pair(double x, double y) {
    this->x = x;
    this->y = y;
}

Pair::Pair(const Pair &other) {
    this->x = other.x;
    this->y = other.y;
}

void Pair::print() const {
    cout << "Pair(" << x << "," << y << ")" << endl;
}

Pair Pair::operator+(const Pair &other) const {
    Pair p(x+other.x, y+other.y);
    return p;
}

Pair Pair::operator+(int val) const {
    Pair p(x+val, y+val);
    return p;
}

Pair Pair::operator~() const {
    Pair p(-x, -y);
    return p;
}

double& Pair::operator[](const int idx) {
    if(idx == 0) {
        return x;
    } else {
        return y;
    }
}

Pair Pair::operator++(int) {
    x++;
    y++;
    return Pair(x-1, y-1);
}

Pair& Pair::operator++() {
    x++;
    y++;
    return *this; // return myself
}

Pair::operator double() const {
    return x*y;
}

bool Pair::operator!() const {
    return (x <= 0 && y <= 0);
}

ostream& operator<<(ostream &stream, const Pair& p) {
    stream << "Pair: " << p.x << "," << p.y;
    return stream;
}
```

