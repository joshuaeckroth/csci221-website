---
title: Group project notes
layout: default
---

# Group project notes

Get Cultured! @ [http://mycultural.events](http://mycultural.events/)

Git repo: [https://github.com/StetsonMathCS/MyCultural.Events](https://github.com/StetsonMathCS/MyCultural.Events)

## Grading

- from now to end, I will take attendance (10% of overall grade)
- each person will have a specific task
  - so each person is responsible and graded on something
- 3 pts per deliverable (=15 pts), plus 5 pts group evals, adds up to 20pts (20% of overall grade)


## Service description

- frontend:
  - website, probably single page, with a form:
    - first name
    - email
    - expected graduation (semester, year)
    - \# of cultural events needed now
    - preference for events (keywords)
  - shows page, responds to form
  - saves form input into sqlite database
  
- backend cultural events crawler:
  - finds cultural events notices, saves in db
  
- backend periodic emailer:
  - reads db for events and people who need events
  - generates periodic emails and sends them


## Groups & tasks

- frontend:
  - HTML/CSS & C++ code to generate it (like with Cgicc library)
  - save into sqlite database (insert)
  - Mikhail, Nick, Mohammed, Greg
  - Michael, Greg: Cgicc
  - http://54.173.103.237/completedemo.cgi
- backend cultural events crawler:
  - RSS crawler
  - consider https://pugixml.org
  - saves to database (insert)
  - Mikhail, Mohammed, Michael, Heyley
  - Mikhail: RSS library
  - https://github.com/zeux/pugixml/tree/master/docs/samples
- backend periodic mailer:
  - checks database for anyone who needs an email
  - logic for choosing who needs an email:
    - Heyley
  - sends an email
    - sendgrid, HTTP requests
    - consider http://www.curlpp.org/
  - Yazeed, Isabel, Mikhail

## Server access

We'll run everything on http://54.173.103.237/ (aka, http://mycultural.events/)

You will each have a user account, same as your londo username. You can write code on that server. All required C++ libraries are already installed, and example working code and Makefiles may be found in the directory `/home/ubuntu/examples`. A Cgicc example is running here: [http://mycultural.events/completedemo.cgi](http://mycultural.events/completedemo.cgi). Note that Cgicc programs should be named "foobar.cgi" rather than just "foobar".


