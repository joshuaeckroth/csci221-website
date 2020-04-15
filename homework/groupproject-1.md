---
layout: default
title: "Project Milestone 1"
due: "Fri Apr 24, 11:59pm"
categories: [assignments]
---

# Project Milestone 1

## About the Group Project

For the final few weeks of CSCI 221, we will have two group projects. I'll mostly be telling you what the projects consist of and what accomplishments are required for each milestone. In a course like CSCI 321, the members of the group will have to come up with their own project and goals.

Grading depends virtually entirely on git commits. I will look at github and see who did what for the timespan for each milestone. If you do not have commits that reflect the work you did, commits under your own name, then you will not get credit for that work. Do not let someone else commit your work on your behalf.

Join the discord group for your team - it's a channel in our regular CSCI 221 discord channel.

## Group 1: `hint`

Github repo: [https://github.com/StetsonMathCS/hint](https://github.com/StetsonMathCS/hint)

Members (random):

- Pablo
- Pham
- Kenneth
- Joey
- Stephen
- Evan
- Cole
- Cassia

### Purpose

This program, called `hint`, will help you and future students who use delenn. `hint` will be a database of hints about coding, Linux, class material, etc. For example, future students can create and read hints that help for proficiency exams. Hints will be created and searched and read from the command line on delenn (but it should work on other Linux and macOS systems also). There will be files stored on the system that hold the hint data. When a user reads a hint, it will just print to the screen. When a user creates or edits a hint, the user's editor will open (vim, nano, etc.; this is defined by the EDITOR environment variable for every user, or use nano if the variable is not defined), and the editor will open a temporary file created by the `hint` program which has a template the user fills out. When the user saves and quits the editor, the `hint` program opens the temporary file and reads the data to create the hint in the database. By "database" we mean just files in system folders (like `/var/lib/hints` or similar), not really a full database like MySQL. Use the boost.serialization library (see below) to read/write data structures like C++ map, vector, etc. to/from files instead of using a full featured database.

See below for goals for the first milestone and example usage of the `hint` program.

### Milestone 1

Milestone 1 is due Fri Apr 24, and the following eight tasks should be completed. There are eight members in the group, so each person should take one task. I'll let the group decide who takes what.

- Use [boost.serialization](https://www.boost.org/doc/libs/1_71_0/libs/serialization/doc/index.html) to create example of serializing complex stl data structures
- Define main method which handles arguments in bunch of ifs
- Define data structures (preferring stl)
- Define file locations and permissions, global and local
- Figure out how to get stack overflow data with url, demonstrate C++ url handling
- Compile test program for [xapian search](/lecture/library-xapian.html)
- Define how stats are computed and shown
- Create example of C++ program opening editor on template file


### Example usage

This example usage is a mockup, you can change the design if you have good reasons.

```
$ hint recent

$ hint search foobar

$ hint search /ls .*/

$ hint search #vector

$ hint add

$ hint rm @123

$ hint edit @123

$ hint comment @123

$ hint suggest @123 @456

$ hint tag @123 #vim

$ hint ask

$ hint answer @123

$ hint stats

$ hint help

$ hint report

$ hint random

```

## Group 2: `deadline`

Github repo: [https://github.com/StetsonMathCS/deadline](https://github.com/StetsonMathCS/deadline)

Members (random):

- Mathew
- Rachel
- Carson
- Ethan
- Joshua
- Harrison
- Moe


### Purpose

This program, called `deadline`, will help you and future students who use delenn. It will keep track of deadlines (due dates, etc.) that have been created by teachers or students. Teachers create deadlines for classes, students can only create personal deadlines that only they see. Technically, teachers will be Linux users in a group called "deadline" and with that permission will be able to create deadlines for other Linux groups. A student will be a member of a Linux group like "csci221sp2020" so that student will see any deadlines associated with that group. Deadline data will be kept in a file database (not MySQL or anything complex like that; instead, use serialization, mentioned below) that is stored in a global place on the system (like `/var/lib/deadline` or similar) and personal deadlines will be stored in the home directory of the user in a folder or file called ".deadline" (so it's hidden in most `ls` output).

Deadlines have a title, maybe a description, and a time and date. When looking at deadlines, the program will show time remaining. Once the program is functional, we can set it up so it runs whenever a user logs in so they see whatever deadlines they need to know about. The user can also run it on their own using the command `deadline`. A deadline can also be hidden if you're tired of seeing it, removed or edited if you're the owner, etc. See the example usage below.

### Milestone 1

Milestone 1 is due Fri Apr 24, and the following seven tasks should be completed. There are seven members in the group, so each person should take one task. I'll let the group decide who takes what.

- Use [boost.serialization](https://www.boost.org/doc/libs/1_71_0/libs/serialization/doc/index.html) to create example of serializing complex stl data structures
- Define main method which handles arguments in bunch of ifs
- Define data structures (preferring stl)
- Define file locations and permissions, global and local
- Demonstrate date time parsing and time delta calculations
- Define how stats are computed and shown
- Create example of C++ program opening editor on template file


### Example usage

```
$ deadline

csci221:
1. Exam 2 - April 20, 2020, 11:59pm (+6 days, 7h 25m)
2. Project Milestone 1 - April 22, 2020, 11:59pm (+8 days, 7h 25m)
3. Project Milestone 2 - April 29, 2020, 11:59pm (+15 days, 7h 25m)
4. Project Milestone 3 - May 4, 2020, 11:59pm (+20 days, 7h 25m)

personal:
5. Walk dog - April 14, 2020, 5:00pm (+24m)

$ deadline add me "Cook dinner" 6pm
Added deadline "Cook dinner" (+1h 24m)

$ deadline

csci221:
1. Exam 2 - April 20, 2020, 11:59pm (+6 days, 7h 25m)
2. Project Milestone 1 - April 22, 2020, 11:59pm (+8 days, 7h 25m)
3. Project Milestone 2 - April 29, 2020, 11:59pm (+15 days, 7h 25m)
4. Project Milestone 3 - May 4, 2020, 11:59pm (+20 days, 7h 25m)

personal:
5. Walk dog - April 14, 2020, 5:00pm (+24m)
6. Cook dinner - April 14, 2020, 6:00pm (+1h 24m)

$ deadline rm 5
Removed deadline "Walk dog" (+24m)

$ deadline

csci221:
1. Exam 2 - April 20, 2020, 11:59pm (+6 days, 7h 25m)
2. Project Milestone 1 - April 22, 2020, 11:59pm (+8 days, 7h 25m)
3. Project Milestone 2 - April 29, 2020, 11:59pm (+15 days, 7h 25m)
4. Project Milestone 3 - May 4, 2020, 11:59pm (+20 days, 7h 25m)

personal:
5. Cook dinner - April 14, 2020, 6:00pm (+1h 24m)

$ deadline hide 2
Hiding deadline "Project Milestone 1" (+8 days, 7h 22m)

$ deadline

csci221:
1. Exam 2 - April 20, 2020, 11:59pm (+6 days, 7h 25m)
2. Project Milestone 2 - April 29, 2020, 11:59pm (+15 days, 7h 25m)
3. Project Milestone 3 - May 4, 2020, 11:59pm (+20 days, 7h 25m)

personal:
4. Cook dinner - April 14, 2020, 6:00pm (+1h 24m)

$ deadline hidden

csci221:
1. Project Milestone 1 - April 22, 2020, 11:59pm (+8 days, 7h 22m) (hidden)

$ deadline unhide 1
Unhiding deadline "Project Milestone 1" (+8 days, 7h 22m)

$ deadline

csci221:
1. Exam 2 - April 20, 2020, 11:59pm (+6 days, 7h 23m)
2. Project Milestone 1 - April 22, 2020, 11:59pm (+8 days, 7h 23m)
3. Project Milestone 2 - April 29, 2020, 11:59pm (+15 days, 7h 23m)
4. Project Milestone 3 - May 4, 2020, 11:59pm (+20 days, 7h 23m)

personal:
5. Cook dinner - April 14, 2020, 6:00pm (+1h 22m)

$ deadline details 1

Exam 2 (csci221)

Deadline: April 20, 2020, 11:59pm (+6 days, 7h 23m)

Created by jeckroth on April 14, 2020, 4:37pm

Notes:

See http://csci221.artifice.cc/exam2

$ deadline edit 5

(editor like vim or nano opens, showing file contents:)
Title: Cook dinner
Deadline: April 14, 2020, 6:00pm

Notes:
Remember to add salt.

(save & quit)

$ deadline edit 1
You cannot edit "Exam 2" since you are not the owner (jeckroth is).

$ deadline calendar

$ deadline this week

$ deadline next week

$ deadline +7 days

$ deadline next

$ deadline jeckroth

$ deadline personal

$ deadline csci221

$ deadline hide all

$ deadline unhide all

$ deadline hide csci221

$ deadline hide jeckroth

$ deadline help

$ deadline version

$ deadline historic

$ deadline stats

```

