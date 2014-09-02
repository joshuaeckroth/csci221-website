---
layout: default
title: GDB debugger
---

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

- `watch x` -- watch for changes to the variable `x`; each change
  triggers a break

## Stack traces

- `backtrace` -- show the stack of function calls

- `backtrace full` -- show the stack of function calls with local
  variable values

## Inspecting code

- `list` -- show source code nearby the current breakpoint

- `list 50` -- show source code nearby line 50

- `list 1,1000` -- show source code lines 1 to 1000
