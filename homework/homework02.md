---
layout: default
title: "HW02: Dynamic Memory"
due: "Wed Jan 29, 11:59pm"
categories: [assignments]
---

# HW02: Dynamic Memory

Fill in the code below. The code comments describe what to do.

Name your bitbucket repository exactly `csci221-hw02`. Make sure to add me ('eckroth@cse.ohio-state.edu') as a "reader" to your repository.

## Template code

```
#include <iostream>
using namespace std;

int main() {

    // create a stack variable and show its address

    // create a heap variable and show its address

    // now show the address of the stack variable that is holding the address of the heap variable

    // move the stack 32 bytes forward (i.e., lower address value), and show this final address

    // write a function (at the top of the file) that creates some stack
    // variables and shows their addresses; call this function three times;
    // notice the stack locations of the function's variables are reused for
    // each call (they are popped off the stack after each call finishes)

    // create a new heap variable that points to another new heap variable,
    // using only one stack variable (the pointer-pointer)

    // set the value of the second heap variable using the first (the pointer-pointer)
    // and then print this value
    
    // delete all three heap variables created in this program

    // write code that causes a stack overflow (you probably have to create a new function above)

    return 0;
}
```

