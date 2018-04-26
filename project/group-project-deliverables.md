---
title: Group project deliverables
layout: default
---

# Group project deliverables

## Wed, May 2, in class

- Abdullah, Mohammed, Heyley, Kyle, Mikhail, Greg: Finish integration of all database functions into database.cpp and database.h - the web form, the rss parser, and Heyley's logic should all be functional (save and read all required data); use prepared queries to prevent sql injections
- Heyley: logic should work correctly in C++ code; it is not necessary yet that an email is actually sent
- Michael, Greg: the form and the page that loads after submission should be finalized and aesthetically pleasing; delete all other code (no "demo" or "testing" code)
- Yazeed: finish the RSS downloader; it should download the RSS file when the program is run. Research how to create a "cron" job that runs your program once per day.
- Nick, Isabel: write a function in C++ with inputs: email address, subject, body; that sends an email using sendgrid and the C++ "curl" library; create a testing program that shows that it works

To receive full credit, all work should ultimately be pushed to the "master" branch on github. You will be graded based on the master branch, not your own branch.

## Wed, April 25, in class

- Abdullah: Finalize the students table design, tell Kyle what it is; ask Heyley what “SELECT” queries she needs for the logic, and write those queries (in C++)
- Mohammed: Same as what Abdullah but with the events table
- Kyle: Implement Abdullah’s and Mohammed’s insert statements for students & events
- Heyley: Update logic to compute # of semesters left and use that value rather than year
- Michael: Create an email template; find example email templates online; notice that you cannot include external CSS in an email; create a nice-looking example email message that says “You should consider this cultural event: … (cultural event details)”
- Greg: Use Kyle’s database class to actually save student data into the database (it doesn’t have to have all the right fields yet, just needs to work)
- Isabel: Update your curl post code so that it is inside a function with arguments: email, subject, and body (all strings), and creates a post request in JSON format, just like explained here: `https://sendgrid.com/docs/API_Reference/Web_API_v3/Mail/index.html`
- Yazeed: create c++ code for the RSS downloader and show it running
- Mikhail: update your rss parser to use Kyle’s database class and actually save event data into the database
- Nick: Using this sendgrid API key, send an example email to me and yourself: (hidden) see: `https://sendgrid.com/docs/API_Reference/Web_API_v3/Mail/index.html` - it is not necessary to do this in code if you can find a easier way (for demonstration purposes)
- Jacob: Write notes about how “cron jobs” are created and used in Linux.

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

