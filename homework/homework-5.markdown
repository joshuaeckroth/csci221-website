---
title: Homework 5
layout: default
---

Given a class that represents mathematical parse trees, write
functions that simplify the tree and find the derivative of the tree.

Skills needed to complete this assignment:

- [Memory management](/lecture/memory-management.html), including
  destructors

- [Trees](/lecture/trees.html)

Name your BitBucket repository **exactly** `csci221-homework5`.

**You may work in a group of two.** Let me know whose repository
contains the code.

## Requirements

- Grab the code on Londo at
  `/home/jeckroth/csci221-public/homework-5`. You should find these
  files:

  - `Makefile` -- obvious; you do not need to modify this file.

  - `main.cpp` -- has a loop that accepts a line of input, then parses
    it (creating the tree structure), prints it, simplifies it and
    prints it again, derives it and prints it again, and then
    simplifies the derivative and prints that. You do not need to
    modify this file.

  - `asciitree.cpp` and `asciitree.h` -- some library code to print a
    graphical tree. You do not need to modify these files.

  - `scanner.l` -- definition of how to break up the user's input into
    "tokens", which are fed into the parser. You do not need to modify
    this file.

  - `parser.ypp` -- definition of how to take tokens and build math
    trees (see examples below). You do not need to modify this file.

  - `mathtree.h` -- header file for `Tree` class. You do not need to
    modify this file.

  - `mathtree.cpp` -- source for `Tree` class. **You need to modify
    this file.** The functions that need to be implemented are marked
    with `TODO`.

- Implement these functions: `Tree::~Tree()`, `Tree::simplify_rec()`,
  and `Tree::derive()`.

  - `Tree::~Tree()` -- this is the destructor, so it needs to clean up
    the tree by following all the left/right links and deleting
    all the subtrees.

  - `Tree::simplify_rec()` -- this is the recursive simplification
    function. It simplifies the current tree (the `this` pointer) and
    returns a **new** tree, or it returns `this` if no simplification
    is possible. See the simplification rules below.

  - `Tree::derive()` -- finds the derivative of the current tree (the
    `this` pointer), and returns a **new** tree that represents this
    derivative. See the derivative rules below.

- Eliminate all memory leaks. This is hard!

## About the tree structure

These trees have left/right subtrees, which might be `NULL`, and some
other values:

- `op` -- a `string`, which might contain an operator, or might be
  empty. Possible **binary** operators are: `+, -, /, *, ^`. Possible
  **unary** operators are: `sin, cos, ln`. Unary operators have a
  `NULL` right tree.

- `val` -- a `double`, which contains a meaningful value only in the
  cases when `op == ""` and `var = 0`.

- `var` -- a `char`, which contains the value `'x'` (the only possible
  variable according to the parser), only in cases when `op ==
  ""`. When the tree is not a variable, but rather a value, then `var
  = 0` (the null character, ASCII 0).

There are convenience functions `is_var()`, `is_val()`,
`is_unary_op()`, and `is_binary_op()` that determine the nature of a
tree.

## Simplification rules

During simplification, produce a new tree according to the following
rules. Note that `simplify(foo)` means call `simplify_rec()` on the
subtree `foo`.

- `1.0 * foo => simplify(foo)` -- i.e., remove the 1.0 multiplier

- `foo * 1.0 => simplify(foo)`

- `0.0 * foo => 0.0`

- `foo * 0.0 => 0.0`

- `0.0 + foo => simplify(foo)`

- `foo + 0.0 => simplify(foo)`

- `sin(foo)` or `cos(foo)` or `ln(foo)`, in cases where `foo` turns
  out to be a number, after simplifying, (`is_val()` is true), then
  the result is to actually compute `sin` or `cos` or `ln` on the
  simplified version of `foo`. Otherwise, if the simplified `foo` is
  not a value, just return `sin(simplify(foo))` etc.

- `foo + bar` or `foo - bar` or `foo * bar` or `foo / bar` or `foo ^
  bar`, in cases where both `foo` and `bar` simplify to values,
  compute the actual function; otherwise, return `simplify(foo) +
  simplify(bar)`, etc.

- If those rules don't apply, return the original tree (`return
  this;`)

## Derivative rules

- If the tree is just the var `x`, return a new tree representing
  `1.0`.

- If the tree is just a constant value, return a new tree representing
  `0.0`.

- If the tree is `sin(foo)`, return a new tree representing
  `cos(foo) * derive(foo)`.

- If the tree is `foo + bar`, return a new tree representing
  `derive(foo) + derive(bar)`.

Etc. I'll leave the rest up to you. You must implement these
derivation rules:

- `sin`, `cos`, `ln` rules

- `+`, `-`, `*`
  ([product rule](http://en.wikipedia.org/wiki/Differentiation_rules#The_product_rule)),
  `/`
  ([quotient rule](http://en.wikipedia.org/wiki/Differentiation_rules#The_quotient_rule)),
  `^`
  ([power rule](http://en.wikipedia.org/wiki/Differentiation_rules#Generalized_power_rule))

## Extra credit

Support some symbolic integrals. Depending on how many patterns you support, you will get more or less extra credit.
  
## Example executions

User input is underlined.

<hr/>

<pre>
Enter expression: <u>5 + 2 * 3</u>

Original tree:

    +
   / \
  /   \
5.00   *
      / \
     /   \
    /     \
  2.00   3.00

Simplified tree:

11.00

Printed in pre-order:
11


Derivative tree:

         +
        / \
       /   \
     0.00   +
           / \
          /   \
         /     \
        /       \
       /         \
      /           \
     *             *
    / \           / \
   /   \         /   \
  /     \       /     \
2.00   0.00   0.00   3.00

Printed in pre-order:

(0 + ((2 * 0) + (0 * 3)))

Simplified derivative tree:

0.00

Printed in pre-order:

0
</pre>

<hr/>

<pre>
Enter expression: <u>x</u>

Original tree:

x

Simplified tree:

x

Printed in pre-order:
x


Derivative tree:

1.00

Printed in pre-order:

1

Simplified derivative tree:

1.00

Printed in pre-order:

1
</pre>

<hr/>

<pre>
Enter expression: <u>5^x</u>

Original tree:

    ^
   / \
  /   \
5.00   x

Simplified tree:

    ^
   / \
  /   \
5.00   x

Printed in pre-order:
(5 ^ x)


Derivative tree:

         *
        / \
       /   \
      /     \
     /       \
    ^         +
   / \       / \
  /   \     /   \
5.00   x   /     \
          /       \
         /         \
        *           *
       / \         / \
      /   \       /   \
    0.00   /    1.00  ln
          / \         /
         /   \      5.00
        x   5.00

Printed in pre-order:

((5 ^ x) * ((0 * (x / 5)) + (1 * ln(5) )))

Simplified derivative tree:

       *
      / \
     /   \
    ^   1.61
   / \
  /   \
5.00   x

Printed in pre-order:

((5 ^ x) * 1.60944)
</pre>

<hr/>

<pre>
Enter expression: <u>sin(cos(x))</u>

Original tree:

   sin
   /
 cos
 /
x

Simplified tree:

   sin
   /
 cos
 /
x

Printed in pre-order:
sin(cos(x) ) 


Derivative tree:

       *
      / \
     /   \
   cos    *
   /     / \
 cos    /   \
 /     -   1.00
x     / \
     /   \
   0.00  sin
         /
        x

Printed in pre-order:

(cos(cos(x) )  * (-sin(x)  * 1))

Simplified derivative tree:

       *
      / \
     /   \
   cos    -
   /     / \
 cos    /   \
 /    0.00  sin
x           /
           x

Printed in pre-order:

(cos(cos(x) )  * -sin(x) )
</pre>

<hr/>

<pre>
Enter expression: <u>sin(x) + cos(5 * ln(x))</u>

Original tree:

     +
    / \
   /   \
 sin   cos
 /     /
x     *
     / \
    /   \
  5.00  ln
        /
       x

Simplified tree:

     +
    / \
   /   \
 sin   cos
 /     /
x     *
     / \
    /   \
  5.00  ln
        /
       x

Printed in pre-order:
(sin(x)  + cos((5 * ln(x) )) )


Derivative tree:

           +
          / \
         /   \
        /     \
       /       \
      /         \
     *           *
    / \         / \
   /   \       /   \
 cos  1.00    /     \
 /           /       \
x           /         \
           /           \
          /             \
         -               +
        / \             / \
       /   \           /   \
     0.00  sin        /     \
           /         /       \
          *         /         \
         / \       *           *
        /   \     / \         / \
      5.00  ln   /   \       /   \
            /  5.00   /    0.00  ln
           x         / \         /
                    /   \       x
                  1.00   x

Printed in pre-order:

((cos(x)  * 1) + (-sin((5 * ln(x) ))  * ((5 * (1 / x)) + (0 * ln(x) ))))

Simplified derivative tree:

       +
      / \
     /   \
   cos    *
   /     / \
  x     /   \
       /     \
      /       \
     /         \
    -           *
   / \         / \
  /   \       /   \
0.00  sin   5.00   /
      /           / \
     *           /   \
    / \        1.00   x
   /   \
 5.00  ln
       /
      x

Printed in pre-order:

(cos(x)  + (-sin((5 * ln(x) ))  * (5 * (1 / x))))
</pre>

<hr/>

<pre>
Enter expression: <u>x^2 / (sin(x) * (x + 5))</u>

Original tree:

         /
        / \
       /   \
      /     \
     /       \
    /         \
   ^           *
  / \         / \
 /   \       /   \
x   2.00   sin    +
           /     / \
          x     /   \
               x   5.00

Simplified tree:

         /
        / \
       /   \
      /     \
     /       \
    /         \
   ^           *
  / \         / \
 /   \       /   \
x   2.00   sin    +
           /     / \
          x     /   \
               x   5.00

Printed in pre-order:
((x ^ 2) / (sin(x)  * (x + 5)))


Derivative tree:

                                         /
                                        / \
                                       /   \
                                      /     \
                                     /       \
                                    /         \
                                   /           \
                                  /             \
                                 /               \
                                /                 \
                               /                   \
                              /                     \
                             /                       \
                            /                         \
                           -                           *
                          / \                         / \
                         /   \                       /   \
                        /     \                     /     \
                       /       \                   /       \
                      /         \                 /         \
                     /           \               /           \
                    /             \             *             *
                   /               \           / \           / \
                  /                 \         /   \         /   \
                 /                   \      sin    +      sin    +
                *                     *     /     / \     /     / \
               / \                   / \   x     /   \   x     /   \
              /   \                 /   \       x   5.00      x   5.00
             /     \               /     \
            /       \             /       \
           /         \           /         \
          /           \         ^           +
         *             *       / \         / \
        / \           / \     /   \       /   \
       /   \         /   \   x   2.00    /     \
      /     \      sin    +             /       \
     /       \     /     / \           /         \
    /         \   x     /   \         /           \
   ^           +       x   5.00      /             \
  / \         / \                   /               \
 /   \       /   \                 /                 \
x   2.00    /     \               *                   *
           /       \             / \                 / \
          /         \           /   \               /   \
         *           *        sin    +             /     \
        / \         / \       /     / \           /       \
       /   \       /   \     x     /   \         /         \
     1.00   /    0.00  ln         /     \       *           +
           / \         /        1.00   0.00    / \         / \
          /   \       x                       /   \       /   \
        2.00   x                            cos  1.00    x   5.00
                                            /
                                           x

Printed in pre-order:

(((((x ^ 2) * ((1 * (2 / x)) + (0 * ln(x) ))) * (sin(x)  * (x + 5))) - ((x ^ 2) * ((sin(x)  * (1 + 0)) + ((cos(x)  * 1) * (x + 5))))) / ((sin(x)  * (x + 5)) * (sin(x)  * (x + 5))))

Simplified derivative tree:

                                         /
                                        / \
                                       /   \
                                      /     \
                                     /       \
                                    /         \
                                   /           \
                                  /             \
                                 /               \
                                /                 \
                               /                   \
                              /                     \
                             /                       \
                            /                         \
                           -                           *
                          / \                         / \
                         /   \                       /   \
                        /     \                     /     \
                       /       \                   /       \
                      /         \                 /         \
                     /           \               /           \
                    /             \             *             *
                   /               \           / \           / \
                  /                 \         /   \         /   \
                 /                   \      sin    +      sin    +
                *                     *     /     / \     /     / \
               / \                   / \   x     /   \   x     /   \
              /   \                 /   \       x   5.00      x   5.00
             /     \               /     \
            /       \             /       \
           /         \           /         \
          /           \         ^           +
         *             *       / \         / \
        / \           / \     /   \       /   \
       /   \         /   \   x   2.00   sin    *
      /     \      sin    +             /     / \
     /       \     /     / \           x     /   \
    /         \   x     /   \              cos    +
   ^           /       x   5.00            /     / \
  / \         / \                         x     /   \
 /   \       /   \                             x   5.00
x   2.00   2.00   x

Printed in pre-order:

(((((x ^ 2) * (2 / x)) * (sin(x)  * (x + 5))) - ((x ^ 2) * (sin(x)  + (cos(x)  * (x + 5))))) / ((sin(x)  * (x + 5)) * (sin(x)  * (x + 5))))
</pre>
