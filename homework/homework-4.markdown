---
title: Homework 4
layout: default
---

Eliminate all memory leaks from a linked list library. Also write test
cases for every linked list function.

Skills needed to complete this assignment:

- [Memory management](/lecture/memory-management.html)

- [Linked lists](/lecture/linked-lists.html); note, the code you will
  work on is not the same code from the notes; you will work on more
  complete, more complex code.

Name your BitBucket repository **exactly** `csci221-homework4`.

## Requirements

- Download the [hw4-ll.zip](/homework/hw4-ll.zip) code. Or, copy
  it from `londo` directory
  `/home/jeckroth/csci221-public/homework-4`.

- Add code to the `testll.cpp` file so that every function in the
  linked list class is tested. Use `assert` when possible, as shown in
  the example in the file. Make sure every function gets used
  once. For functions that return a value, test that the value is as
  expected, using `assert`. For functions that just print to the
  screen, simply execute the function. Be sure to handle edge cases
  (e.g., removing from an empty list, etc.). You don't need to test
  with invalid parameters that will crash the program (e.g.,
  retrieving a value at an invalid index). The crashes are due to the
  use of `assert`.

- Eliminate all memory leaks, according to Valgrind. As part of this
  process, create a destructor function (refer to the bottom of
  [memory management](/lecture/memory-management.html) notes) for the
  `LinkedList` class.

Be sure to create a repository on BitBucket and add me (your
instructor) as a viewer. Tag your final submitted version with the tag
"v1.0" (without quotes). If you forget to tag a commit with "v1.0",
your work will be considered late.


