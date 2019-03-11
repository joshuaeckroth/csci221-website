---
layout: default
title: Test 1 from Spring 2018
categories: [studyguides]
---

# Test 1

Create a bitbucket repo called `csci221-test1`. **Do not work with anyone else on this test. Evidence of cheating will result in a zero.**

## Honor Statement

Create a `README` file that states you worked alone on this test and did not receive help from others. Type your full name in the file as your signature. **Without this statement and signature, I will not grade your submission.**

## Task

Extend (and repair) the cyclic linked list code developed on the whiteboard in class and coded here: `/home/jeckroth/csci221/class-examples/2018-spring/linkedlist`.

Define new C++ operators so that the `main.cpp` file below works, i.e., no assertions fail. Refer to [cppreference.com's operator overloading page](http://en.cppreference.com/w/cpp/language/operators). **Avoid all memory leaks.** Check with valgrind.

```
#include <iostream>
#include <cassert>
using namespace std;

#include "cycliclinkedlist.h"

typedef CyclicLinkedList CLL;

int main() {

    CLL a;
    // a.hasVal() checks that cur != NULL
    assert(!a.hasVal());

    a.add(1);
    assert(a.hasVal());
    assert(a.val() == 1);

    a.add(2);
    assert(a.hasVal());
    assert(a.val() == 2);

    a.del();
    assert(a.hasVal());
    assert(a.val() == 1);

    a.del();
    assert(!a.hasVal());

    a.add(1);
    a.add(2);

    // moves cur left
    --a;
    assert(a.hasVal());
    assert(a.val() == 1);

    // moves cur right
    ++a;
    assert(a.hasVal());
    assert(a.val() == 2);

    // same as add(3)
    a += 3;
    assert(a.hasVal());
    assert(a.val() == 3);

    CLL b;

    // same as a.hasVal()
    assert(a);
    // !a is same as !a.hasVal()
    assert(!(!a));
    assert(!b);

    b += 1;
    b += 2;
    b += 3;

    // == means same values in same order, and both cur's pointing to same starting val
    // e.g., consider these lists, where cur is indicated by *
    // x = {1, 5*, 7, 9}
    // y = {1, 5*, 7, 9}  -  these are == (and >=)
    assert(a == b);
    assert(!(a != b));

    // >= means same values in same order, but cur's may have different starting vals
    // e.g., consider these lists, where cur is indicated by *
    // x = {1, 5, 7, 9*}
    // y = {1, 5*, 7, 9}  -  these are >= (but not ==)
    assert(a >= b);

    ++b;

    assert(!(a == b));
    assert(a >= b);

    CLL c;
    assert(a != c);
    assert(!(a >= c));

    c += 4;
    assert(a != c);
    assert(!(a >= c));

    cout << "All tests passed." << endl;

    return 0;
}
```

