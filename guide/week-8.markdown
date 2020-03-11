---
title: Week 8 notes
layout: default
categories: [studyguides]
---

# Week 8 notes

## Pair class

`pair.h`

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
        double operator[](const int idx) const;
        double operator[](const string &pos) const;
        void print() const;

    private:
        double x, y;
};
```

`pair.cpp`

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


double Pair::operator[](const int idx) const {
    if(idx == 0) {
        return x;
    } else {
        return y;
    }
}

double Pair::operator[](const string &pos) const {
    if(pos == "x") {
        return x;
    } else {
        return y;
    }
}
```

`main.cpp`

```
#include "pair.h"
#include <iostream>
using namespace std;

int main() {

    Pair p1(5, 2);
    Pair p2(p1);
    p1.print();
    p2.print();
    Pair p3 = p1 + p2;
    p3.print();
    Pair p4 = p1 + 5;
    p4.print();
    
    cout << "Pair p1 x value: " << p1[0] << endl;
    cout << "Pair p1 x value: " << p1["y"] << endl;

    return 0;
}
```
