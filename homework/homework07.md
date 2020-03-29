---
layout: default
title: "HW07: Jelly Bags"
due: "Fri Apr 3, 11:59pm"
categories: [assignments]
---

# HW07: Jelly Bags

Refactor existing code to support polymorphism. Read these notes:

- [Constructors and inheritance](/lecture/constructors-and-inheritance.html)
- [Polymorphism](/lecture/polymorphism.html)

## Jelly Bags

The existing code is on delenn. Copy it to your own directory (keep the `.` at the end of the command):

```
mkdir csci221/hw07
cd csci221/hw07
git init
cp /home/jeckroth/csci221/jellybags/* .
```

This code will build & run, but the last part of the main file, which executes a function, does not correctly use polymorphism. This is because the classes are not designed in a way that uses inheritance and virtual methods.

**Your task is to update bag/set/magicbag/bean .h and .cpp files so that polymorphism works, and the main file gives the desired output.**

Here are the requirements:

- JellyBag should be the parent class. The others are child classes of JellyBag. A JellyBag just holds JellyItems in no particular order. Repeats are allowed.
- JellySet eliminates duplicate values.
- JellyMagicBag is the same as JellyBag except when iterating through values (using `next()`), the order is random.
- JellyBean can only hold zero or one JellyItems, so adding a second item removes the first.

**When you rewrite the classes, you must maximize the benefit of inheritance: do not write any extra code in the child classes that is not absolutely required. Call on your parent methods.** Note, sometimes your child class will define a method like `add()` that must call the JellyBag version of `add()`. To do so, you must write `JellyBag::add()` in the child method because if you just write `add()` then the child method will call itself infinitely.



