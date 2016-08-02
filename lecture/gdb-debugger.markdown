---
layout: default
title: GDB debugger
---

# GDB debugger

## Starting the debugger

First, you'll need to compile your program with "debug symbols" using the `-g` switch:

```
g++ -Wall -g -o myprog myprog.cpp
```

Then, start GDB on your program:

```
gdb ./myprog
```

Now you can use the commands listed below.

## Getting help

- `help` -- list help topics

- `help data` -- list help topics about examining variables

- `help all` -- list all help topics

- `apropos break` -- list topics with the phrase "break"

## Breakpoints

- `break 10` -- set a breakpoint at line 10

- `break main` -- break when entering the `main()` function

- `delete 1` -- delete breakpoint number 1

- `delete` -- delete all breakpoints

## Running

- `run` -- start the program from the beginning

- `continue` -- continue running the program after stopping at a
  breakpoint

- `next` -- when at a breakpoint, execute the next line of code,
  stepping over function calls

- `step` -- when at a breakpoint, execute the next line of code, and
  step into function calls

- `stepi` -- when at a breakpoint, execute a single instruction (like
  an assembly language instruction)

- `kill` -- stop executing the program

Hit Ctrl-Z to stop a running program and go back to the gdb prompt.

## Variable inspection

- `display x` -- show the value of variable `x` (must be in scope at
  current breakpoint)

- `display &x` -- show the address of `x`

- `display *px` -- dereference a pointer `px` (show the value in
  memory that the pointer points to)

- `watch x` -- watch for changes to the variable `x`; each change
  triggers a break

- `info variables` -- show all known variables (slow!)

- `info variables myregex` -- show all known variables with names that
  match regular expression `myregex`

## Type inspection

- `ptype MyType` -- show the definition of a type `MyType`, which in
  the case of a class, shows the class methods and data (public and
  private).

- `info types` -- show all known types

- `info types myregex` -- show types matching regular expression
  `myregex` (e.g., `Rat.*` or `.*string.*`)

## Function inspection

- `info functions` -- show all known functions

- `info functions myregex` -- show all known functions with names
  matching regular expression `myregex`

## Stack traces

- `backtrace` -- show the stack of function calls

- `backtrace full` -- show the stack of function calls with local
  variable values

## Inspecting code

- `list` -- show source code nearby the current breakpoint

- `list 50` -- show source code nearby line 50

- `list 1,1000` -- show source code lines 1 to 1000

## Miscellaneous

- `info macro mymacro` -- show the source and location of definition
  for a preprocessor macro; requires compiling with `-ggdb3` instead
  of `-g`

- `info source` -- gives information about the program and its source;
  notice with the `-ggdb3` option, it says "Includes preprocessor
  macro info," while with `-g` it says "Does not include preprocessor
  macro info."

