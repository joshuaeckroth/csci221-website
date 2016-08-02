---
layout: default
title: GCC compiler
---

# GCC compiler

This page gives a few tips about the GNU Compiler Collection (GCC). As
evidenced by the name, GCC includes multiple compilers: `gcc` (C),
`g++` (C++), `gnat` (Ada), `gfortran` (Fortran), etc.

## Usage

We'll want to use a specific set of flags to improve error reporting,
debugging, and optimization:

<table>
<thead><th>Flag</th><th>Purpose</th></thead>
<tbody>
<tr>
<td>
<code>-ansi</code>
</td>
<td>
Produce errors for code that violates C++ ANSI standards.
</td>
</tr>
<tr>
<td>
<code style="white-space: nowrap;">-pedantic</code>
</td>
<td>
Similar to <code>-ansi</code>, but even stricter.
</td>
</tr>
<tr>
<td>
<code>-Wall</code>
</td>
<td>
Produce warnings for all potential errors.
</td>
</tr>
<tr>
<td>
<code>-g</code>
</td>
<td>
Include debugging symbols so we can effectively use <code>gdb</code>
on the resulting program.
</td>
</tr>
<tr>
<td>
<code>-O2</code>
</td>
<td>
Turn on aggressive optimizations. Sometimes we'll turn off
optimizations (<code>-O0</code>) when we want to inspect the machine
code produced by the compiler.
</td>
</tr>
</tbody>
</table>

`g++` can compile a single file at a time, producing an `object` file
(`.o` extension), or it can compile a mixture of source and object
files and produce a final binary program.

Compile a single file to an object file:

```
g++ -ansi -pedantic -Wall -g -O2 -c source1.cpp
```

You can compile each file separately, then join all the object files
to produce the final binary:

```
g++ -ansi -pedantic -Wall -g -O2 -o outfile source1.o source2.o source3.o
```

Alternatively, you can compile all the source files at the same time,
and produce the final binary program. This technique does not produce
intermediate object files.

```
g++ -ansi -pedantic -Wall -g -O2 -o outfile source1.cpp source2.cpp source3.cpp
```

Typing `g++` commands over-and-over is annoying, so we'll use
[Makefiles](/lecture/makefiles.html).

## Compiler workflow

<img src="/images/compiler-workflow.png" align="right" alt="Compiler workflow" />

The "compiler" is actually just one stage in a larger workflow that
transforms source files into a single binary program. The steps are as
follows, assuming we're compiling one file at a time:

1. Read the source file, and run it through the preprocessor. See the
   [preprocessor notes](/lecture/preprocessor.html) for details about
   that. The preprocessor may copy-paste `#include`'d files, among
   other things. Ultimately, raw C++ source comes out the other side.

2. Compile this raw C++ source into Assembler language source.

3. Assembler the assembler language source into an "object file,"
   which is binary (machine code) but not yet a working program.

<div style="clear: both;"></div>

The object file is only the compiled code from the single input
file. It likely refers to functions, variables, classes, etc. that are
defined in other source files. So the final step is to "link" various
object files into a final binary. This is shown in the diagram below:

<div style="text-align: center;">
<img src="/images/compiler-linker.png" alt="Linker" />
</div>

## Errors in compiling, linking

The compiler can produce these kinds of errors:

- Syntax errors
- Unknown variables/functions/classes
- Incompatible types

The linker can produce these kinds of errors:

- Undefined reference (function assumed to exist but actually no
  definition found)
- No `main()` function (not an error if just compiling a library,
  e.g., with `g++ -static` or `g++ -shared`)

Each of these groups of errors do not include "runtime errors," e.g.,
crashes, or logic errors.
