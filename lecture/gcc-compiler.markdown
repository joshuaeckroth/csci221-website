---
layout: default
title: GCC compiler
---

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
<td>
Produce warnings for all potential errors.
</td>
</tr>
<tr>
<td>
<code>-g</code>
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
