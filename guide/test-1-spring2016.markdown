---
title: Test 1 from Spring 2016
layout: default
categories: [studyguides]
---

# Test 1 from Spring 2016

**Note, you may only refer to this site during the test. Do not look at other notes or code or Google, etc.** Total points is 100.

Create as many source files as you need, but clearly indicate which question is being answered in the various regions of code.

0\. (10pts) Write a Makefile such that certain `g++` commands are executed for a given sequence of actions (listed below). There may be more than one possible answer.

```
$ ls
a.cpp b.cpp c.cpp d.cpp x.h y.h z.h

$ make clean
rm *.o goal

$ make
g++ -c a.cpp
g++ -c b.cpp
g++ -c c.cpp
g++ -c d.cpp
g++ -o goal *.o

$ touch b.cpp
$ make
g++ -c b.cpp
g++ -o goal *.o

$ touch x.h
$ make
g++ -c a.cpp
g++ -c b.cpp
g++ -c d.cpp
g++ -o goal *.o

$ touch y.h
$ make b.o
g++ -c b.cpp

$ make
g++ -o goal *.o

$ touch z.h
$ make
g++ -c d.cpp
g++ -o goal *.o
```

1\. (5pts) Imagine you have the following code: `int *x = &(**w);` What type must `w` be?

2\. (5pts) Imagine you have the following code: `int ****x = &&w;` What type must `w` be?

3\. (10pts) Create a small scenario that results in an indirect leak. An indirect leak is one where the memory is still being pointed to, by a valid pointer, but the pointer to that pointer is lost. There may be more pointers in the chain.

4\. (10pts) Fix the memory leaks and errors in this code. You can add lines of code anywhere, but you must not remove any lines of code or comment them out. Valgrind must report no bad memory accesses (no errors) and no memory leaks.

```
int main()
{
  int ***f = new int**;
  *f = new int*;
  ***f = 37;

  int **h = new int*[3];
  f = &h;
  h[0] = new int;
  h[1] = new int;
  h[2] = new int;
  **(*f+1) = 52;

  return 0;
}
```

5\. (20pts) Define a struct inside a main() function that creates a binary tree representing the mathematical expression (in infix notation) `((1+3)*5)-(2+3)`.

6\. (20pts) Write a function that finds the product of all values in a binary tree containing float's (no "operators" like sin/cos/ln, just left-subtree, right-subtree, and a float value). Give the tree struct definition as well, unless it is the same as in question 5.

7\. (20pts) Write a function that prints all leaf nodes (nodes with no children) of a binary tree with float values. Give the tree struct definition again, if it differs from prior questions.
