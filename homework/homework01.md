---
layout: default
title: "HW01: Automatic Memory"
due: "Fri Jan 24, 11:59pm"
categories: [assignments]
---

# HW01: Automatic Memory

Fill in the code below. The code comments describe what to do.

Name your bitbucket repository exactly `csci221-hw01`. Make sure to add me ('joshuaeckroth') as a "reader" to your repository.

## Template code

```
#include <iostream>
using namespace std;

int main() {

    // show the actual size (in bytes) for every primitive type
    // refer to http://csci221.artifice.cc/lecture/java-vs-cpp.html "Primitive data types" section


    // create a structure that is 32 bytes large; there are multiple ways to do this;
    // verify the size by printing its size


    // create a structure representing a single day's weather:
    // include year, month, day, high temp, low temp, avg temp;
    // then set these values for a single day (make up the data)


    // create a variable (call it x) of any primitive type, and print its memory address


    // create a pointer to the variable created in the prior step (called x);
    // print this pointer's value and print its address (notice these are different ideas!)


    // create a pointer to the pointer created in the last step;
    // print this pointer's value and print its address


    // change the value of the original variable (called x) using the pointer

    
    // keep this line here so we can see x's new value
    cout << "x value now: " << x << endl;


    // change the value of the original variable (called x) using the pointer-to-the-pointer


    // keep this line here so we can see x's new value
    cout << "x value now: " << x << endl;


    // create a pointer to the weather data you defined for the single day's temperatures


    // print the weather pointer's value

    
    // set the single day's high temperature to 89.5 degrees using the pointer


    // write a line of code that will crash your program with an invalid memory access
    // also known as a segmentation fault


    return 0;
}
```

