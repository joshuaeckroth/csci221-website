---
layout: default
title: Documentation
---

# Documentation

It's important to document your code. Document your code. But not too much. Because I said so.

## Doxygen

[Doxygen](http://www.stack.nl/~dimitri/doxygen/) is a convenient tool that automatically scans your code and produces a website with source code listings, hyperlinked class overviews with all attributes and methods, UML class diagrams, etc. It can produce PDF reports as well, though I find those less useful.

On Londo, create a `docs` folder in your source folder, copy my [Doxyfile](/code/Doxyfile) to your source folder and run the `doxygen` command. It will produce HTML documentation in the `docs` folder. You might want to zip it all up with `zip -r mydocs.zip docs/` and copy the resulting `mydocs.zip` file to your own computer.

## How to document your code

Generally, you'll want some comments above your class definitions and above complex methods. Use JavaDoc format, even in C++:

{% highlight cpp %}
/** Brief description which ends at this dot. Details follow
 *  here.
 */
{% endhighlight %}

Example:

{% highlight cpp %}
/**
 *  A test class. A more elaborate class description.
 */
class Test
{
  public:
      /**
       * A constructor.
       * A more elaborate description of the constructor.
       */
      Test();
      /**
       * A destructor.
       * A more elaborate description of the destructor.
       */
     ~Test();
    
      /**
       * a normal member taking two arguments and returning an integer value.
       * @param a an integer argument.
       * @param s a constant character pointer.
       * @see Test()
       * @see ~Test()
       * @see testMeToo()
       * @see publicVar()
       * @return The test results
       */
       int testMe(int a,const char *s);
       
      /**
       * A pure virtual member.
       * @see testMe()
       * @param c1 the first argument.
       * @param c2 the second argument.
       */
       virtual void testMeToo(char c1,char c2) = 0;
   
      /** 
       * a public variable.
       * Details.
       */
       int publicVar;
       
      /**
       * a function variable.
       * Details.
       */
       int (*handler)(int a,int b);
};
{% endhighlight %}

That example is from the [Doxygen manual](http://www.stack.nl/~dimitri/doxygen/manual/index.html).

## Should I really bother?

There are possibly three groups of programmers:

- Those who obsessively document their code (typically college grads).
- Those who never document their code (typically self-taught code cowboys/cowgirls, who have difficulty working with others).
- The rest.

Obsessive documenters are somewhat annoying because excessive verbiage hides the actual code:

{% highlight cpp %}
/** Extract the address from the message.
 * @param message The message
 * @return The address
 */
string extractAddressFromMessage(Message message)
{% endhighlight %}

Or worse:

<pre>
  //*********************************************************************
  //* Pattern name: MassiveFunctionHeaders                              *
  //* Pattern type: Anti                                                *
  //* Because:                                                          *
  //*   All imposed  structure is inherently  good, and to make  up for *
  //*   deficient  tools (lack  of on-demand  versioning reports),  and *
  //*   because our ancestors did it that way,                          *
  //* Therefore:                                                        *
  //*   Require  that  every  function  have a  massive  and  elaborate *
  //*   header.  Extra points awarded  for enclosing the whole thing in *
  //*   a box of ASCII characters so that it looks pretty.              *
  //* However:                                                          *
  //*   Due to the high cost of  creating and filling out massive head- *
  //*   ers, impels programmers to  add functionality to existing func- *
  //*   tions rather  than to  add new functions.   This  causes overly *
  //*   large functions.   Hard to maintain (edit this  example and get *
  //*   the  *'s to  line up).   The  inventor of  the header  tends to *
  //*   kitchen-sink it, so  that every function has  many empty fields *
  //*   that are  not carrying their  weight.  Many programmers  do not *
  //*   fill in even the fields  that apply, "insert method description *
  //*   here."   All modern  versioning tools will  give you  a version *
  //*   history for a  file.  It is incredibly stupid  to have to write *
  //*   a description for a method called "extractSourceAddressFromMes- *
  //*   sage."                                                          *
  //* Author: WayneConrad                                               *
  //* Creation date: 2000-02-18                                         *
  //* Version: 0.06                                                     *
  //* Version history:                                                  *
  //*   2000-02-18 wconrad   Initial check-in                           *
  //*   2002-05-16 tholenst  Adjustment of header                       *
  //*   2002-06-13 cwillu    Corrected above adjustment (missing '*')   *
  //*   2002-06-16 gkalnins  fixing version number and date format      *
  //*   2003-09-07 kknechtel Adjustment of version history              *
  //*   2003-10-13 kpanko    bug fix change of unclear nature           *
  //*   2010-09-11 bungalo   justified and hyphenated with TeX          *
  //*********************************************************************
</pre>

![Cate comment](/images/catedoge.jpg)

Both examples are from the wiki page [MassiveFunctionHeaders](http://c2.com/cgi/wiki?MassiveFunctionHeaders) -- that's the C2 Wiki, the *first* wiki.

Ideally, code will be self-documenting. There is no reason to assume the reader of your code is an idiot. Instead, assume the reader is quite intelligent but not necessarily sure what your code is trying to accomplish, and also not sure why your code even exists in the first place. The most important comments are those that explain **intentions and goals** rather than explain how the function works.

Here is a **bad example**:

{% highlight cpp %}
float a, b, c; a=9.81; b=5; c=0.5*a*(b^2);
{% endhighlight %}

That is not self-documenting code. This is:

{% highlight cpp %}
const float gravitationalForce = 9.81;
float timeInSeconds = 5;
float displacement = 0.5 * gravitationalForce * (timeInSeconds ^ 2);
{% endhighlight %}

And here it is with a small comment about why this code exists (this is a **good example**):

{% highlight cpp %}
/* compute displacement with Newton's equation x = vₒt + ½at² */
const float gravitationalForce = 9.81;
float timeInSeconds = 5;
float displacement = 0.5 * gravitationalForce * (timeInSeconds ^ 2);
{% endhighlight %}

This example was borrowed from a [StackOverflow post](http://stackoverflow.com/a/209089).
