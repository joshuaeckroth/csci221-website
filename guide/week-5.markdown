---
title: Week 5 notes
layout: default
categories: [studyguides]
---

# Week 5 notes

## Pass-by-value vs. pass-by-reference

Function calling value semantics

1. Pass-by-value:
   - argument value is copied to function, function receives own copy (on stack)
   - C++: always (unless pass-by-reference)
   - Java: only primitives (double, int, boolean)

2. Pass-by-reference:
   - argument is assigned same memory location for both original value and function's value
   - C++: requires & in arguments
   - Java: all objects

Pass-by-value:

```
// value of x is copied to function
int addOne(int x) {
    x++;
    return x;
}

void main() {
    int y = 0;
    addOne(y); // y does not change
    z = addOne(y); // z == 1
}
```

Pass-by-reference:

```
// variable x is connected (same memory location) with variable from main()
int addOne(int &x) {
    x++;
    return x;
}

void main() {
    int y = 0;
    addOne(y); // y changes, so now y == 1
    z = addOne(y); // z == 2, and now y == 2
}
```

Another approach, pass-by-pointer (which is actually pass-by-value):

```
// value of pointer px is copied to function
int addOne(int *px) {
    (*x)++;
    return *x;
}

void main() {
    int y = 0;
    addOne(&y); // y changes, so now y == 1
    z = addOne(&y); // z == 2, and now y == 2
}
```

Less common case, use pointers and pass-by-reference:

```
// variable px is shared with pointer variable from main()
void messWithPointer(int *&px) {
    px = new int; // change pointer to another location
    *px = 55;
}

int main() {
    int *y = new int;
    *y = 0;
    addOne(y); // after function, y points to a different int! and now *y == 55
}
```

Another variation, double-pointer (pass-by-value):

```
void messWithPointer(int **px) {
    *px = new int; // change original pointer to point to something else
    **px = 55;
}

int main() {
    int *y = new int;
    *y = 0;
    addOne(&y); // after function, y points to a different int! and now *y == 55
}
```

