---
layout: default
title: Development Methodologies
---

## Waterfall vs. Agile

Now for a historical perspective. First, they say, was the Waterfall method:

![Waterfall development](/images/waterfall_development.png)

Image from: [blogs.mentor.com](http://blogs.mentor.com/robinbornoff/blog/2012/05/11/agile-software-development-practices-in-the-mechanical-analysis-division/)

There were various refinements over the years. Then, they say, the [Agile Manifesto](http://agilemanifesto.org/) was published, and everything changed (or should change), to this:

![Agile development](/images/Agile-Software-Development.png)

Agile changes the risk profile because mistakes are discovered sooner:

![Waterfall vs. Agile](/images/waterfall_versus_agile_development.png)

Image from [this presentation](http://www.slideshare.net/Managewell/agile-software-development-38182472).

Of course, in practice, agile often reduces to "less planninge" and "more work."

![Dilbert agile](/images/dilbert-agile.gif)

## User stories

![User story](/images/Sample-user-story.jpg)

Image from: [Agile Marketieng](http://www.agilemarketing.net/user-stories-agile-marketing-part-2/)

![Agile board](/images/agileboard.jpeg)

Image from: [garrensmith.com](http://www.garrensmith.com/2009/12/10/AgileBoard.html)

## Test-driven development

![Test-driven development](/images/tdd_cycle.jpg)

Image from: [this Code Project article](http://www.codeproject.com/Articles/320791/Developing-Factorial-Application-Using-Test-Driven)



## Continuous integration

![Continuous integration](/images/continuous-integration.png)

Image from: [blog.jki.net](http://blog.jki.net/news/niweek-2012-fire-and-forget-bulletproof-builds-using-continuous-integration-with-labview-video-slides-now-available/)

### Tools for continuous integration

- Hudson

## An analysis

Programmers seem, to me, to be obsessed with escaping this:

![The Trial](/images/trial_7-large-1.jpg)

Image from *The Trial* by Orson Welles

...and arriving at this:

![User stories and coffee](/images/user-stories-coffee.jpg)

Image from: [spverma.wordpress.com](http://spverma.wordpress.com/2011/02/07/292/)

Here is my analysis of the situation:

- Programs are the most complex and brittle artifacts humans have ever built.

- Hence, managers are typically far removed from the actual complexity that programmers deal with every day.

- Due to this disparity, there are no official standards of process, language choice, architecture, etc., because people who are interested in such standards are not the programmers.

- Thus, programmers are held liable for mistakes, if not legally in all cases, at least professionally or as a team.

- Finally, and therefore, programmers suffer an everpresent anxiety, and will consider any new idea that promises to eliminate it.

Programmers not only want to eliminate their anxiety. They also want to build something beautiful. Broken requirements, missed deadlines and overtime, hacks, kludges, and increasing technical debt keep us from that elusive beauty. Doing the right thing requires time.

The new ideas:

- Agile methodology: show me sooner if I've misunderstood the requirements, so I have time to change course.

- User stories: represent requirements with as little commitment as possible, so I can be sure the requirements reflect the user's actual desires, so I don't find out later that I built the wrong system, so I have time to build the right system.

- Testing, continuous integration: expose bugs sooner, so I have time to fix them.

- Test-driven development: ensure I'm covering all corner cases, so I don't find bugs later, so I have time to fix them.

You should see a pattern here. In my analysis, everything comes down to "give me time to fix mistakes," i.e., "allow me to build something that works and makes me feel good." Change "me" to "us" to make sense of how teams see the issues.

Even after software is deployed, and programmers are stuck with maintenance problems, the issue is still time: reduce the time it takes to fix a bug in maintenance mode, so I can go back to work on the more pressing projects.

## Estimation

The above analysis reduces all the problems down to time. No wonder "estimation" is famously difficult. There are no viable rules for how to estimate the time it will take for a person or team to complete a software project. This is because we can't even be sure we have an effective methodology. No methodology can foresee mistakes, which take time to correct; they only attempt to mitigate how impactful mistakes will be (do we have to start over from scratch? or just restart this iteration?).

For what it's worth, here are two rules for estimation:

> **Hofstadter's Law** "It always takes longer than you expect, even when you
> take into account Hofstadter's Law." --
> *G&ouml;del, Escher, Bach: An eternal golden braid*

Or if you prefer,

> **Murphy's law of Programming** "The sooner you start coding your program,
> the longer it is going to take." -- *The computer contradictionary*


