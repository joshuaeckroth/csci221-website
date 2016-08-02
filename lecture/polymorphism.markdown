---
title: Polymorphism
layout: default
---

# Polymorphism

These notes will review object-oriented programming and inheritance with C++, then discuss polymorphism.

## A simple set of classes

Let's build a Shape class, and descendents Rectangle, Ellipse, and Triangle. The diagram below is a [UML](/lecture/uml.html) diagram, which we'll learn more about later.

![Shape diagram](/images/shape-uml.png "Shape diagram")

First, we'll write the Shape class.

{% highlight cpp %}
class Shape
{
public:
    double x;
    double y;
};
{% endhighlight %}

We use the keyword `public` for technical reasons (alternatives are `private` and `protected`). Eventually we'll learn why we need that, but for now just consider it to be a necessary addition in order for the inheritance to work properly.

Next, the `Rectangle` class. On the first line, we'll write `Rectangle : public Shape` to indicate that `Rectangle` inherits properties and methods from `Shape` (`public` again, to make the inheritance work). We'll also write a function header for the `area` method.

{% highlight cpp %}
class Rectangle : public Shape
{
public:
    double width;
    double height;

    double area();
};
{% endhighlight %}

The other classes are similarly written:

{% highlight cpp %}
class Ellipse : public Shape
{
public:
    double major_axis;
    double minor_axis;

    double area();
};

class Triangle : public Shape
{
public:
    double side1;
    double side2;
    double angle_between;

    double area();
};
{% endhighlight %}

Let's write the code for the `area` functions.

{% highlight cpp %}
double Rectangle::area()
{
    return width * height;
}

double Ellipse::area()
{
    return 3.1415926 * major_axis * minor_axis;
}

double Triangle::area()
{
    return 0.5 * side1 * side2 * sin(angle_between);
}
{% endhighlight %}

Here is a simple `main` function to test the Triangle class:

{% highlight cpp %}
int main()
{
    Triangle t;
    t.x = 5;
    t.y = 4;
    t.side1 = 3;
    t.side2 = 4;
    t.angle_between = 3.1415926/2.0;

    cout << t.area() << endl;
    cout << t.x << "," << t.y << endl;
}
{% endhighlight %}

We see on the screen:

<pre>
6
5,4
</pre>

## Polymorphism

A `Shape` is a kind of "abstract" category that cannot be
used to perform any real task. For example, you cannot draw a "shape,"
or find its area. When we defined the `Shape` class, we did not provide any of
these methods (e.g. `draw()`, `area()`, etc.). However, subclasses
like `Rectangle` and `Ellipse` did have some useful methods (e.g.
`area()`). That's because, obviously, one can actually draw a
rectangle or calculate its area.

We already know that using object-orientation, and inheritance in
particular, are good ideas for shapes; that's because rectangles,
ellipses, and so on share many common properties and methods, such as
the properties `x` and `y` (location in a 2D space), and perhaps some
methods like `translate()`, `rotate()`, and so on. However, we were
unable to put the `area()` method in the `Shape` class, even though all
subclasses will have their own `area()` methods, because there is no
concept of the "area" of a "generic shape." So instead we just defined
the `area()` method for each subclass.

Now, there is a significant problem with this state of affairs we have
constructed. We're not getting the full power of object-orientation
and inheritance. We know that every shape has an area, so any
object that is a `Shape`, by way of inheritance, should have an
`area()` method. Recall that if we create a `Rectangle` object, say
`Rectangle r(3, 5);` then we are simultaneously creating a `Shape`
object as well; because `Rectangle` is a subclass of `Shape`, any
`Rectangle` object is also a `Shape` object. That means you can change
a `Rectangle` object into a `Shape` object:

{% highlight cpp %}
// this is valid since Rectangle inherits from Shape
Shape s = Rectangle(3, 5);

// or using pointers instead:
Shape *s = new Rectangle(3, 5);
{% endhighlight %}

However, even though `s` *really is a `Rectangle`*, now that we are
treating it as a `Shape` we cannot ask for its area, because the `Shape`
class does not have an `area()` method.

However, we often find it convenient, or even necessary, to gather up
several objects of several distinct types (different classes) which
all happen to inherit from the same parent class. In our shapes
example, we might want to gather up several objects of several kinds
of shapes, and put them into an array or linked list:

{% highlight cpp %}
// make a few shapes
Triangle t(3, 4, 3.141/2.0);
Rectangle r(8, 12);
Ellipse e(3.4, 3.4);

// using objects

Shape *myshapes = new Shape[3];
myshapes[0] = t;
myshapes[1] = r;
myshapes[2] = e;

// using pointers to objects

Shape **myshapes2 = new Shape*[3];
myshapes2[0] = &t;
myshapes2[1] = &r;
myshapes2[2] = &e;
{% endhighlight %}

However, now that they are all considered *just* shapes and not rectangles, ellipses, and so on, the objects (or pointers) in the array can only be treated as objects of type `Shape`. So, in particular, we can't ask any object in the array to calculate its area.

This is the problem that polymorphism solves. Polymorphism means that an object of some class, say `r` of the class `Rectangle`, can "look like" a `Shape` object but *act* like a `Rectangle` object when its asked to do things that may be done differently by a `Rectangle`.

Consider a different example: human infants are humans, and humans
walk on two feet. Perhaps you have defined a class named `Human` and a
class named `HumanInfant` (which is a subclass of `Human`). The
`Human` class may have a method `move()` that visually animates a
human walking on two feet. The `HumanInfant` will also have a method
called `move()` but what you'll see is a baby crawling. So of course
the code for the two `move()` methods will be different. Now consider
that you have a collection of `Human` objects, say an array called
`characters_in_the_game`, and you want to tell each character to move
in some random direction. You want the correct `move()` method to work
on each character. In this example, you will have `Human` objects and
`HumanInfant` objects, but they will all "look like" `Human` objects
when the are put into the array (because arrays can only hold one
type of thing, and you don't want to change `Human` objects into
`HumanInfant` objects; rather, the other way around is more
appropriate, because the class hierarchy says `HumanInfants` are
`Humans`, not vice versa). Even though the baby characters will appear
to be regular adult characters (because every object in the array 
will be of the type `Human`-pointer, i.e. `Human*`), when the `move()`
method is called for each object in the array, the `HumanInfant`'s
`move()` method is called if the object is *actually* of that type,
and not of the type `Human`. This is polymorphism (an object looking
like another, as far as types are concerned, but behaving in its
specific way).

To achieve this effect with our `Shape` class, we indicate that the
`area()` method is `virtual`. By `virtual` we mean polymorphic (but
the C++ creator thought `virtual` was a better word, apparently). Here
is the modified class:

{% highlight cpp %}
class Shape
{
public:
    double x;
    double y;

    // this method is virtual so that subclasses can redefine it
    virtual double area()
    {
        // if this method is used with a true generic shape object,
        // just return 0.0
        return 0.0;
    }
};
{% endhighlight %}

The subclasses need not change at all.

Finally, this `Shape` class should not really have an `area()` method
at all, since we don't ever want to create true generic `Shape`
objects. Rather, we will only be creating `Rectangle`, `Ellipse`,
etc. objects. So we delete the code for the `area()` method in the
`Shape` class and just write `= 0;` instead to indicate that
subclasses will have this `area()` method but the parent `Shape` class will
not. By doing this, we are turning `area()` into a "pure virtual"
method, and thus changing the `Shape` class into an "abstract class."
The reason for this extra terminology is that we will no longer be
able to create `Shape` objects (e.g.  `Shape s;` which we never
attempted to do anyway) because the `Shape` class has a method with no
definition (a purely virtual method). This makes the `Shape` class a
kind of "contract" which says "any subclasses must provide code for
their own `area()` method because I am introducing such a method but
not providing any code for it."

{% highlight cpp %}
class Shape
{
public:
    double x;
    double y;

    // this method is purely virtual; subclasses *must* define it
    virtual double area() = 0;
};
{% endhighlight %}

Now that `Shape` is an abstract class, we can't turn `Rectangle` or
whatever into `Shape`; we can only use the `Shape` class as a pointer
to a true `Rectangle`, `Ellipse`, etc.

{% highlight cpp %}
// not possible; ERROR!
Shape s = Rectangle(3, 4);

// this is ok
Shape *s = new Rectangle(3, 4);
{% endhighlight %}

And we can ask for the rectangle's area even though it "looks like" a
`Shape`:

{% highlight cpp %}
// polymorphism is used here
Shape *s = new Rectangle(3, 4);
cout << s->area() << endl;
{% endhighlight %}

Here is another, completely different example.

{% highlight cpp %}
// stolen from http://en.wikipedia.org/wiki/Virtual_function

#include <iostream>
using namespace std;
 
class Animal
{
public:
    virtual void eat()
    { 
        cout << "I eat like a generic Animal." << endl; 
    }
};
 
class Wolf : public Animal
{
public:
    void eat()
    { 
        cout << "I eat like a wolf!" << endl; 
    }
};
 
class Fish : public Animal
{
public:
    void eat()
    {  
        cout << "I eat like a fish!" << endl; 
    }
};
 
class GoldFish : public Fish
{
public:
    void eat()
    { 
        cout << "I eat like a goldfish!" << endl; 
    }
};
 
class OtherAnimal : public Animal
{
    // does nothing special
};
 
int main()
{
    Animal **animals = new Animal*[5];
    animals[0] = new Animal();
    animals[1] = new Wolf();
    animals[2] = new Fish();
    animals[3] = new GoldFish();
    animals[4] = new OtherAnimal();
 
    for(int i = 0; i < 5; i++)
    {
        animals[i]->eat();
    }
 
    return 0;
}
{% endhighlight %}

Output:

<pre>
I eat like a generic Animal.
I eat like a wolf!
I eat like a fish!
I eat like a goldfish!
I eat like a generic Animal.
</pre>

If we did not use `Animal` pointers, but instead put instances of each
class into the array (rather than pointers), like so:

{% highlight cpp %}
Animal *animals = new Animal[5];
animals[0] = Animal();
animals[1] = Wolf();
animals[2] = Fish();
animals[3] = GoldFish();
animals[4] = OtherAnimal();

for(int i = 0; i < 5; i++)
{
    animals[i].eat();
}
{% endhighlight %}

...then polymorphism would not take effect. This would be the output:

<pre>
I eat like a generic Animal.
I eat like a generic Animal.
I eat like a generic Animal.
I eat like a generic Animal.
I eat like a generic Animal.
</pre>

## Comparison with Java

- In Java, all methods in all classes are polymorphic. This means that any descendent class can override a method in an ancestor class, and should an object be created of this descendent class, its specialized method will always be used.
- Java interfaces are equivalent to C++ abstract classes where all methods are polymorphic and "pure virtual" (`= 0`), and the class has no data members.
- Java abstract classes and abstract methods are like pure virtual methods in C++. We call a C++ class abstract if it has (or inherits) at least one pure virtual method. In Java and C++, you cannot create an instance of an abstract class.

Also see the notes [Java vs. C++](/lecture/java-vs-cpp.html), specifically the section "Type casting and polymorphism."

