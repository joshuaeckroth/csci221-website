---
title: Week 6 notes
layout: default
categories: [studyguides]
---

# Week 6 notes

## Midterm notes

```
# All of the below is really C language. C++ is when we get classes.
 - except cout/endl and "using namespace"


# Basic C++ program

#include <iostream>
using namespace std;

int main() {
    cout << "Hi" << endl;
    return 0;
}


# Types (primitive)

Integer types:
- int (32 bits)
- char (8 bits)
- bool (8 bits)
- long (64 bits) 

Floating-point types:
- float (32 bits)
- double (64 bits)


# Variables

- two kinds of memory:
  - stack (automatic)
    - any variable with a name is on the stack (e.g., int x)
    - variables get added/removed from the "top"
    - the compiler establishes the logic for creating/deleting stack variables
      - the variable is "alive" as long as it is in "scope"
      - scope is defined by { and }
  - heap (dynamic)
    - activated whenever you write "new int" or "new int[100]" or similar
    - cleared when you say "delete" or "delete[]"
    - "new" gives back a pointer to element (or first element in array)
    - "delete" requires a pointer
    - if you lose track of that pointer, you cannot delete
- struct: "structure", holds several variables
  - the size is equal to the sum of the sizes of the internal variables
  - using a struct:
    - struct foo { int a; int b; };
    - foo x;
    - x.a = 5;
    - foo* px = &x;
    - x->a = 5;
    - pointer to internal element: int *p = &x.a;
- Pointers:
  - int *px = new int;
  - int **ppx = &px;
  - int ***pppx = &ppx;
  - ***pppx = 5;
  - void* can be used for any pointer, but gotta cast before use:
    - void* p = px;
    - *((int*)p) = 5;
- Function pointers
  - whenever you make a function, you can get a pointer to it
  - void foo(int a, int b) { ... }
  - "foo" itself is a pointer to the function body
  - void (*pfoo)(int,int) = foo;
  - now use it: (*pfoo)(5, 2)


# Preprocessor

- #include "blah" (copy-replaces contents of blah right here)
- #define X 5 (define X throughout the program)


# Compiling and testing

- good g++ flags: g++ -Wall -g
- compile only (to .o "object" files): g++ -Wall -g -c file.cpp
- link .o files to output program: g++ -Wall -g -o myprogram file.o file2.o
- test for memory leaks: valgrind

# Makefiles

- word before colon: "target" to build, followed by dependencies
  - myprogram: file.o file2.o
- next line, tab-indented: commands to run to produce target
- produces a directed acyclic graph of dependencies
- "make" will only rerun those commands where target is older (modified time) than a dependency
```

