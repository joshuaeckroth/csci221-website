---
layout: default
title: Test 1 from Fall 2016
categories: [studyguides]
---

# Test 1 from Fall 2016

**Note, you may only refer to this site during the test. Do not look at other notes or code or Google, etc.** Total points is 30, each question is 10 points.

Create a bitbucket repo called `csci221-test1`. Create a directory for each problem, i.e., `prob1`, `prob2`, `prob3`. Be sure to add me as a "reader" to your repository. The test answers are due by Fri Oct 7, 11:59pm.

## Problem 1

Update the linked list code from class, on londo in `/home/jeckroth/csci221/class-examples/2016-09-21/`, so that the list can store any kind of value in any node. In other words, the list should be able to store an integer in one node, a double in the next, a tree in the third node, etc. Note, the only way to do this in C++ is to use `void*` pointers for the values so that each node points to its value rather than storing the value directly.

Write a `main.cpp` file and `main` function that tests this functionality (adding an integer, double, and tree object to the same linked list). Also retrieve the integer and double values from the list (via their pointers) and print the values (not the pointers), and retrieve the tree's pointer from the list and print its root value. Hint, you cannot store the ints or doubles directly, you can only store a pointer to them; also, you'll need a lot of type casting.

Be sure there are no memory leaks, including in your `main.cpp`.

## Problem 2

Starting with our existing tree code, on londo in `/home/jeckroth/csci221/class-examples/2016-09-30/`, write two functions:

1. Write a function that finds the max depth of the tree. The max depth is the longest number of steps from the root to a leaf. The depth of a tree with just one root node and no children is 1. Add two tests for this function in `main.cpp`. Be sure there are no memory leaks (the starting code has no leaks).

2. Write a function that counts and returns the number of nodes in the tree. Add two more tests to `main.cpp` to test this function. Be sure there are no memory leaks.

## Problem 3

Write a "Vector" class that stores `double` values in an array (do not use a linked list or anything else but an array for the underlying storage). Create these class functions, plus any others you need:

- a default constructor, `Vector()`
- a constructor that specifies the initial size of the vector, `Vector(int n)`
- a set-value function, `void set(int idx, double val)`, that sets the position `idx` in the vector to the val given; if the position is larger than the current size of the array, grow the array to accomodate
- a get-value function, `double get(int idx) const`, that returns the value at position `idx`; if the position is invalid (too large or negative), just return anything you want (the behavior is undefined)
- a function that returns the array size, `int size() const`, which may have grown since it was first constructed due to the `set` function

Create a proper `.cpp` and `.h` separation of code for the class. Use the `main.cpp` file below to test your class. You should have no memory leaks, and the main function should print correct values (it's self-explanatory). Also write a Makefile, with a `clean` target as well as the usual targets.

~~~ cpp
#include <iostream>
using namespace std;

#include "vector.h"

int main()
{
    Vector v;
    v.set(3, 10.7);
    v.set(4, 11.7);
    cout << "v.get(3) == " << v.get(3) << endl;
    cout << "v.get(4) == " << v.get(4) << endl;
    cout << "v.size() should be >= 5: " << v.size() << endl;

    Vector *pv = new Vector(20);
    pv->set(0, 88.8);
    pv->set(19, 99.9);
    cout << "pv->get(0) == " << pv->get(0) << endl;
    cout << "pv->get(19) == " << pv->get(19) << endl;
    cout << "pv->size() should be >= 20: " << pv->size() << endl;
    delete pv;

    Vector *pv2 = new Vector;
    for(int i = 0; i < 10; i++) {
        pv2->set(i, 2.2);
    }
    for(int i = 0; i < 10; i++) {
        cout << "pv2->get(" << i << ") == " << pv2->get(i) << endl;
    }
    delete pv2;
}
~~~

