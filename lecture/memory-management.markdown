---
layout: default
title: Memory management
---

# Memory management

## Data section vs. dynamic memory

### Data section

Values that appear in code, such as `x = 5;`, have the value 5 stored
in the program binary. There is a special "section" of the binary
where all such values are kept, which is called the "data section."

Consider this example program:

{% highlight cpp %}
int x = 37;
float y = 3.14;
char c = 'q';

int main()
{

    return 0;
}
{% endhighlight %}

We can look at the data section for this program with the Linux
command `objdump -s [file]`:

```
...
Contents of section .data:
 600938 00000000 25000000 c3f54840 71000000  ....%.....H@q...
...
```

In order to interpret this data section, we'll want to know the
locations of the variables, by using the `objdump --syms [file] |
sort` command:

```
0000000000600938  w      .data	0000000000000000              data_start
000000000060093c g     O .data	0000000000000004              x
0000000000600940 g     O .data	0000000000000004              y
0000000000600944 g     O .data	0000000000000001              c
```

Ok, so `60093c` is the start of the `x` value. Back to the data
section, we see it starts at `600938`, so we need to look forward four
bytes to get to `60093c` (one chunk of hex values; each two hex
numbers is a byte). That gives us: `25`, which is hexadecimal for 37
(16*2+5). (Note: the value 37 is stored as `25000000`, i.e., byte
values `37,0,0,0` in decimal, because Intel architectures are "little
endian," meaning the most least significant bits are on the left at
the smaller/earlier addresses.)

The next four bytes are `c3f54840`. This is a bunch of nonsense
representing the `float` value 3.14 in IEEE-754 format.

The next four bytes are `71000000`, which in decimal is 113 (16*7+1),
which is ASCII for `q`. That's the value of the variable `c`. Woot!

### Dynamic memory

Apart from global variables found in the data section, we have local
variables and explicit memory allocation. Local variables look like
this:

{% highlight cpp %}
int main()
{
  int x; // local variable

  // ...
}
{% endhighlight %}

Local variables are stored on "the stack," just like function
calls. Local variables are often kept with the information about the
function call. These variables are automatically forgotten when the
function completes.

Explicit memory allocation looks like this (see the next sections
also):

{% highlight cpp %}
int main()
{
  int *x = new int;

  // ...
}
{% endhighlight %}

The `new` operator uses the "heap" (main memory) for memory
allocation. The allocated memory is not automatically freed. One must
use the `delete` operator to free up heap memory.

## new and delete and delete[]

The `new` operator reserves memory for one value of a certain
type. Example: `new int`. The return value is a pointer (memory
address) to the reserved memory. One can also reserve space for an
array of values: `new int[10]`. This creates space for 10
integers. The reserved space is consecutive, so one can use pointer
arithmetic to get to all the values:

{% highlight cpp %}
// reserve space for 4 integer values and set each value
int *p = new int[4];
*p = 10;
*(p+1) = 11;
*(p+2) = 12;
*(p+3) = 13;
{% endhighlight %}

Any memory reserved with `new` should eventually be deleted:

{% highlight cpp %}
// reserve memory
int *p = new int;
// delete (free) memory
delete p;

// similar with arrays
int *p = new int[4];
delete[] p;
{% endhighlight %}

## Segementation faults

A segmentation fault occurs when an invalid pointer is followed
(attempts to read or write data from the invalid memory address).

Simple example:

{% highlight cpp %}
int *x = (int*)37; // bogus pointer
cout << *x << endl; // segfault
*x = 19; // segfault
{% endhighlight %}

Here is another example.

{% highlight cpp %}
int *arr = new int[3];
cout << arr[5] << endl; // segfault, arr[5] is bogus
arr[5] = 19; // segfault, arr[5] is bogus
{% endhighlight %}

The meaning of the word "segmentation" in this context is described by
Wikipedia:

> The term "segmentation" has various uses in computing; in the
> context of "segmentation fault", a term used since the 1950s, it
> refers to the address space of a program. With memory protection,
> only the program's address space is readable, and of this, only the
> stack and the read-write portion of the data segment of a program
> are writable, while read-only data and the code segment are not
> writable. Thus attempting to read outside of the program's address
> space, or writing to a read-only segment of the address space,
> results in a segmentation fault, hence the name.

## Memory leaks

We can use the `valgrind` tool to detect memory leaks:

```
valgrind --leak-check=full --show-reachable=yes ./myprogram
```

### Types of leaks

- **definitely lost** -- reserved memory for which no pointer exists.

- **indirectly lost** -- reserved memory that has one or more pointers
    to it (also created with `new`), but pointers to those pointers
    are lost.

- **possibly lost** -- an array is reserved but the only remaining
    pointer is pointing to the middle of it, not the start; note that
    you only use `delete[]` with a pointer that points to the start of
    the array.

- **still reachable** -- memory that is never freed but for which
    there is still a pointer to it when the program exists; one simple
    way to achieve this is to keep the pointer as a global variable,
    but never free the memory.

### Examples of leaks

Run this program with `valgrind`. See the output below.

{% highlight cpp %}
#include <iostream>
using namespace std;

int *x;
int *y;

int main()
{
    // 1. memory that is not leaked
    int *a = new int;
    *a = 37;
    delete a;

    // 2. array of memory that is not leaked
    int *b = new int[4];
    *b = 37;
    *(b+1) = 38;
    *(b+2) = 39;
    *(b+3) = 40;
    delete[] b;

    // 3. memory that is accessible indirectly
    int **c = new int*;
    int *d = new int;
    *c = d;
    **c = 37;
    delete d; // order can be flipped
    delete c;

    // 4. memory that is directly lost
    int *e = new int;
    *e = 37;
    // memory pointed to by e is never deleted
    
    // 5. memory that is (still) directly lost
    // (lose address of second 'new' reserved memory)
    int **f = new int*;
    *f = new int; // this memory is directly lost
    **f = 37;
    delete f; // lost here

    // 6. memory that is indirectly lost (we have a chain of three
    // pointers; first pointer, g, points to a 2-chain; the end of the
    // chain, with value 37, is still pointed to when we delete g; but
    // the start of the 3-chain is lost (by deleting g), so the inner
    // value of 37 is indirectly lost); "indirectly lost" is a term
    // defined by the valgrind program
    int ***g = new int**;
    *g = new int*;
    **g = new int;
    ***g = 37;
    delete g; // pointer to value of 37 is indirectly lost (still
              // pointed to by something else, but the pointer to that
              // pointer is lost)

    // 7. more memory that is indirectly lost; we have an array still
    // in memory that has pointers to other values, but the start
    // location of that array is lost; the three integers (not the
    // three pointers) are the indirectly lost memory
    int **h = new int*[3];
    h[0] = new int;
    h[1] = new int;
    h[2] = new int;

    // 8. possibly lost; we still have a pointer to the middle of an
    // array, but lose the start pointer
    int *i = new int[3];
    i[0] = 37;
    i[1] = 38;
    i[2] = 39;
    x = (i+2);
    // we lose i, but still have x (since it's global)

    // 9. a still-reachable pointer, since y is global, but we never
    // delete, so it's still a leak
    y = new int;

    return 0;
}
{% endhighlight %}

Output from `valgrind --leak-check=full --show-reachable=yes ./leaks`

```
==15267== Memcheck, a memory error detector
==15267== Copyright (C) 2002-2012, and GNU GPL'd, by Julian Seward et al.
==15267== Using Valgrind-3.8.1 and LibVEX; rerun with -h for copyright info
==15267== Command: ./leaks
==15267==
==15267==
==15267== HEAP SUMMARY:
==15267==     in use at exit: 72 bytes in 10 blocks
==15267==   total heap usage: 16 allocs, 6 frees, 120 bytes allocated
==15267==
==15267== 4 bytes in 1 blocks are still reachable in loss record 1 of 10
==15267==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==15267==    by 0x40099F: main (leaks.cpp:76)
==15267==
==15267== 4 bytes in 1 blocks are indirectly lost in loss record 2 of 10
==15267==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==15267==    by 0x4008E7: main (leaks.cpp:50)
==15267==
==15267== 4 bytes in 1 blocks are indirectly lost in loss record 3 of 10
==15267==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==15267==    by 0x40091E: main (leaks.cpp:61)
==15267==
==15267== 4 bytes in 1 blocks are indirectly lost in loss record 4 of 10
==15267==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==15267==    by 0x40093A: main (leaks.cpp:62)
==15267==
==15267== 4 bytes in 1 blocks are indirectly lost in loss record 5 of 10
==15267==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==15267==    by 0x40094F: main (leaks.cpp:63)
==15267==
==15267== 4 bytes in 1 blocks are definitely lost in loss record 6 of 10
==15267==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==15267==    by 0x40086B: main (leaks.cpp:31)
==15267==
==15267== 4 bytes in 1 blocks are definitely lost in loss record 7 of 10
==15267==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==15267==    by 0x400891: main (leaks.cpp:38)
==15267==
==15267== 12 bytes in 1 blocks are possibly lost in loss record 8 of 10
==15267==    at 0x4A07152: operator new[](unsigned long) (vg_replace_malloc.c:363)
==15267==    by 0x40095C: main (leaks.cpp:67)
==15267==
==15267== 12 (8 direct, 4 indirect) bytes in 1 blocks are definitely lost in loss record 9 of 10
==15267==    at 0x4A075BC: operator new(unsigned long) (vg_replace_malloc.c:298)
==15267==    by 0x4008CC: main (leaks.cpp:49)
==15267==
==15267== 36 (24 direct, 12 indirect) bytes in 1 blocks are definitely lost in loss record 10 of 10
==15267==    at 0x4A07152: operator new[](unsigned long) (vg_replace_malloc.c:363)
==15267==    by 0x400910: main (leaks.cpp:60)
==15267==
==15267== LEAK SUMMARY:
==15267==    definitely lost: 40 bytes in 4 blocks
==15267==    indirectly lost: 16 bytes in 4 blocks
==15267==      possibly lost: 12 bytes in 1 blocks
==15267==    still reachable: 4 bytes in 1 blocks
==15267==         suppressed: 0 bytes in 0 blocks
==15267==
==15267== For counts of detected and suppressed errors, rerun with: -v
==15267== ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 6 from 6)
```

## Destructors

Sometimes, class functions will reserve memory with the `new` operator
and save pointers to this memory in private class variables. When an
object of the class is deleted, we want the class to take care of
deleting the memory it reserved. We can't do it anyway, since the
pointers are private class variables.

To deal with this, we can create class "destructors." These are the
opposite of class constructors: the destructor is executed when a
class object is being deleted. Here is what it looks like:

{% highlight cpp %}
class MyClass
{
public:
    MyClass(); // constructor
    void food(); // some function
    ~MyClass(); // destructor
private:
    int *my_pointer;
};

MyClass::MyClass()
{
    my_pointer = new int;
}

MyClass::~MyClass()
{
    delete my_pointer;
}
{% endhighlight %}

Here is how you might use this class:

{% highlight cpp %}
int main()
{
    MyClass *obj = new MyClass;
    obj->foo(); // whatever
    delete obj; // now the destructor is executed
}
{% endhighlight %}

<div style="text-align: center">
<iframe width="420" height="315" src="//www.youtube.com/embed/cUaaSR4AbZs?rel=0" frameborder="0" allowfullscreen></iframe>
</div>
