---
title: Homework 3
layout: default
---

Implement John Conway's Game of Life.

Skills needed to complete this assignment:

- [Arrays](/lecture/arrays.html)

Name your BitBucket repository **exactly** `csci221-homework3`.

## Requirements

- Create one file, `life.cpp`, with three functions: `main`,
  `generation`, `display` (described below). This program should
  simulate Conway's Game of Life.

- Create a `Makefile` that builds your program.

Be sure to create a repository on BitBucket and add me (your
instructor) as a viewer. Tag your final submitted version with the tag
"v1.0" (without quotes). If you forget to tag a commit with "v1.0",
your work will be considered late.

## Game of Life

The mathematician
[John Horton Conway](http://en.wikipedia.org/wiki/John_Horton_Conway)
invented the "Game of Life" (not the board game). Though not a "game"
in any traditional sense, it provides interesting behavior that is
specified with only a few rules.

Life is an organism that lives in a discrete, two-dimensional
world. While this world is actually unlimited, we don't have that
luxury, so we restrict the world to a certain width and height (you
choose). It is your choice to make the edges "wrap around" or not.

For this assignment, the world should be represented by a 1D array
(width*height big). Review the
[array lecture notes](/lecture/arrays.html) for guidance about how to
treat a 1D array as a 2D array. The array should have `bool` values,
indicating a living or dead cell.

The world is updated all at once. Each cell is born, kept alive, kept
dead, or killed according to simple rules. These rules refer to the
eight neighbors of the cell, in the previous world. Be sure you have
two copies of the world: the old one (prior time step), and the one
that's being modified (current time step).

The neighbors of a cell are the cells directly above, below, to the
right, to the left, diagonally above to the right and left, and
diagonally below to the right and left. Be careful when checking for
neighbors on the edges; you can decide whether an edge cell has alive
or dead neighbors beyond the edge, or instead that the edges wrap
around.

The rules for birth/death are as follows:

- If an living cell has zero or one living neighbors, it dies of
  loneliness. If an living cell has more than three living neighbors,
  it dies of overcrowding.

- If a dead cell has exactly three living neighbor cells, the dead
  cell turns into a living cell (birth).

You will "hard code" a starting configuration. The user need not be
able to specify a different starting configuration, but you can build
this feature if you want.

## Code design

- Create at least these functions: `main`, `generation` (copies and
  modifies world for next generation, using the two rules), `display`
  (prints the world).

- Your `main` function essentially does the following:

  - Sets up the initial world.

  - Loops forever:

    - Calls `generation`

    - Calls `display`

    - Waits for a short time

Use this code to wait for a short time:

{% highlight cpp %}
#include <unistd.h>

// ...

usleep(800000); // pause 800 ms
{% endhighlight %}

## Configurations

Examples available from the article <a
href="http://www.ibiblio.org/lifepatterns/october1970.html">Scientific
American 223 (October 1970): p. 120-123</a>

These examples are stolen from <a
href="http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life">Wikipedia</a>.

<div style="font-size: 80%">
  <table border="0" cellpadding="6"
         style="margin-left:auto;margin-right:auto; border: 0;">
    <tr style="border-bottom: 0;">
      <td>
        <table class="wikitable">
          <tr>
            <th colspan="2">Still lifes</th>
          </tr>
          <tr>
            <td>Block</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_block_with_border.svg" class="image"><img alt="Game of life block with border.svg" src="//upload.wikimedia.org/wikipedia/commons/thumb/9/96/Game_of_life_block_with_border.svg/66px-Game_of_life_block_with_border.svg.png" width="66" height="66" /></a></td>
          </tr>
          <tr>
            <td>Beehive</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_beehive.svg" class="image"><img alt="Game of life beehive.svg" src="//upload.wikimedia.org/wikipedia/commons/thumb/6/67/Game_of_life_beehive.svg/98px-Game_of_life_beehive.svg.png" width="98" height="82" /></a></td>
          </tr>
          <tr>
            <td>Loaf</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_loaf.svg" class="image"><img alt="Game of life loaf.svg" src="//upload.wikimedia.org/wikipedia/commons/thumb/f/f4/Game_of_life_loaf.svg/98px-Game_of_life_loaf.svg.png" width="98" height="98" /></a></td>
          </tr>
          <tr>
            <td>Boat</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_boat.svg" class="image"><img alt="Game of life boat.svg" src="//upload.wikimedia.org/wikipedia/commons/thumb/7/7f/Game_of_life_boat.svg/82px-Game_of_life_boat.svg.png" width="82" height="82" /></a></td>
          </tr>
        </table>
      </td>
      <td rowspan="2">
        <table class="wikitable">
          <tr>
            <th colspan="2">Oscillators</th>
          </tr>
          <tr>
            <td>Blinker</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_blinker.gif" class="image"><img alt="Game of life blinker.gif" src="//upload.wikimedia.org/wikipedia/commons/9/95/Game_of_life_blinker.gif" width="82" height="82" /></a></td>
          </tr>
          <tr>
            <td>Toad</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_toad.gif" class="image"><img alt="Game of life toad.gif" src="//upload.wikimedia.org/wikipedia/commons/1/12/Game_of_life_toad.gif" width="98" height="98" /></a></td>
          </tr>
          <tr>
            <td>Beacon</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_beacon.gif" class="image"><img alt="Game of life beacon.gif" src="//upload.wikimedia.org/wikipedia/commons/1/1c/Game_of_life_beacon.gif" width="98" height="98" /></a></td>
          </tr>
          <tr>
            <td>Pulsar</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_pulsar.gif" class="image"><img alt="Game of life pulsar.gif" src="//upload.wikimedia.org/wikipedia/commons/0/07/Game_of_life_pulsar.gif" width="137" height="137" /></a></td>
          </tr>
        </table>
      </td>
    </tr>
    <tr style="border: 0px;"0>
      <td>
        <table class="wikitable">
          <tr>
            <th colspan="2">Spaceships</th>
          </tr>
          <tr>
            <td>Glider</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_animated_glider.gif" class="image"><img alt="Game of life animated glider.gif" src="//upload.wikimedia.org/wikipedia/commons/f/f2/Game_of_life_animated_glider.gif" width="84" height="84" /></a></td>
          </tr>
          <tr>
            <td>Lightweight spaceship</td>
            <td><a href="http://www.wikipedia.org/wiki/File:Game_of_life_animated_LWSS.gif" class="image"><img alt="Game of life animated LWSS.gif" src="//upload.wikimedia.org/wikipedia/commons/3/37/Game_of_life_animated_LWSS.gif" width="126" height="98" /></a></td>
          </tr>
        </table>
      </td>
      <td></td>
    </tr>
  </table>
</div>

These may prove interesting starting conditions (see Wikipedia for
more options).

<table align="center" style="text-align: center; border: 0;">
  <tr style="border-bottom: 0;">
    <td>
      <div class="thumb tright">
        <div class="thumbinner" style="width:84px;"><a href="http://www.wikipedia.org/wiki/File:Game_of_life_fpento.svg" class="image"><img alt="" src="//upload.wikimedia.org/wikipedia/commons/thumb/1/1c/Game_of_life_fpento.svg/82px-Game_of_life_fpento.svg.png" width="82" height="82" class="thumbimage" /></a>
          <div class="thumbcaption">F-pentomino</div>
        </div>
      </div>
    </td>
    <td>
      <div class="thumb tright">
        <div class="thumbinner" style="width:164px;"><a href="http://www.wikipedia.org/wiki/File:Game_of_life_diehard.svg" class="image"><img alt="" src="//upload.wikimedia.org/wikipedia/commons/thumb/9/99/Game_of_life_diehard.svg/162px-Game_of_life_diehard.svg.png" width="162" height="82" class="thumbimage" /></a>
          <div class="thumbcaption">Diehard</div>
        </div>
      </div>
    </td>
    <td>
      <div class="thumb tright">
        <div class="thumbinner" style="width:148px;"><a href="http://www.wikipedia.org/wiki/File:Game_of_life_acorn.svg" class="image"><img alt="" src="//upload.wikimedia.org/wikipedia/commons/thumb/b/b9/Game_of_life_acorn.svg/146px-Game_of_life_acorn.svg.png" width="146" height="82" class="thumbimage" /></a>
          <div class="thumbcaption">Acorn</div>
        </div>
      </div>
    </td>
  </tr>
</table>

## Extras

Go to
[http://www.qotile.net/blog/wp/?p=600](http://www.qotile.net/blog/wp/?p=600)
to see some cool 3D visualizations of the game over time. A ridiculous
amount of further information is available here:
[http://www.conwaylife.com/wiki/index.php?title=Main_Page](http://www.conwaylife.com/wiki/index.php?title=Main_Page)

Download <a href="http://golly.sourceforge.net/">Golly</a> (for
Windows, Mac, Linux) to play with cellular automata and some amazing
creations by researchers.

Cellular automata is serious research; see a
[list of journals](http://uncomp.uwe.ac.uk/genaro/Cellular_Automata_Repository/Journals.html)
that publish articles about cellular automata.
