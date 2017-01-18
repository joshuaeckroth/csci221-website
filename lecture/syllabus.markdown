---
title: Syllabus
layout: default
---

# Syllabus

CSCI 221 - 01, Spring 2017 --- Software Development I

MWF 1:30-2:20p Eliz Hall 205; pre-reqs: CSCI 142

This course introduces the C++ language and contemporary software development methodologies. By the end of the course, you should feel comfortable developing software with C++ inside a Linux environment while working in teams in an "agile" development style.

## About me

- Joshua Eckroth, [jeckroth@stetson.edu](mailto:jeckroth@stetson.edu), [homepage](http://www2.stetson.edu/~jeckroth/)

- Eliz Hall 214, 386-740-2519

- Office hours: Mon 2:30-4; Wed 12-1, 2:30-4

## Textbook

There is no textbook for this class.

## Grading

- Attendance on work days (Fridays, plus all class days Apr 3 - May 5): 5%
- Homeworks (6 of them): 30%
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
- answer at least 25% of the questions: 1 pt
- answer fewer than 25% of the questions: 0 pts

### Attendance

The grading rubric for attendance is as follows, out of 3 points:

- attended at least 75% of work days: 3 pts
- attended at least 50% of work days: 2 pts
- attended at least 25% of work days: 1 pt
- attended fewer than 25% of work days: 0 pts

### Group project

In the last five weeks of the course, all students will be working on a single group project. I will define the project requirements and assign each student to a subgroup with a specific set of tasks. We will collaborate as a class to decide the deliverables after I have explained the project goals.

Grades for the group project will be determined primarily on whether or not the class meets its deliverables. 20% of your group project grade will be determined by an average of your team members' and your own ratings of your performance. These ratings will be private and anonymous.

The group project grading rubric is as follows, out of 10 points:

- +2 pts: meets deliverable 1
- +2 pts: meets deliverable 2
- +2 pts: meets deliverable 3
- +2 pts: meets deliverable 4
- remaining 2 pts: average of your group member's individual private ratings of your performance

## Calendar

### Proficiency exam dates

- Proficiency exam 1: Fri Feb 24
- Proficiency exam 2: Fri Mar 31

### Test dates

Both tests are take-home. Tests will be made available at these dates, and will be due a few days later:

- Test 1: available Mon Mar 13, due Fri Mar 17 11:59pm
- Test 2: available Mon Apr 3, due Fri Apr 7 11:59pm

### Group project deliverables

Requirements for the group project will be established later. The project will have five deliverables. Each deliverable is a set of features (to be decided when the project begins), plus a presentation (~10 minutes).

- Deliverable 1: Mon Apr 10
- Deliverable 2: Mon Apr 17
- Deliverable 3: Mon Apr 24
- Deliverable 4: Mon May 1
- Deliverable 5: Fri May 5

### Topics

- Week 1: Basics of C++
- Week 2: Makefiles
- Week 3: Pointers, memory management
- Week 4: Pointers, memory management, references
- Week 5: Structs, classes, operator overloading
- Week 6: Linked lists
- Week 7: Trees
- Week 8: no class (break)
- Week 9: Polymorphism, inheritance, destructors
- Week 10: Templates, Standard Template Library
- Week 11: Qt library
- Week 12: Group project start
- Week 13: Group project deliverable (presentation)
- Week 14: Group project deliverable (presentation)
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
