---
layout: default
title: Haskell quick introduction
---

## Key points

### Every valid expression is a value

Values are values (e.g., `5`). Variables are values. Variables do not
*hold* values; they *are* values (but with names). Functions are
values. **Programs are values.**

Here are some values.

{% highlight haskell %}
x = 5

q = let y = x + 10
    in y + 3

r = z * x + w
    where w = 4
          z = 3

f c = c*c

main = do putStrLn (show (f 3))
          putStrLn (show r)
{% endhighlight %}

Run `ghci` on the file
[haskell-quick-intro.hs](/code/haskell-quick-intro.hs) and type `x`,
`q`, and `r` to show the various computed values:

```
$ ghci haskell-quick-intro.lhs
GHCi, version 7.8.3: http://www.haskell.org/ghc/  :? for help
Loading package ghc-prim ... linking ... done.
Loading package integer-gmp ... linking ... done.
Loading package base ... linking ... done.
[1 of 1] Compiling Main             ( haskell-quick-intro.lhs, interpreted )
Ok, modules loaded: Main.
*Main> x
5
*Main> q
18
*Main> r
19
*Main> main
hello
9
19
*Main> t
hello
9
19
*Main>
```

### Variables never vary; they are "bound"

{% highlight haskell %}
x2 = 55
x2 = 75 -- not gonna work
{% endhighlight %}

We can see it's not gonna work by reloading the file in `ghci`:

```
*Main> :reload
[1 of 1] Compiling Main             ( haskell-quick-intro.hs, interpreted )

haskell-quick-intro.hs:22:1:
    Multiple declarations of ‘x2’
    Declared at: haskell-quick-intro.hs:21:1
                 haskell-quick-intro.hs:22:1
Failed, modules loaded: none.
```

### Every value has a specific type

Let's ask `ghci` about the types of the variables we bound:

```
*Main> :t q
q :: Integer
*Main> :t x
x :: Integer
*Main> :t q
q :: Integer
*Main> :t r
r :: Integer
*Main> :t f
f :: Num a => a -> a
*Main> :t main
main :: IO ()
*Main> :t t
t :: IO ()
*Main>
```

### Types are inferred

We didn't define the type of the function `f`. It inferred it had to
be `a -> a` where `a` is one of the number types. Why? Because we used
`*`, which has the type:

```
*Main> :type (*)
(*) :: Num a => a -> a -> a
*Main>
```

In other words, it takes two values of type `a` (i.e., any type, so
long as it has parent type `Num`) and gives back a value of the same
type.

### Functions are just partially-realized values

Functions have types like `Int -> Int` or `a -> b -> a` (for some
types `a` and `b`). Any lower-case type, such as `a`, means "any type
can go here." Of course, when the function is actually executed, if
`a` matches up to type `X`, all `a` type values in the function must
be type `X` for that function call.

Give a function one of its several arguments, and it just becomes a
"slightly more realized" value. I.e., that argument is replaced with
its value everywhere it appears in the function, but the function
still is not fully realized. Normal variables, like `x` above (first
example), are simply fully-realized values.

Example of a function:

{% highlight haskell %}
average_three_values x y z = (x + y + z) / 3.0
{% endhighlight %}

Let's interrogate the types and values:

```
*Main> :t average_three_values
average_three_values :: Fractional a => a -> a -> a -> a
*Main> :t (average_three_values 8.0)
(average_three_values 8.0) :: Fractional a => a -> a -> a
*Main> :t (average_three_values 8.0 9.0)
(average_three_values 8.0 9.0) :: Fractional a => a -> a
*Main> :t (average_three_values 8.0 9.0 10.0)
(average_three_values 8.0 9.0 10.0) :: Fractional a => a
*Main> let avg2 = (average_three_values 8.0)
*Main> let avg3 = (avg2 9.0)
*Main> let avg4 = (avg3 10.0)
*Main> avg4
9.0
```

This method of partial application is called *currying* (after the
mathematician Haskell Curry).

### Values are computed lazily (as-needed)

When compiling a binary, execution starts in `main`. Whatever value
`main` computes, and whatever values that computation depends on, are
the only values computed.

So, in this code, `y` is never computed:

{% highlight haskell %}
main = let x = 5
           y = x * x
       in do putStrLn "hello"
             putStrLn x
{% endhighlight %}

This means you can actually use infinite lists, for example, and never
have a problem (unless you try to process the whole list...).

### Side-effects are not allowed

**There are only values.** In the code `x + y`, for example, there is
no "room" for some random "print" statement or whatever. It would look
like `x + (putStr "foo") + y`, which doesn't make sense because
`putStr` is not a numeric type (so it can't be added).

Due to laziness (see previous point), even this never prints anything
(if it were even valid code, and it's not for another reason, see
below):

{% highlight haskell %}
f x = let y = putStr "foo"
      in (2+x*x)
{% endhighlight %}

That's because `y` is never needed, so its value is never
computed. Likewise, this does not work:

{% highlight haskell %}
f x = putStr "foo"
      (2+x*x)
{% endhighlight %}

This example does not compile because `putStr` has type (and value)
`IO ()` (i.e., void), which does not contribute to any arithmetic
computation; it cannot feed into the next value `(2+x*x)` because (1)
`(2+x*x)` is not a function and (2) if we put a function there, it has
to be of special type `IO () -> IO a`, i.e., it has to accept a void
input. Such functions do exist, but they have to be used in a special
way; see the next section.

Generally, you can't put a "print" statement, or anything else with
side-effects, in a position where it does not contribute to a
computation. You can only do side-effects when using the IO trick
(next section).

### IO is a trick

Since Haskell disallows side-effects, as described previously, there
has to be some fancy trick to enable a program to read input from the
outside world and send output to the screen or elsewhere. This trick
is with a "monad."

The basic idea is that the `main` function, where everything begins,
is given the `IO` object. Any code that wants to do input/output must
use this `IO` object. The `IO` object is passed along to each
input/output action, in sequence (each action hands it off to the next
action). The result of input can be extracted from the `IO` object,
and used in other "pure" computations (which aren't given the `IO`
object), but the value extraction operation still must exist in a
sequence passing along the `IO` object.

Example:

{% highlight haskell %}

main = do putStr "Type your name: "
          name <- getLine
          putStr "Your name is: "
          putStrLn name
          putStr "Type a number: "
          num_str <- getLine
          let num  = read num_str
              num2 = num * num + 5
            in do putStr "New number: "
                  putStrLn (show num2)
          putStrLn "We're done."
{% endhighlight %}

It's hidden from us (due to the special `do` syntax), but the `IO`
object is being passed across `putStr`, `putStrLn`, and `getLine`. The
`let` only sets up bindings, it's not part of the chain.

```
*Main> :reload
[1 of 1] Compiling Main
*Main> :main
Type your name: Josh
Your name is: Josh
Type a number: 23
New number: 534
We're done.
*Main>
```

## "Functional programming" is programming with data

In functional programming, every operation transforms or generates
data. There are no operations (except the IO trick) that simply
perform actions for the sake of producing side effects (e.g.,
modifying memory, launching missles, inserting into or querying
databases, etc.).

[Of course, with the IO trick, we really can produce side-effects and
launch missiles, or whatever. But the program is still "pure" because
it acts as if these side-effects are actually just "values" that will
be the same every time the program runs.]

- There are no loops. A loop means "do something X times." That is not
  a data transformation or generation operation; it is an operation
  that is intended to produce side-effects.

- There is no way to "break" out of a function (nor a loop, because
  there are no loops). Functions turn into values; if you want the
  function to finish, just ensure it results in the appropriate value
  at the appropriate time.

- Conditionals must always have an "else" value; if they didn't, what
  would be the value of the conditional when the `if` part is false?
  Remember, every expression must turn into a value.

- There are no pointers and no mutable arrays. All function calling is
  call-by-value; a function always receives a copy of each of its
  arguments.

**Except for (minimal) IO code, functional programs play with
data. Functional programs are not composed of "statements" but rather
they are composed of data manipulations. Every output of a function
is the input to another function.**

## Lists are a crucial data structure

Often, we have lots of data. Often, these data are collected into
lists. Not surprisingly, there exist many simple functions that play
with lists. The main functions are:

- `map`: apply a (unary) function to every element in the list,
  resulting in a new list

- `filter`: drop elements from the list according to a (unary)
  function; when that function returns false for some element, the
  element is left out; a new list results

- `foldr`: "fold" a list by applying a (binary) function to the first
  and second element, then the result of that with the third element,
  the result of that with the fourth element, etc., resulting in a
  single value. (`foldr` means fold-to-the-right; there is `foldl`,
  too).

You can also pull apart the head and tail when binding:

{% highlight haskell %}
let (x:xs) = [1, 2, 3, 4, 5]
in ...
{% endhighlight %}

In that code, `x` is `1`, `xs` is `[2, 3, 4, 5]`.

Examples of `map`, `filter`, and `foldr`:

{% highlight haskell %}
xs = [1, 3, 5, 2, 6, 2, 5, 8]

my_mapping_fn n = 2*n

xs2 = map my_mapping_fn xs

my_filtering_fn n = (n `mod` 2 == 0)

xs3 = filter my_filtering_fn xs

my_foldr_fn m n = (m * n + 5)

-- foldr needs three arguments: the folding fn, an initial value (for
-- the first folding fn call), and the list
xs4 = foldr my_foldr_fn 10 xs
{% endhighlight %}

Here are their values:

```
*Main> :reload
[1 of 1] Compiling Main             ( haskell-quick-intro.hs, interpreted )
Ok, modules loaded: Main.
*Main> xs
[1,3,5,2,6,2,5,8]
*Main> xs2
[2,6,10,4,12,4,10,16]
*Main> xs3
[2,6,2,8]
*Main> xs4
155950
*Main>
```

### "List comprehensions" generate new lists

It's often very convenient to generate a new list simply by describing
what it would look like. Examples:

```
*Main> [x | x <- [1..3]]
[1,2,3]
*Main> [y*2 | y <- [1..5]]
[2,4,6,8,10]
*Main> [y*2+x | y <- [1..5], x <- [4, 2, 6, 2]]
[6,4,8,4,8,6,10,6,10,8,12,8,12,10,14,10,14,12,16,12]
*Main> [(x,y) | x <- [1..5], y <- [1..5], x < y]
[(1,2),(1,3),(1,4),(1,5),(2,3),(2,4),(2,5),(3,4),(3,5),(4,5)]
*Main> [x | x <- [q | q <- [1..5]]]
[1,2,3,4,5]
*Main>
```

### Other list functions

- `++`: append two lists: `xs ++ ys`

- `head`: get the head of a list

- `tail`: get the tail of a list

- `length`: get the length of a list

- `reverse`: reverse a list

- `!!`: get the nth element: `xs !! 3`

- `take`, `drop`: keep or drop a certain number of values

- `splitAt`: split a list into two at a certain position

Many more list functions are available in the
[Prelude](http://hackage.haskell.org/package/base-4.7.0.1/docs/Prelude.html#g:11),
i.e., Haskell's standard library.

## Examples

### Quicksort

{% highlight haskell %}
quickSort []     = []
quickSort (x:xs) = quickSort [a | a <- xs, a < x]   -- Sort the left part of the list
                   ++ [x] ++                        -- Insert pivot between two sorted parts
                   quickSort [a | a <- xs, a >= x]  -- Sort the right part of the list
{% endhighlight %}

## Useful libraries

Just a sample, obviously.

- [Yesod](http://www.yesodweb.com/) -- A spiffy web framework for
  building large web apps in Haskell. Among other cool features: SQL
  injections are impossible, due to Haskell's strong type
  system. Broken (internal) links are also impossible.

- [QuickCheck](https://github.com/nick8325/quickcheck) -- Generates
  random test inputs, based on the types of the parameters, and when
  tests fail, automatically narrows down the failing example to a
  (nearly) minimal failing case.

- [Persistent](http://www.yesodweb.com/book/persistent) -- Database
  library (SQL databases, et al.).

- [Shakespearean Templates](http://www.yesodweb.com/book/shakespearean-templates)
  -- HTML, CSS, JavaScript template libraries.

- [Conduit](https://github.com/snoyberg/conduit) -- Efficient handling
  of streams large and small, of all varieties (console IO, network
  IO, binary file IO, etc.).

- [OpenGL](http://www.haskell.org/haskellwiki/OpenGL) -- See link for
  other game stuff as well.

## Famous philosophical articles and a video

- [J. Backus, "Can Programming Be Liberated from the von Neumann Style?
  A Functional Style and Its Algebra of Programs," 1978.](/pdf/a1977-backus.pdf)
  -- Given that functional programming is so different, can we build
  machines differently to take better advantage of programming with
  values (rather than instructions, registers, and memory)?

- [J. Hughes, "Why Functional Programming Matters," 1989.](/pdf/The Computer Journal-1989-Hughes-98-107.pdf) -- Argues that functional
  programming allows us to build more modular, more well-behaved
  programs.

- [B. Moseley & P. Marks, "Out of the Tar Pit," 2006.](/pdf/tarpit.pdf)
  -- Attempts to come to grips with *complexity*, particularly
  *accidental complexity*. I believe it is crucial to understand this
  paper and its explanation of why everything is so hard.

- [R. Hickey, "Simple Made Easy," 2011.](http://www.infoq.com/presentations/Simple-Made-Easy) -- A video of a conference presentation in which Rich Hickey,
  creator of Clojure (another functional language), distinguishes
  "simple" from "easy" and crucially introduces the word "complect" to
  mean "A is complected with B when A and B cannot be easily
  separated, their concerns are entwined." Complecting is the source
  of complexity. Functional programming reduces the likelihood of
  complecting various functions, modules, systems because functional
  programs, if done right, can be paragons of "isolation of concerns."

