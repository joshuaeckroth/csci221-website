---
layout: default
title: Randomness
---

## Tests for non-randomness

http://csrc.nist.gov/groups/ST/toolkit/rng/stats_tests.html

http://www.phy.duke.edu/~rgb/General/dieharder.php

http://www.fourmilab.ch/rpkp/experiments/statistics.html

http://www.fourmilab.ch/rpkp/experiments/analysis/chiCalc.html

http://www.fourmilab.ch/random/


dieharder returns "p-values".  To understand what a p-value is and how
to use it, it is essential to understand the null hypothesis, H0.

The null hypothesis for random number generator testing is "This
generator is a perfect random number generator, and for any choice of
seed produces a infinitely long, unique sequence of numbers that have
all the expected statistical proper‐ ties of random numbers, to all
orders".  Note well that we know that this hypothesis is technically
false for all software generators as they are periodic and do not have
the correct entropy content for this statement to ever be true.
However, many hardware generators fail a priori as well, as they
contain subtle bias or correlations due to the deterministic physics
that underlies them.  Nature is often unpredictable but it is rarely
random and the two words don't (quite) mean the same thing!

The null hypothesis can be practically true, however.  Both software
and hardware generators can be "random" enough that their sequences
cannot be distinguished from random ones, at least not easily or with
the available tools (including dieharder!) Hence the null hypothesis
is a practical, not a theoretically pure, statement.

To test H0 , one uses the rng in question to generate a sequence of
presumably random numbers.  Using these numbers one can generate any
one of a wide range of test statistics -- empirically computed numbers
that are considered random samples that may or may not be covariant
subject to H0, depending on whether overlapping sequences of random
numbers are used to generate successive samples while generating the
statistic(s), drawn from a known distribution.  From a knowledge of
the target distribution of the statistic(s) and the associated
cumulative distribution function (CDF) and the empirical value of the
randomly generated statistic(s), one can read off the probability of
obtaining the empirical result if the sequence was truly random, that
is, if the null hypothesis is true and the generator in question is a
"good" random number genera‐ tor!  This probability is the "p-value"
for the particular test run.

For example, to test a coin (or a sequence of bits) we might simply
count the number of heads and tails in a very long string of flips.
If we assume that the coin is a "perfect coin", we expect the number
of heads and tails to be binomially distributed and can easily compute
the probability of getting any particular number of heads and tails.
If we compare our recorded number of heads and tails from the test
series to this distribution and find that the probability of getting
the count we obtained is very low with, say, way more heads than tails
we'd suspect the coin wasn't a perfect coin.  dieharder applies this
very test (made mathematically precise) and many others that operate
on this same principle to the string of random bits produced by the
rng being tested to provide a picture of how "random" the rng is.

Note that the usual dogma is that if the p-value is low -- typically
less than 0.05 -- one "rejects" the null hypothesis.  In a word, it is
improbable that one would get the result obtained if the generator is
a good one.  If it is any other value, one does not "accept" the
generator as good, one "fails to reject" the generator as bad for this
particular test.  A "good random number generator" is hence one that
we haven't been able to make fail yet!

This criterion is, of course, naive in the extreme and cannot be used
with dieharder!  It makes just as much sense to reject a generator
that has p-values of 0.95 or more!  Both of these p-value ranges are
equally unlikely on any given test run, and should be returned for (on
average) 5% of all test runs by a perfect random number generator.  A
generator that fails to produce p-values less than 0.05 5% of the time
it is tested with different seeds is a bad random number genera‐ tor,
one that fails the test of the null hypothesis.  Since dieharder
returns over 100 pvalues by default per test, one would expect any
perfectly good rng to "fail" such a naive test around five times by
this criterion in a single dieharder run!

## Pseudorandom number generators

> "Anyone who attempts to generate random numbers by deterministic
> means is, of course, living in a state of sin." --- John von Neumann

![xkcd: Random number](/images/xkcd-random-4.png)

![Elementary cellular automata, rule 30](/images/eca-rule30-snip.png)

http://en.wikipedia.org/wiki/Rule_30

## Human generation of random sequences

> "The generation of random sequences is known to be a complex,
> demanding and effortful task for adults." [1]

## Infinite monkeys

![Infinite monkeys](/images/infinite-monkeys.jpg)

(infinite monkeys: probably will just produce monkey text, because
they probably lack the executive functions needed to generate
sufficiently random keypresses)

## Podcast

http://www.bbc.co.uk/programmes/b00x9xjb

## References

[1] -
[An exploration of random generation among children](http://onlinelibrary.wiley.com/doi/10.1348/026151099165348/abstract) [PDF](/pdf/towse1999exploration.pdf)

[2] -
[Random number generation and creativity](http://www.sciencedirect.com/science/article/pii/S0306987707005221) [PDF](/pdf/
