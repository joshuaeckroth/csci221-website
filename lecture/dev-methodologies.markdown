---
layout: default
title: Development methodologies
---

# Development methodologies

## Waterfall vs. Agile

Now for a historical perspective. First, they say, was the Waterfall method:

![Waterfall development](/images/waterfall_development.png)

Image from: [blogs.mentor.com](http://blogs.mentor.com/robinbornoff/blog/2012/05/11/agile-software-development-practices-in-the-mechanical-analysis-division/)

There were various refinements over the years. Then, they say, the [Agile Manifesto](http://agilemanifesto.org/) was published, and everything changed (or should change), to this:

![Agile development](/images/Agile-Software-Development.png)

Agile changes the risk profile because mistakes are discovered sooner:

![Waterfall vs. Agile](/images/waterfall_versus_agile_development.png)

Image from [this presentation](http://www.slideshare.net/Managewell/agile-software-development-38182472).

Of course, in practice, agile often reduces to "less planning" and "more work."

![Dilbert agile](/images/dilbert-agile.gif)

There is a more sinister outcome besides more meetings with managers and customers. Because iterations happen more often, say every two weeks, team members may be replaced, reassigned, or eliminated more frequently. In large, waterfall projects, team members become virtually irreplaceable because completion of the project depends more critically on the people who were there at the beginning.

> "Agile development is a horrible, soul sucking, time wasting management style. It micromanages teams and treats programmers as easily replaceable cogs in a system instead of professionals and artisans." ([hurrycaine from reddit](http://www.reddit.com/r/programming/comments/2lea0u/whats_your_most_controversial_technical_opinion/clubjlf))

## User stories

Part of the agile workflow is the "user story." It is a kind of soft requirement that, presumably, can easily be stated by the customer. The programming team takes these stories, a few every two weeks or so, and writes whatever code is necessary to make sure the user can accomplish the stated task. The idea is that programmers can't possibly misunderstand such a simple and straightforward requirement, so programmers will build systems that actually meet customers' needs.

![User story](/images/Sample-user-story.jpg)

Image from: [Agile Marketing](http://www.agilemarketing.net/user-stories-agile-marketing-part-2/)

These stories are prioritized, and a few are worked on in each iteration.

![Agile board](/images/agileboard.jpeg)

Image from: [garrensmith.com](http://www.garrensmith.com/2009/12/10/AgileBoard.html)

The user story attempts to **minimize commitment** to code architecture and specific technologies. A user story is intended to be **more or less exactly what the customer wants**. However, I'm doubtful that user stories can be elicited from the customer without any priming. What if the story above was stated this way instead?

> "As a Mom, I want our family to see video of what my kids are doing."

This second version may or may not mean that the customer wants live-streaming of video. Clearly, that's a completely different product. Why did the customer say the first version (take video, share video)? Was she coached? Were her words interpreted and rewritten by the programmers? Will future user stories be free-form once the programmers have committed to certain architectures, technologies, etc.?

## Continuous integration

The main problem with the waterfall method was that the risk of failure grew as the project was in development. Risk decreases once a customer sees a demo and offers feedback. Agile tries to reduce this risk by showing demos more often (after every iteration, ideally).

Thus, it might be best to have a **continuously working system**, one that can be shown to a customer at any time because the team is always certain that it works. This can be accomplished by defining some scripted tests to ensure "workingness," and refusing to accept any code changes that break the tests. With continuous integration, as it's called, there is no risk of wasting time on big integration/bug-fixing issues just before a demo is due. The "master" branch of the project will always be in a functioning state.

![Continuous integration](/images/continuous-integration.png)

Image from: [blog.jki.net](http://blog.jki.net/news/niweek-2012-fire-and-forget-bulletproof-builds-using-continuous-integration-with-labview-video-slides-now-available/)

Continuous integration (CI) is easy to adopt. This is because decentralized version control systems (DVCS) like git are commonly used. With DVCS, developers can commit to their own isolated branch as often as they like without continuously worrying about continuous integration on the master branch.

## Test-driven development

A more extreme risk-mitigation technique is to write extensive test cases before any other code is written, then write just enough code to make all test cases pass. As a result, necessarily the code is fully tested, and these tests will serve as "regression" tests in the future. (A regression test is a test that was developed for an earlier feature, but the test is still executed to ensure the old feature still works. If the regression test fails, you have a "regression.")

![Test-driven development](/images/tdd_cycle.jpg)

Image from: [this Code Project article](http://www.codeproject.com/Articles/320791/Developing-Factorial-Application-Using-Test-Driven)

Writing all tests before any other code assumes you have a very clear idea of the requirements of the system. On a small scale, in isolated components, this approach might be useful. For example, test-driven development (TDD) might be a good idea when developing algorithms that operate on well-defined data structures. However, its usefulness is unclear to me for the more typical case of ambiguous and changing requirements. TDD limits creative exploration. And if requirements change, one might have to change a lot of test cases.

## An analysis

Here is my analysis of the situation:

- Programs are the most complex and brittle artifacts humans have ever built.

- Hence, managers are typically far removed from the actual complexity that programmers deal with every day.

- Due to this disparity, there are no official standards of process, language choice, architecture, etc., because people who are interested in such standards are not the programmers.

- Thus, programmers are held liable for mistakes, if not legally in all cases, at least professionally or as a team.

- Finally, and therefore, programmers suffer an ever-present anxiety, and will consider any new idea that promises to eliminate it.

Programmers not only want to eliminate their anxiety. They also want to build something beautiful. Broken requirements, missed deadlines and overtime, hacks, kludges, and increasing technical debt keep us from that elusive beauty. Doing the right thing requires time.

The new ideas:

- Agile methodology: show me sooner if I've misunderstood the requirements, so I have time to change course.

- User stories: represent requirements with as little commitment as possible, so I can be sure the requirements reflect the user's actual desires, so I don't find out later that I built the wrong system, so I have time to build the right system.

- Testing, continuous integration: expose bugs sooner, so I have time to fix them.

- Test-driven development: ensure I'm covering all corner cases, so I don't find bugs later, so I have time to fix them.

You should see a pattern here. In my analysis, everything comes down to "give me time to fix mistakes," i.e., "allow me to build something that works and makes me feel good." Change "me" to "us" to make sense of how teams see the issues.

Even after software is deployed, and programmers are stuck with maintenance problems, the issue is still time: reduce the time it takes to fix a bug in maintenance mode, so I can go back to work on the more pressing projects.

## Estimation

The above analysis reduces all the problems down to time. No wonder "estimation" is famously difficult. There are no viable rules for how to estimate the time it will take for a person or team to complete a software project. This is because we can't even be sure we have an effective methodology. No methodology can foresee mistakes, which take time to correct; they only attempt to mitigate how impactful mistakes will be (do we have to start over from scratch? or just restart this iteration? do we have to fix a single broken test, or integrate several independent branches of broken code?).

For what it's worth, here are two rules for estimation:

> **Hofstadter's Law** "It always takes longer than you expect, even when you
> take into account Hofstadter's Law." --
> *G&ouml;del, Escher, Bach: An eternal golden braid*

Or if you prefer,

> **Murphy's law of Programming** "The sooner you start coding your program,
> the longer it is going to take." -- *The computer contradictionary*


