---
layout: default
title: Test 2
categories: [tests]
due: "Wed Apr 17, 11:59pm"
---

# Test 2

Create a bitbucket repo called `csci221-test2`. **Do not work with or talk about this test with anyone else. Evidence of cheating will result in a zero.**

## Honor Statement

Create a `README` file that states you worked alone on this test and did not receive help or advice from others. Type your full name in the file as your signature. **Without this statement and signature, I will not grade your submission.**

## Background

Update the code provided on londo: `/home/jeckroth/csci221/homework/test2`

Your program will allow users to convert units, e.g., grams to kilograms, days to seconds, miles to kilometers. Using some interesting C++ features (described in comments in the starting code), new units can be created just by creating new .cpp files that are subclasses of Mass/Time/Distance classes which themselves are subclasses of Unit. In other words, for each new unit you add, you do not need to make a .h file nor do you need to modify the main.cpp or anything else. Also, the Makefile is written in such a way that you will not need to modify it either.

The purpose of this test is to challenge you to read and sufficiently understand existing code and figure out what you need to do to create new subclasses. You also need to do some minimal string parsing like in the text adventure game assignment.

## Task

Create at least two units of each type: mass, time, and distance. The Mass class is provided; create the time and distance classes. Your new units will be subclasses of these. A basic template UnitKg class is provided. For the time/distance classes, create .h files. For your units, create only .cpp files.

You can decide which units you want to create (e.g., kilometers, yards, minutes, microseconds, whatever).

Then, write code in the main function that supports these kinds of interactions:

```
> 5 g = ? kg
0.005000 kg
> 5 kg = ? g
5000.000000 g
> quit
```

You can see an example in `maindemo` provided. It only supports kg and g. Your code should support all of your units.

Make sure you handle errors and do not crash. Instead, your program should ignore the input (after printing an error) or print an error and quit. Here are examples:

```
> 5 g = x kg
Invalid format. Type: '5.5 kg = ? g' -OR- '? kg = 5.5 g'
```

```
> 5 g = ? x
Invalid conversion or invalid units: x
> ? x = 5 g
Invalid conversion or invalid units: x
> ? kg = 5 x
Invalid conversion or invalid units: x
```


