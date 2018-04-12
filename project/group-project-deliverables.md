---
title: Group project deliverables
layout: default
---

# Group project deliverables

## Wed, April 18, in class

- Abdullah: Create the students table with C++/SQLite code. Insert example data with C++ code. Select example data as well.
- Mohammed: Same as above (Abdullah's task) but with the events table.
- Kyle: Define a C++ class for the database, in which the constructor sets up the SQLite database, and various methods insert/select data. Guess what methods will be needed. Leave the methods mostly blank, as Abdullah and Mohammed will eventually provide that code.
- Heyley: Write your logic in C++ code, making assumptions about which database class methods exist (e.g., `getStudentCulturalEventCount(int studentid)`).
- Michael: Write your HTML code into Greg's Cgicc demo. Replace Greg's HTML form with your own. Make sure the program still submits the form data.
- Greg: Write code that checks the form submission data: a name should be just letters, no punctuation; graduation date should be proper year and semester; needed cultural events should be a number, etc; this is needed because a user can trick their browser to send anything they wish, not just what's written in the HTML dropdowns. Also check that the data is short, e.g., a name should be no more than 30 characters.
- Isabel: Write C++ code with the curlpp library that makes a POST request to the form on our website: `http://mycultural.events/completedemo.cgi`
- Yazeed: Write C++ code that downloads the RSS file from the web: `https://www.stetson.edu/programs/calendar/rss/cultural-credits.rss`
- Mikhail: Retrieve all relevant event information from the RSS file.
- Nick: Write notes about how to send an email to a particular person with the SendGrid API.
- Jacob: Write notes about how "cron jobs" are created and used in Linux.

## Wed, April 11, in class

Be prepared to present for 3-4min each about your progress. Some people will have the same task but should come up with different results.

- Abdullah: Write notes about what a "table" for students will contain
- Greg: Adapt the working Cgicc code to contain something like the form we will ultimately want on the website
- Heyley: Write notes about the logic that will determine if a student should be emailed about a new event that is posted
- Isabel: Research curlpp and write notes about GET vs. POST HTTP requests
- Jacob: Research curlpp and write notes about GET vs. POST HTTP requests
- Kyle: Write notes about the methods that will necessary to save/retrieve data in the database
- Michael: Look at Twitter bootstrap and create an example page that has our website form
- Mikhail: Download the culture credit RSS file and get some data from the file with pugixml
- Mohammed: Write notes about what a "table" for events will contain
- Nick: Adapt the working Cgicc code to contain something like the form we will ultimately want on the website
- Yazeed: Research curlpp and write notes about GET vs. POST HTTP requests 

