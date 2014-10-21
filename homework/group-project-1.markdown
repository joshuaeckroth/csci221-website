---
title: Group project 1
layout: default
---

Create a text-based "adventure game." Work in a team of two. Use git to share code. Document your object-oriented design with <a href="/lecture/uml.html">UML</a>.

Skills needed to complete this assignment:

- [Constructors and inheritance](/lecture/constructors-and-inheritance.html)
- [Polymorphism](/lecture/polymorphism.html)
- [Vectors](/lecture/vectors.html) and/or [maps, sets, etc.](/lecture/maps-sets-etc.html)
- [UML](/lecture/uml.html)

Create a "Team" on Bitbucket and add me and your partner as members. Call your team and your repository whatever you want.

## Requirements

- Make a game like the text adventure games of the 70's and 80's. See the example below.
- Document your object-oriented design with a single UML diagram.
- Separate your teamwork so that each person is responsible for different classes (mostly). E.g., person A works on the Room class and descriptions, and person B works on the Agent/Monster/Player classes (described below).
- I need to see in the git repository that both partners contributed. Both people need to submit code.

## Example

Here is an example of simple movements:

<pre>
You are in the Garden. The trees and shrubs appear to be resilient to
decades of neglect but the flowerbeds all withered away long ago.

There is an exit to North (Kitchen) and East (Library).

Which exit? (or 'quit'): <u>north</u>

You move to the North...

You are in the Kitchen. Knives, pots, pans, and other kitchenware
dangle over the island like some kind of metallic chandelier.

There is an exit to North (Hallway), East (Library), and South
(Garden).

Which exit? (or 'quit'): <u>west</u>

There is nothing over there.

Which exit? (or 'quit'): <u>east</u>

You move to the East...
</pre>

Besides movement, you also must support non-player characters, a.k.a., monsters. When you enter a room and there are other monsters there, you should be told so:

<pre>
Tracy, it is your turn. You are in the Kitchen. Knives, pots, pans,
and other kitchenware dangle over the island like some kind of
metallic chandelier.

You see a monster named Napolean (once Emperor of the French), a
monster named Kafka (a thin, nervous looking creature), and Josh (your
husband).

There is an exit to North (Hallway), East (Library), and South
(Garden).

Tracy, which exit? (or 'quit'): <u>east</u>

You move to the East...
</pre>

## Required classes

### Room class

The `Room` class should have at least these methods:

* a constructor that sets the `name` and `description`
* `string getName()`
* `string getDescription()`
* `void link(Room *r, string direction)` -- establish a link between rooms
* `Room *getLinked(string direction)` -- get the room linked in some direction
* `void printLinked()` -- print all rooms linked to this room

You should support room links in North, South, East, and West
directions (at least). Use a map (key is the direction, a string;
value is the `Room` pointer).

You can establish the maze in the code (in the `main()` function
probably); the maze need not be designed by the user interactively
(that would be slightly harder).

### Agent, Monster, Player classes

Add an `Agent` class that, at least, has a pure virtual function `bool
act()` that must be implemented in subclasses. Make at least one
subclass for monsters (named `Monster`), and another subclass for
the player (named `Player`). Update your `main()` function
or make a `Game` class so that, during each "turn," the monsters move
and the player(s) move (in whatever order).  Moves are accomplished by
using the monsters' or player(s)' `act()` functions.  The monsters'
`act()` functions will choose a random room (or whatever you want to
do) and will move into that room. The player(s)' `act()` function will
ask the person at the keyboard to choose a room. The `act()` function
will always return `true` for monsters but may return `false` for
players if the player types "quit" or similar. Wherever you are using
these `act()` functions, you'll need to check for true/false and quit
the game if `act()` returns false. For example:

{% highlight cpp %}
Monster* monster1 = new Monster(...);
Player* player1 = new Player(...);
Player* player2 = new Player(...);
vector<Agent*> agents;
agents.push_back(monster1);
agents.push_back(player1);
agents.push_back(player2);

while(true)
{
    for(int i = 0; i < agents.size(); i++)
    {
        bool ok = agents[i]->act();
        if(!ok)
        {
            cout << "Game quits." << endl;
            return 0;
        }
    }
}
{% endhighlight %}

Here is what your `Agent` class header (`agent.h`) might contain (at
least):

{% highlight cpp %}
#ifndef AGENT_H
#define AGENT_H

#include "room.h"

class Agent
{
protected:
    Room *cur_room;
    string name;

public:
    virtual bool act() = 0;
    string getName() { return name; }
};

#endif
{% endhighlight %}

Here is what your monster (`Monster`) class header (`monster.h`) might contain
(at least):

{% highlight cpp %}
#ifndef MONSTER_H 
#define MONSTER_H

#include <string>
#include "agent.h"
#include "room.h"
using namespace std;

class Monster: public Agent
{
public:
    Monster(string _name, Room *starting_room);
    bool act();
};

#endif
{% endhighlight %}

Here is a quick glance at how you might program a "random" monster
that chooses a random direction to move on each turn:

{% highlight cpp %}
int n = rand() % 4;
string direction;
switch(n)
{
    case 0: direction = "north"; break;
    case 1: direction = "south"; break;
    case 2: direction = "west"; break;
    case 3: direction = "east"; break;
}
if(cur_room->getLinked(direction) != NULL)
{
    cur_room = cur_room->getLinked(direction);
}
{% endhighlight %}

If you use `rand()` anywhere in your code, be sure to include this at
the beginning of `main()`:

{% highlight cpp %}
// ensure different random numbers each time the program is run
srand(time(NULL));
{% endhighlight %}

### Handling agents in rooms

Your `Room` class must be able to tell the player who is in
the room. That is, the `Room` class should have a set or some other
collection that holds `Agent` pointers; when an agent enters the room,
the agent's pointer is added to the collection; when an agent leaves
the room, the agent's pointer is removed from the collection. The idea
is, if the player does not know who is in the same room as the player,
then how will you, as the programmer, know if your monsters are
appropriately moving to different rooms?

You might accomplish this in the following way: add a set to the
`Room` class (i.e. add `#include <set>` in `room.h` and add a private
variable `set<Agent*> occupants` to the `Room` class). This set
contains `Agent` pointers. This way, you can store monsters and
players in the set since both can be treated as `Agent` pointers. Then
provide methods in the `Room` class called `enter`, `leave`, and
`printOccupants` that, respectively, add an `Agent` to the room,
remove an `Agent` from the room, and print all the agents in the room.

Here is what those functions might look like:

{% highlight cpp %}
void Room::enter(Agent *a)
{
    occupants.insert(a);
}

void Room::leave(Agent *a)
{
    occupants.erase(a);
}

void Room::printOccupants()
{
    cout << "Occupants in this room:" << endl;

    set<Agent*>::iterator it;
    for(it = occupants.begin(); it != occupants.end(); ++it)
    {
        // use the Agent's getName() function
        cout << (*it)->getName() << endl;
    }
}
{% endhighlight %}

To use these `enter` and `leave` functions, when an agent (monster or
player) is changing rooms, before changing rooms, "leave" the current
room (i.e.  `cur_room->leave(this)` -- recall that `this` is a pointer
variable that always exists in class methods, and points to the
monster or player who is changing rooms), then change rooms, then
enter the new room (i.e.  `cur_room->enter(this)` after `cur_room` has
been changed).

Note that there will be a small problem with the modified `Room`
class. Your new `Room` class will need a set of agents, like so:

{% highlight cpp %}
class Room
{
private:
    set<Agent*> occupants;

    // ...
};
{% endhighlight %}

You might expect to add `#include "agent.h"` to the top of
`room.h`. However, this is not going to work, because `agent.h`
already has `#include "room.h"`. The two `.h` files can't both
"include" each other -- cyclical includes are not allowed.

So the solution to this is to keep `#include "room.h"` inside
`agent.h` but don't put `#include "agent.h"` inside `room.h`. Of
course, without that "include," the `Room` class won't know what an
`Agent` is. We solve this by adding a *forward declaration* of the
`Agent` class, like so:

{% highlight cpp %}
class Agent;  // forward declaration

class Room
{
private:
    set<Agent*> occupants;

    // ...
};
{% endhighlight %}

What this says is "I promise there will be a class called `Agent`,
eventually, but not yet." As long as we stick with pointers to
`Agent`, this will work.

In the `room.cpp` and `agent.cpp` files, you can "include" whatever
you want (so `#include "agent.h"` and `#include "room.h"` in the
respective `.cpp` files); there is no cyclical dependency in this case
because `.cpp` files don't "include" each other, and are compiled
separately.

Note that you could have alternatively used a forward declaration of
`Room` instead of `Agent`; it would work either way.

## Historical fun

This may be interesting if you have some free time: [You find yourself in a room](http://www.kongregate.com/games/2DArray/you-find-yourself-in-a-room)

You can also play the first text adventure game (updated to be played in a browser):
[Colossal Cave Adventure](http://www.ifiction.org/games/playz.php?cat=&game=1&mode=html)

