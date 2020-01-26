---
title: Week 2 notes
layout: default
categories: [studyguides]
---

# Week 2 notes

## Dynamic memory

```
#include <iostream>
using namespace std;

void func1() {
    // y is managed automatically: created & deleted without my control
    int y = 8;
    cout << "&y = " << &y << endl;
}

int main() {
    // Automatic memory management
    int x = 5;
    cout << "&x = " << &x << endl;
    int x2 = 6;
    cout << "&x2 = " << &x2 << endl;
    int x3 = 7;
    cout << "&x3 = " << &x3 << endl;

    // So, these variables are growing "up" (larger addresses)


    // Dynamic memory: we control it

    // let's make an integer that won't disappear    
    // (we can only get a pointer to the space)
    int *myloc = new int;
    cout << "myloc = " << myloc << endl;
    int *myloc2 = new int;
    cout << "myloc2 = " << myloc2 << endl;

    *myloc = 5;
    cout << "*myloc = " << *myloc << endl;

    // Free up memory
    delete myloc;
    delete myloc2;

    cout << "*myloc = " << *myloc << endl;

    func1();
    func1();
    func1();

    // Let's run out of memory
    //while(1) {
    //    new int;
    //}


    return 0;
}
```

## Vim

![Vim notes](/images/vim-notes.png)

