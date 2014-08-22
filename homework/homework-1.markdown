---
title: Homework 1
layout: default
---

Program a simple text-based version of the Numberwang game. See the
example execution below to see how it works.

Skills needed to complete this assignment:

- [Linux](/lecture/linux.html), [git](/lecture/git.html)

- [Java vs. C++](/lecture/java-vs-cpp.html),
[primitive types](/lecture/types-and-classes.html)

Name your BitBucket repository **exactly** `csci221-homework1`.

## Requirements

- Create one file, called `numberwang.cpp` or `main.cpp` or whatever.

- Compile with the command: `g++ -o numberwang numerwang.cpp` or `g++ -o numerwang main.cpp`

- Ask for two players' names. These are `string` variables. Use `cout`
  and `cin` (and `endl` for newlines). Use these players' names
  throughout the program, as shown below.

- Ask for the number of rounds. Loop for this many rounds.

- During each round, switch back-and-forth among each player to get
  their number guess. When their number is Numberwang, say so, and
  move on to the next round.

- Each round alternates the player who goes first in that round. (And
  players alternate within the round.)

- After the rounds are complete, report the players' final
  scores. Indicate which player won by stating "P1 pulls ahead
  with..." as shown below. Of course, use the actual player's name.

- Create one `main()` function, and one `numberwang(int)` function
  (which returns a `bool` type, i.e., `true` or `false`). You can
  create more functions if you feel so inspired.

Be sure to create a repository on BitBucket and add me (your
instructor) as a viewer. Tag your final submitted version with the tag
"v1.0" (without quotes). If you forget to tag a commit with "v1.0",
your work will be considered late.

## Example execution

Underlined text indicates the players providing input from the keyboard.

<pre>
Hello, and welcome to Numberwang, the maths quiz that simply everyone
is talking about!

What is player 1's name? <u>Tracy</u>

What is player 2's name? <u>Josh</u>

How many rounds? <u>2</u>

Well, if you're ready, let's play Numberwang!

Round 1, Tracy to play first.

Tracy: <u>14</u>
Josh: <u>8</u>
Tracy: <u>9</u>
Josh: <u>37</u>
Tracy: <u>99</u>

That's Numberwang!

Round 2, Josh to play first.

Josh: <u>37</u>
Tracy: <u>11.1</u>
Josh: <u>87</u>

That's Numberwang!

Final scores: Tracy pulls ahead with 32, and Josh finishes with 13.
</pre>


