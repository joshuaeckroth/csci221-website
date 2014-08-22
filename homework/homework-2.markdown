---
title: Homework 2
layout: default
---

Download existing code and create a Makefile for building the
code. Also, fix a few bugs using GDB debugging techniques.

Skills needed to complete this assignment:

- [Linux](/lecture/linux.html), [git](/lecture/git.html)

- [Java vs. C++](/lecture/java-vs-cpp.html),
  [primitive types](/lecture/types-and-classes.html)

- [GCC compiler](/lecture/gcc-compiler.html),
  [Makefiles](/lecture/makefiles.html),
  [GDB Debugger](/lecture/gdb-debugger.html)

Name your BitBucket repository **exactly** `csci221-homework2`.

## Task 1: Create a Makefile

### Requirements

- Download [homework-2-1.zip](/homework/homework-2-1.zip). It contains
  three files (from lecture): `main.cpp`, `rational.cpp`, and
  `rational.h`.

- Create a Makefile so that one could easily build a binary file out
  of these sources.

  - `main.o` depends on `main.cpp` and `rational.h`
  - `rational.o` depends on `rational.h` and `rational.cpp`
  - `ratdemo` depends on `main.o` and `rational.o`

- The Makefile must have the following "targets":

  - `all`, which depends on `ratdemo` target and otherwise does
    nothing
  - `ratdemo`, which links `main.o` and `rational.o`, creating the
    binary `ratdemo`
  - `main.o`, which compiles `main.cpp`
  - `rational.o`, which compiles `rational.cpp`
  - `clean`, which removes (`rm -f`) the generated files `main.o`,
    `rational.o`, and `ratdemo`

- Your Makefile should enable the following sequence of events. My
  typing is indicated by underlined text. Note that the `touch`
  command simply updates a file's last-modified timestamp, thus
  causing the `make` program to belief the file has changed (and so
  dependent files are out of date). Notice that, in each case, only
  necessary actions are taken to update the binary. (This makes a huge
  difference when you have thousands of files and build times that are
  measured in hours.)

<pre>
$ <u>make</u>
g++ -c main.cpp
g++ -c rational.cpp
g++ -o ratdemo main.o rational.o
$ <u>touch main.cpp</u>
$ <u>make</u>
g++ -c main.cpp
g++ -o ratdemo main.o rational.o
$ <u>touch rational.cpp</u>
$ <u>make</u>
g++ -c rational.cpp
g++ -o ratdemo main.o rational.o
$ <u>touch rational.h</u>
$ <u>make</u>
g++ -c main.cpp
g++ -c rational.cpp
g++ -o ratdemo main.o rational.o
$ <u>make clean</u>
rm -f main.o rational.o ratdemo
$ <u>make</u>
g++ -c main.cpp
g++ -c rational.cpp
g++ -o ratdemo main.o rational.o
</pre>

Be sure to create a repository on BitBucket and add me (your
instructor) as a viewer. You can use the same repository for Task 1
and Task 2. Tag your final submitted version with the tag "v1.0"
(without quotes). If you forget to tag a commit with "v1.0", your work
will be considered late.

I'll test your Makefile with exactly these commands. Include
`main.cpp`, `rational.cpp`, and `rational.h` in your repository so
that my tests work.

## Task 2: Fix a broken program

I wrote two programs. One is broken. They are intended to solve the
"Longest Collatz Sequence" problem, described at
[Project Euler, Problem 14](https://projecteuler.net/problem=14). Read
and understand the problem. One of my programs works correctly, and
gives the answer. The other does not. I compiled the working program
without debug symbols, and I am not giving you the code. So, you won't
be able to see how it works. The second, broken program was compiled
with debug symbols, so you can inspect it and fix it.

Your task is to fix the broken code, and give me the fixed source code
(via BitBucket, as usual). Of course, fix the code I wrote; don't give
me completely new code. The point of this assignment is to learn how
to use GDB for debugging.

### Requirements

- Download [homework-2-2.zip](/homework/homework-2-2.zip). It contains
  two files, `longest-collatz-sequence` and
  `longest-collatz-sequence-broken`, which are Linux
  binaries. Transfer these files to your Linux account so you can run
  them.

- Try running `longest-collatz-sequence`. You should get the correct
  answer (check that it is correct on the Project Euler website). Try
  running the second program
  `longest-collatz-sequence-broken`. Something is wrong. You need to
  produce bug-free source code.

Be sure to create a repository on BitBucket and add me (your
instructor) as a viewer. You can use the same repository for Task 1
and Task 2. Tag your final submitted version with the tag "v1.0"
(without quotes). If you forget to tag a commit with "v1.0", your work
will be considered late.

### Hints

So, you have a broken binary file. How do you fix it, and produce
working source code?

- Load the broken program into GDB and list its source code (maybe
  save this code as `lcs.cpp`).

- Run the program in GDB to possibly identify any crashes.

- If it crashes, fix the crash in the code, and recompile with
  debug-symbols: `g++ -g -o lcs lcs.cpp`

- Try running the program again in GDB. If it seems to get into an
  infinite loop, press `Ctrl-C` to stop it, and figure out where it
  stopped. Type `l` to list the code near where it stopped. Use `p`
  (print) to print current values of various variables. Does anything
  seem wonky?

- If it's useful to you, set a breakpoint on the `collatz_length`
  function or `collatz_next` function with the GDB command `b
  collatz_length` or `b collatz_next`. Or, set a breakpoint at a
  certain line number, e.g., line 15, with `b 15`. Then run the
  program again with `r`. It will stop when it reaches this
  function. You can now inspect variables, list code, etc. Type `c` to
  continue running. Type `d 1` to delete breakpoint #1.

Note: I will be curious how you use GDB to solve this problem. Please
take mental notes, or whatever, so we can talk about it in class.

However it's done, fix the code and push it up to BitBucket. Your
fixed code and my `longest-collatz-sequence` program should give the
same answers (and take about the same amount of time).
