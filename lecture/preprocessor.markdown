---
layout: default
title: Preprocessor
---

C++ supports a special embedded language that is parsed before the
rest of the code is parsed. Commands ("directives") in this embedded
language always start with `#`. It is useful for including files,
excluding code based on simple conditions, and creating little macro
functions.

## Preproccesor workflow

As we saw in the [compiler notes](/lecture/gcc-compiler.html), the
preprocessor handles source code before it is compiled. Preprocessor
directives can muck around with the file in significant ways.

## Preprocessor directives

### #define, #undef

{% highlight c++ %}
#define SOME_CONSTANT 55
#define getmax(a,b) ((a) > (b) ? (a) : (b))
#define debug(x) cout << x << endl;
#undef SOME_CONSTANT
{% endhighlight %}

The key to remember about `#define` is whenever the new name (e.g.,
`SOME_CONSTANT`) or macro (e.g., `getmax(5,2)`) appears in the source,
it is **replaced** by the right side of the `#define` code. So every
use of `SOME_CONSTANT` is replaced by `55` before compilation even
begins.

This replacement happens without syntax checking or type
checking. It's easy to replace with invalid code. Use `#define`
sparingly, especially when defining macros.

### #if, #else, #elif, #endif, #ifdef, #ifndef

{% highlight c++ %}
#if SOME_CONSTANT > 5
// some code...
#else
// some other code
#endif
{% endhighlight %}

You can also use `#ifdef` to check if something is defined (but you
don't care about the value), or `#ifndef` to check if it's not
defined.

{% highlight c++ %}
#ifdef DEBUG
// some code...
#endif
{% endhighlight %}

Preprocessor variables can be defined on the command line, making
these kind of `#ifdef DEBUG` directives especially useful for turning
on / turning off debug code. Use the `-DFOO` option, where `FOO` is
the variable to define. Use `-DFOO=3` to give `FOO` a value.

```
g++ -c -DDEBUG myfile.cpp
```

### #include

This directive copy-pastes a specified file into the location of the
`#include` directive. If angle-brackets are used (`<somefile.h>`),
then the default system paths are searched for the file. If quotes are
used, then the directory of the source file is searched first, then
system paths. You can also give search paths on the command line with
`-I/some/path`.
