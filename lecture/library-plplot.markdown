---
layout: default
title: "Library: PLplot"
---

# Library: PLplot

Homepage: [PLplot](http://plplot.sourceforge.net/index.php), and its [manual](http://plplot.sourceforge.net/docbook-manual/plplot-html-5.10.0/index.html). In the manual, when a function is written `plfoo`, use it like `pls->foo()`.

## Installation

- Windows: Sorry, gotta [build from source](http://plplot.sourceforge.net/downloads.php#source_code).
- Linux: Find packages from your distribution, e.g., `libplplot-dev`
- Mac OS X: `brew install plplot` worked for me (let me know if you have an issue).

## Makefile

This works on Londo.

```
CXX=g++
CFLAGS=-Wall -g -I/usr/include/plplot -lplplotcxxd

all: main


main: main.o
    $(CXX) $(CFLAGS) -o main main.o

main.o: main.cpp
    $(CXX) $(CFLAGS) -c main.cpp

.PHONY: clean
clean:
    rm -f main main.o
```

## Demo

{% highlight cpp %}
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include "plstream.h"
using namespace std;

const int NSIZE = 100;
plstream *pls;

int main(int argc, const char **argv) {

    // PLFLT is a kind of float type

    PLFLT x[NSIZE], y[NSIZE];
    PLFLT xmin = 0., xmax = 1., ymin = 0., ymax = 100.;
    int   i;

    // Prepare data to be plotted.
    for ( i = 0; i < NSIZE; i++ )
    {
        x[i] = (PLFLT) ( i ) / (PLFLT) ( NSIZE - 1 );
        y[i] = ymax * x[i] * x[i];
    }

    pls = new plstream();

    // this command turns off color (switches to black-and-white):
    // pls->scolor(0);

    // this command below sets the background to rgb white
    pls->scolbg(255, 255, 255);

    // Parse and process command line arguments
    pls->parseopts( &argc, argv, PL_PARSE_FULL );

    // set the "device"; must happen before pls->init()
    // if this is left out, your program will start by asking you the 'dev' device

    // interesting options: xwin (show onscreen), pngcairo (save to png)
    // if you use pngcairo, your program will ask for a filename, or you can
    // ...give this line of code: pls->sfnam("filename.png");
    pls->sdev("pngcairo");
    pls->sfnam("test.png");


    // Initialize plplot
    pls->init();

    // change foreground color to blue; foreground is color 0 (col0), and blue is index 9;
    // see: http://plplot.sourceforge.net/docbook-manual/plplot-html-5.10.0/plcol0.html
    // must come after pls->init();
    pls->col0(9);

    // Create a labelled box to hold the plot.
    pls->env( xmin, xmax, ymin, ymax, 0, 0 );

    // Plot the data that was prepared above.
    pls->line( NSIZE, x, y );

    // Add plot labels (x axis, y axis, title); the "y=100 x#u2#d" is a complicated way to write y=100 x^2
    pls->lab( "x", "y=100 x#u2#d", "Simple PLplot demo of a 2D line plot" );

    delete pls;

    return 0;
}
{% endhighlight %}

The line `delete pls` actually calls `pls->end()` (or something like that) finally produces the plot and saves to the file.

If these two lines are missing in the code:

{% highlight cpp %}
pls->sdev("pngcairo");
pls->sfnam("test.png");
{% endhighlight %}

...then your program will start up asking you for the output device (screen, pdf, png, whatever). You can specify the output device on the command line:

```
./main -dev xwin
```

You can also see other command line options:

```
./main -h
```

This is all made possible by this line of code:

{% highlight cpp %}
pls->parseopts( &argc, argv, PL_PARSE_FULL );
{% endhighlight %}

## Helper functions

{% highlight cpp %}
void my_plot_line(
        string plotname, vector<float> xs, vector<float> ys,
        float xmin, float xmax, float ymin, float ymax,
        string xlab, string ylab, string title)
{
    // require same number of xs and ys
    assert(xs.size() == ys.size());

    // copy xs, ys into PLFLT arrays
    PLFLT *plxs = new PLFLT[xs.size()];
    PLFLT *plys = new PLFLT[ys.size()];
    for(int i = 0; i < xs.size(); i++)
    {
        plxs[i] = (PLFLT)xs[i];
        plys[i] = (PLFLT)ys[i];
    }

    plstream *pls = new plstream();
    pls->scolbg(255, 255, 255);
    pls->sdev("pngcairo");
    plotname = plotname + ".png";
    pls->sfnam(plotname.c_str());
    pls->init();
    pls->col0(9); // set foreground to blue
    pls->env((PLFLT)xmin, (PLFLT)xmax, (PLFLT)ymin, (PLFLT)ymax, 0, 0);
    pls->line(xs.size(), plxs, plys);
    pls->lab(xlab.c_str(), ylab.c_str(), title.c_str());
    delete pls;
}
{% endhighlight %}

Usage of the line function:

{% highlight cpp %}
float xsarr[] = {0.0, 1.0, 2.0, 3.0, 4.0};
float ysarr[] = {2.3, 7.1, 5.2, 9.2, 3.2};
vector<float> xs(xsarr, xsarr+5);
vector<float> ys(ysarr, ysarr+5);
my_plot_line("test2", xs, ys, -0.5, 5.0, 0.0, 10.0, "x lab", "y lab", "title");
{% endhighlight %}

And another for histograms:

{% highlight cpp %}
void my_plot_histogram(
        string plotname, vector<float> xs, int nbins, float xmin, float xmax,
        string xlab, string ylab, string title)
{
    // copy xs, ys into PLFLT arrays
    PLFLT *plxs = new PLFLT[xs.size()];
    for(int i = 0; i < xs.size(); i++)
    {
        plxs[i] = (PLFLT)xs[i];
    }

    plstream *pls = new plstream();
    pls->scolbg(255, 255, 255);
    pls->sdev("pngcairo");
    plotname = plotname + ".png";
    pls->sfnam(plotname.c_str());
    pls->init();
    pls->col0(9); // set foreground to blue
    //pls->env((PLFLT)xmin, (PLFLT)xmax, (PLFLT)ymin, (PLFLT)ymax, 0, 0);
    pls->hist(xs.size(), plxs, (PLFLT)xmin, (PLFLT)xmax, nbins, 0); // 0 means "default options", like axis bounds
    pls->lab(xlab.c_str(), ylab.c_str(), title.c_str());
    delete pls;
}
{% endhighlight %}

Usage of the histogram function:

{% highlight cpp %}
float delta = 2.0 * M_PI / 100.0;
vector<float> vals(100);
for(int i = 0; i < 100; i++)
{
    vals[i] = sin(i*delta);
}
my_plot_histogram("test3", vals, 5, -1.1, 1.1, "xlab", "y lab", "title");
{% endhighlight %}
