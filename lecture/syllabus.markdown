---
title: Syllabus
layout: default
---

# Syllabus

CSCI 221 - 01, Fall 2016 --- Software Development I

MWF 11-11:50a Eliz Hall 205; pre-reqs: CSCI 142

This course introduces the C++ language and contemporary software development methodologies. By the end of the course, you should feel comfortable developing modern software in C++ and using various common C++ libraries, as well as working in teams in an "agile" development style.

## About me

- Joshua Eckroth, [jeckroth@stetson.edu](mailto:jeckroth@stetson.edu), [homepage](http://www2.stetson.edu/~jeckroth/)

- Eliz Hall 214, 386-740-2519

- Office hours: Mon/Wed 12-2:30

## Text book

There is no textbook for this class.

## Grading

- Attendance on work days (Fridays, plus all class days Nov 7 - Dec 14): 5%
- Homeworks (7 of them): 30%
- Proficiency exam 1: 2.5%
- Proficiency exam 2: 2.5%
- Test 1: 20%
- Test 2: 20%
- Group project: 20%

Late work is penalized 20% for each day that it is late. Submissions
more than 3 days late receive no credit. Tests cannot be made up
unless a doctor's note is provided.

### Homework

Homework will be submitted via Bitbucket. Create an account on Bitbucket and, for every assignment, create a new repository and add me (username 'joshuaeckroth') as a reader. Always name the repository `csci221-HW01` or similar.

See the individual assignments for the grading rubric. Homeworks are always out of 5 points.

### Proficiency exams

You are required to learn a wide variety of techniques for Linux, git, vim, emacs, etc. I will not lecture about these techniques. See the [list of techniques](/guide/proficiency-exams.html). You cannot use notes while being examined. The grading rubric is as follows, out of 3 points:

- answer at least 75% of the questions: 3 pts
- answer at least 50% of the questions: 2 pts
- ansewr at least 25% of the questions: 1 pt
- answer fewer than 25% of the questions: 0 pts

### Attendance

The grading rubric for attendance is as follows, out of 3 points:

- attended at least 75% of work days: 3 pts
- attended at least 50% of work days: 2 pts
- attended at least 25% of work days: 1 pt
- attended fewer than 25% of work days: 0 pts

### Group project

In the last five weeks of the course, every student will be working on a group project. Groups will have 3-6 people, mostly grouped by interests and technology stack (e.g., Windows vs. Linux).

Grades for the group project will be determined primarily on whether or not your group meets its deliverables. 20% of your group project grade will be determined by an average of your team members' and your own ratings of your performance. These ratings will be private and anonymous.

The group project grading rubric is as follows, out of 10 points:

- +2 pts: meets deliverable 1
- +2 pts: meets deliverable 2
- +2 pts: meets deliverable 3
- +2 pts: meets deliverable 4
- remaining 2 pts: average of your group member's individual private ratings of your performance

## Calendar

### Proficiency exam dates

- Proficiency exam 1: Wed Nov 2
- Proficiency exam 2: Wed Nov 30

### Test dates

Both tests are take-home.

- Test 1: Wed Oct 5
- Test 2: Fri Oct 28

### Group project deliverables

Requirements for the group projects will depend on the projects in question. All projects will have four deliverables. Each deliverable is a set of features (to be decided when the project begins), plus a presentation (~10 minutes).

- Deliverable 1: Mon Nov 14
- Deliverable 2: Mon Nov 28
- Deliverable 3: Mon Dec 5
- Deliverable 4: Mon Dec 14

### Topics

- Week 1: Basics of C++
- Week 2: Makefiles
- Week 3: Pointers, memory management
- Week 4: Structs, classes, linked lists, trees
- Week 5: Test 1 (take-home); arrays
- Week 6: Polymorphism, inheritance, destructors
- Week 7: Templates, Standard Template Library
- Week 8: UML, code documentation, SQLite library
- Week 9: Test 2 (take-home)
- Week 10: Qt library; proficiency exams
- Week 11: Plan group projects
- Week 12: Group project deliverable (presentation)
- Week 13: Work day (only one day of class due to holiday)
- Week 14: Group project deliverable (presentation); proficiency exams
- Week 15: Group project deliverable (presentation)
- Week 16: Group project deliverable (presentation)

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

## Honor code

I am strongly in agreement with the
[Stetson University Honor Code](http://www.stetson.edu/other/honor-system/). Any
form of cheating is not acceptable, will not be tolerated, and could
lead to dismissal from the University.

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
