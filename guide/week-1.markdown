---
title: Week 1 notes
layout: default
categories: [studyguides]
---

# Week 1 notes

```
#include <iostream>
using namespace std;

int main() {

        int x = 5; // 4 bytes (32 bits)
        cout << "x = " << x << endl;
        x = 7;
        cout << "size of x: " << sizeof(x) << endl;

        cout << "size of bool: " << sizeof(bool) << endl;


        cout << "address of x: " << &x << endl;

        int y = 10;
        cout << "address of y: " << &y << endl;


        // pointer type
        // need to say what kind of variable you are storing the address for
        int* px = &x;
        // "int*" means "address of an int variable"
        cout << "value of px: " << px << endl;


        bool c = 1;
        bool* pc = &c;
        cout << "value of pc: " << pc << endl;


        // want to use px to change the value of x
        *px = 12;
        // *px means "dereference px" (i.e., go to where it is pointing)
        cout << "value of px: " << px << endl;
        cout << "x = " << x << endl;


        // make a pointer to px
        // call this new variable "ppx" (pointer to pointer to x)
        int ** ppx = &px;
        cout << "value of ppx: " << ppx << endl;


        // change x's value using only ppx
        **ppx = 31;
        cout << "x = " << x << endl;



        struct student {
                int age;
                int year;
                float gpa;
                bool active;
        };

        struct student frank;
        frank.age = 18;
        frank.year = 1;
        frank.gpa = 2.56;
        frank.active = 1;

        cout << "size of struct student: " << sizeof(struct student) << endl;

        cout << "address of frank: " << &frank << endl;
        cout << "address of frank.age: " << &frank.age << endl;
        cout << "address of frank year: " << &frank.year << endl;

        struct student * pfrank = &frank;

        pfrank->age = 19;
        cout << "Frank's age: " << pfrank->age << endl;


        return 0;
}
```

