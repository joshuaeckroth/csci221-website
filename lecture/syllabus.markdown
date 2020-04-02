---
title: Syllabus
layout: default
---

# Syllabus

CSCI 221 - 01, Spring 2020 --- Software Development I

MWF 2:30-3:30p Eliz Hall 308; pre-reqs: CSCI 142

Implementation of the Object Oriented paradigm using C++ and the Unified Modeling Language (UML). An introduction to the components of the C++ compiler, and the software development life cycle.

## About me

- Joshua Eckroth, [jeckroth@stetson.edu](mailto:jeckroth@stetson.edu), [homepage](http://www2.stetson.edu/~jeckroth/)

- Eliz Hall 214, 386-740-2519

- Office hours (online): Tu 12-2, W 10-12, Th 10-12

## Textbook

There is no textbook for this class.

## Grading

- Homeworks: 30%
- Proficiency exam: 10%
- Test 1: 20%
- Test 2: 20%
- Group project: 20%

Attendance is expected but not graded.

### Homework

Homework will be submitted via Bitbucket. Create an account on Bitbucket and, for every assignment, create a new repository and add me (username 'joshuaeckroth') as a reader. Always name the repository `csci221-HW01` (homework \# changes).

See the individual assignments for the grading rubric. Homeworks are always out of 5 points.

Late work is not accepted. The modified time on the files submitted to bitbucket will verify if homework was turned in on-time.

### Proficiency exams

You are required to learn a wide variety of techniques for Linux, git, vim, emacs, etc. I will not lecture about these techniques. See the [list of techniques](/guide/proficiency-exams.html). You cannot use notes while being examined. The tasks you will be asked to perform will differ slightly from those shown in the notes. The grading rubric is as follows, out of 3 points:

- answer at least 75% of the questions: 3 pts
- answer at least 50% of the questions: 2 pts
- answer at least 25% of the questions: 1 pt
- answer fewer than 25% of the questions: 0 pts

### Group project

In the last five weeks of the course, all students will be working on a single group project. I will define the project requirements and assign each student to a subgroup with a specific set of tasks. We will collaborate as a class to decide the deliverables after I have explained the project goals.

Grades for the group project will be determined primarily on whether or not the class meets its deliverables. 25% of your group project grade will be determined by an average of your team members' and your own ratings of your performance. These ratings will be private and anonymous.

The group project grading rubric is as follows, totalling 20 points (for 20% of final grade):

- Deliverable 1: 4 pts
- Deliverable 2: 4 pts
- Deliverable 3: 4 pts
- Deliverable 4: 4 pts
- Average peer rating: 4pts

## Calendar

### Proficiency exam dates

- Proficiency exam 1: Fri Feb 28
- Proficiency exam 2: Wed Mar 25

### Test dates

Both tests are in-class and on-paper.

- Test 1: Wed Feb 19
- Test 2: Wed Apr 15

### Group project deliverables

Requirements for the group project will be established later. The project will have five deliverables. Each deliverable is a set of features (to be decided when the project begins), plus a presentation (~10 minutes).

- Deliverable 1: Wed Apr 15
- Deliverable 2: Wed Apr 22
- Deliverable 3: Wed Apr 29
- Deliverable 4: Mon May 4, 5pm

### Topics

- Week 1: Basics of C++, Linux, git
- Week 2: Makefiles
- Week 3: Debugging
- Week 4: Pointers, memory management, references
- Week 5: Structs, classes, operator overloading
- Week 6: Linked lists
- Week 7: Trees
- Week 8: no class (break)
- Week 9: Polymorphism, inheritance, destructors
- Week 10: Templates, Standard Template Library
- Week 11: Boost library
- Week 12: Group project start
- Week 13: Group project deliverable (presentation)
- Week 14: Group project deliverable (presentation)
- Week 15: Group project deliverable (presentation)
- Week 16: Group project deliverable (presentation)
- Final exam time (May 4, 5-7pm): Group project deliverable and retrospective


{% comment %}
Homework due dates:

<ul>
{% for p in site.pages sort_by:title order:ascending %}
{% if p.categories contains 'assignments' %}
<li>
<a href="{{ p.url }}">{{ p.title }}</a>, due {{ p.due }}
</li>
{% endif %}
{% endfor %}
</ul>
{% endcomment %}


## Honor code

I am strongly in agreement with the
[Stetson University Honor Code](http://www.stetson.edu/other/honor-system/). Any
form of cheating is not acceptable, will not be tolerated, and could
lead to dismissal from the University. In this class, cheating is defined as copying code from the internet (except this website), copying code from other students, or working together on assignments or tests. Only in the context of the group project may students work together; even then, code cannot be copied from the internet. Please consult with me if you find a solution to a problem on the internet and wish to make use of it; we can arrange an appropriate solution.

## Academic success center

If a student anticipates barriers related to the format or
requirements of a course, she or he should meet with the course
instructor to discuss ways to ensure full participation. If
disability-related accommodations are necessary, please register with
the Academic Success Center (822-7127;
[www.stetson.edu/asc](http://www.stetson.edu/asc)) and notify the
course instructor of your eligibility for reasonable
accommodations. The student, course instructor, and the Academic
Success Center will plan how best to coordinate accommodations. The
Academic Success Center is located at 209 E Bert Fish Drive, and can
be contacted using the email address
[asc@stetson.edu](mailto:asc@stetson.edu).
