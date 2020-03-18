---
layout: default
title: "HW05: Happy Arrays"
due: "Fri Mar 20, 11:59pm"
categories: [assignments]
---

# HW05: Happy Arrays

Create a class (`.cpp` and `.h` files) and a Makefile (include a "clean" target). The class should be named `A`, meaning "array", and should behave as described below. The `main.cpp` provided below must produce the output specified. Use the `main.cpp` file given, do not modify it.

**Avoid all memory leaks.** Check with valgrind.

## Behavior for class "A"

The A class stores an array or list of double values. Every A object has at least one value.

Constructors:

- `A(5.5)` -- initialize with a single value.
- `A(5.5, 10)` -- repeat a single value 10 times.
- `A(a, 3)` -- copy another array 3 times (appended left-to-right).
- `A(start, end, by)` -- create an array starting at value `start` and increasing by `by` each element until `end` is reached.
- copy constructor -- copy another array.

Methods:

- `a.print()` -- print array with spaces between elements and newline at the end.
- `a.slice(start, end)` -- return a new array with values from original array from positions `start` to `end` (inclusive).
- `a.append(b)` -- return a new array with `b` appended on the right side of `a`.

Overloaded operators:

- `a[i]` -- return or set value at position `i` (counting starts at 0, as usual).
- `a+b` -- return a new array that is the element-by-element sum of arrays `a` and `b`; **see arithmetic rules below**.
- `a-b` -- return a new array that is the element-by-element difference of arrays `a` and `b`; **see arithmetic rules below**.

## Arithmetic rules

When adding/subtracting two arrays of the same size, the operation is performed element-by-element. For example, array "1 2 3" plus array "5 6 7" produces an array "(1+5) (2+6) (3+7)", i.e., "6 8 10". Same for subtraction.

If the two arrays are not the same size, we have two cases to handle:

- If one array is an integer multiple of the size of the other, say the size of `a` is a multiple of the size of `b`, then the smaller array (`b`) is repeated enough times to make the two sizes match. Then the normal element-by-element operation is performed. For example, array "1 2 3" plus array "6" copies the 6 three times to produce the addition "1 2 3" plus "6 6 6", resulting in array "7 8 9".
- If neither array is an integer multiple of the size of the other, the operation cannot be performed, so return an array containing a single 0.0 value.

## main.cpp

```
#include "A.h"

#include <iostream>
using namespace std;

int main()
{
    A a(37);
    A b(37, 10);
    A c(b);
    A d(b, 3);
    A e(1, 10, 2);
    A f(-5.5, -4.75, 0.1);

    cout << "a: "; a.print();
    cout << "b: "; b.print();
    cout << "c: "; c.print();
    cout << "d: "; d.print();
    cout << "e: "; e.print();
    cout << "f: "; f.print();

    cout << "e[2]: " << e[2] << endl;
    b[2] = -10;
    cout << "b: "; b.print();

    A g = e.slice(1, 3);
    cout << "g: "; g.print();
    A h = e.slice(2, 2);
    cout << "h: "; h.print();

    A i = e.append(f);
    cout << "i: "; i.print();

    A j = a+e;
    A k = e+a;
    cout << "j: "; j.print();
    cout << "k: "; k.print();

    A l = e+g;
    A m = g+e;
    cout << "l: "; l.print();
    cout << "m: "; m.print();

    A n = j+k;
    cout << "n: "; n.print();

    A o = b+e;
    A p = e+b;
    cout << "o: "; o.print();
    cout << "p: "; p.print();

    A q = a-e;
    A r = e-a;
    cout << "q: "; q.print();
    cout << "r: "; r.print();

    A s = e-g;
    A t = g-e;
    cout << "s: "; s.print();
    cout << "t: "; t.print();

    A u = j-k;
    cout << "u: "; u.print();

    A v = b-e;
    A w = e-b;
    cout << "v: "; v.print();
    cout << "w: "; w.print();

    return 0;
}
```

## Expected output

```
a: 37
b: 37 37 37 37 37 37 37 37 37 37
c: 37 37 37 37 37 37 37 37 37 37
d: 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37 37
e: 1 3 5 7 9
f: -5.5 -5.4 -5.3 -5.2 -5.1 -5 -4.9 -4.8
e[2]: 5
b: 37 37 -10 37 37 37 37 37 37 37
g: 3 5 7
h: 5
i: 1 3 5 7 9 -5.5 -5.4 -5.3 -5.2 -5.1 -5 -4.9 -4.8
j: 38 40 42 44 46
k: 38 40 42 44 46
l: 0
m: 0
n: 76 80 84 88 92
o: 38 40 -5 44 46 38 40 42 44 46
p: 38 40 -5 44 46 38 40 42 44 46
q: 36 34 32 30 28
r: -36 -34 -32 -30 -28
s: 0
t: 0
u: 0 0 0 0 0
v: 36 34 -15 30 28 36 34 32 30 28
w: -36 -34 15 -30 -28 -36 -34 -32 -30 -28
```

