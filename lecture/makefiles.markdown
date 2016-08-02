---
layout: default
title: Makefiles
---

# Makefiles

When we have larger projects, it is much more efficient to compile
only the modified files rather than all files. `Makefiles` let us
define these dependencies and rebuild our project with simple
commands.

## Dependency graph

Suppose we have a program made up of some files: `main.cpp`,
`foo.cpp`, `foo.h`, `bar.cpp`, and `bar.h`. The dependencies among
these are as follows (suppose):

<div style="text-align: center;">
<img src="/images/makefile-deps.png" alt="Makefile dependencies (example)" />
</div>

From this diagram, we can infer the following properties of the build
process:

- When `foo.h` is modified, both `foo.cpp` and `main.cpp` need to be
  recompiled, and the binary `myprogram` needs to be linked.

- When `foo.cpp` is modified, it needs to be recompiled, and the
  binary needs to be linked.

- When `main.cpp` is modified, it needs to be recompiled, and the
  binary needs to be linked.

Notice that when `main.cpp` is modified, for example, neither
`foo.cpp` nor `bar.cpp` need to be recompiled. This is because they do
not `#include` anything from `main.cpp` (not even recursively from
their `#include`'s).

## Example Makefile

Here is a `Makefile` that handles building the project shown in the
diagram. We would name this file `Makefile` and put it in the same
directory as our source files (though the source files could be
anywhere, technically).

{% highlight makefile %}
foo.o: foo.cpp foo.h
	g++ -Wall -ansi -pedantic -g -O2 -c foo.cpp

bar.o: bar.cpp bar.h
	g++ -Wall -ansi -pedantic -g -O2 -c bar.cpp

main.o: main.cpp foo.h bar.h
	g++ -Wall -ansi -pedantic -g -O2 -c main.cpp

myprogram: main.o foo.o bar.o
	g++ -Wall -ansi -pedantic -g -O2 -o myprogram main.o foo.o bar.o
{% endhighlight %}

**Note: The space before the g++ commands must be a TAB! All actions
must be indented by honest-to-god \t tabs.**
    
We have a lot of repetition in the compiler flags (`-Wall -ansi
...`). Let's use a variable to clean that up. We'll also use a
variable for the compiler command, in case we change compilers later
(on a different operating system, for example).

{% highlight makefile %}
CXX = g++
CXXFLAGS = -Wall -ansi -pedantic -g -O2

foo.o: foo.cpp foo.h
	$(CXX) $(CXXFLAGS) -c foo.cpp

bar.o: bar.cpp bar.h
	$(CXX) $(CXXFLAGS) -c bar.cpp

main.o: main.cpp foo.h bar.h
	$(CXX) $(CXXFLAGS) -c main.cpp

myprogram: main.o foo.o bar.o
	$(CXX) $(CXXFLAGS) -o myprogram main.o foo.o bar.o
{% endhighlight %}

## Using a Makefile

We can run the `make` command, and give a target (goal), as follows:

```
make foo.o
```

Or more likely:

```
make myprogram
```

The `make` program first reads the `Makefile` (if you named it
something use, use `make -f mymakefile`), and determines the
dependencies of the specified target. If the target file is newer than
all of the dependencies (by checking modified time on the files), then
there is nothing to do. If one or more of the dependencies are newer,
then the target is regenerated.

Actually, all dependencies are checked in the same way first,
recursively. So if `foo.h` has been modified more recently than either
`myprogram` (original target) or `main.o` or `foo.o`, then all the
out-of-date targets are rebuilt.

## Useful non-file targets

Most targets are filenames (e.g., `myprogram` or `foo.o`). However, we
sometimes want some other targets just for convenience. One special
target is `all`:

{% highlight makefile %}
...

all: myprogram
{% endhighlight %}

The `all` target typically has no associated actions, but just depends
on the target you're most often going to use. Now, if you just run
`make` with no target, it will assume the `all` target, which in this
case is actually the `myprogram` target.

We can also make "phony" targets that have no dependencies but just
perform useful actions. One common example is the `clean` target:

{% highlight makefile %}
.PHONY: clean
clean:
	rm -f *.o myprogram
{% endhighlight %}

In this example, we can run `make clean` to delete all the generated
files, including the program binary. By doing this, we can run `make
clean` followed by `make` to ensure we are rebuilding the entire
project from scratch.
