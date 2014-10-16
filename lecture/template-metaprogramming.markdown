---
title: Template meta-programming
layout: default
---

Template meta-programming can be a very interesting, complicated topic
(anything "meta" is very interesting, after all). We'll keep it very simple in
this class.

The idea behind template meta-programming is that we want to use a special
language *on top of C++* that generates C++ code. This "template meta-language"
is itself a full programming language, but we'll just use the simplest pieces.
Our use of template meta-programming will be limited to generating classes and
functions that work on any type of object.

**Important note:** Template classes and functions must have their full implementations in the header file, not an external `.cpp` file. This is because template classes and functions cannot be compiled in a generic way, so we cannot produce a `.o` file that is generic.

## Generic linked lists

Think back to our linked lists. Let's say we have a linked list class:

{% highlight cpp %}
class LinkedList
{
    private:
    struct node
    {
        double value;
        node *pnext;
    };

    node *head;

    public:
    LinkedList();
    void insert_front(double value);
    void push_back(double value);
    int length();
    void reverse();
    double nth(int n);
    void print();
};

// etc...
{% endhighlight %}

Assuming that `LinkedList` class was fully implemented, we would be able to do
things like this:

{% highlight cpp %}
int main()
{
    LinkedList mylist;
    mylist.push_back(4.3);
    mylist.insert_front(3.2);

    mylist.print();

    // etc...
}
{% endhighlight %}

But this is quite unfortunate! That linked list class *only* stores `double`
values. There are more things in heaven and earth than can be represented as
`double` values. (Well, not really, since representations don't matter,
theoretically. But in practice, they do.)

We want to create a single linked list class that can store any (single) type
of value. We will not have the option to create a linked list that can store
varying types of values (e.g. a linked list with strings, doubles, ints, and so
on all in the same list will not be possible). But, it would be nice to write
one linked list class that can store strings, or in another instance integers,
or whatever. Template meta-programming allows us to do this.

## Creating a templated class

All you have to change about the linked list class above in order to support
making a linked list with a (single) arbitrary type is the following:

{% highlight cpp %}
template <typename T> // T can be anything, e.g. foo
class LinkedList
{
    private:
    struct node
    {
        T value; // not double, T!
        node *pnext;
    };

    node *head;

    public:
    LinkedList();
    void insert_front(T value); // T!
    void push_back(T value); // T!
    int length();
    void reverse();
    T nth(int n); // T!
    void print();
};

template<typename T>
void LinkedList<T>::insert_front(T value)
{
    node *n = new node;
    n->value = value;
    n->pnext = head;
    head = n;
}

// etc...
{% endhighlight %}

Now, to use such a "generic linked list," when we create a `LinkedList` object
in the `main()` function we have to say what type we're using (`T` will become
whatever that type is).

{% highlight cpp %}
int main()
{
    LinkedList<double> mylist;
    mylist.push_back(4.3);
    mylist.insert_front(3.2);

    mylist.print();

    // etc...
}
{% endhighlight %}

Ok, that's still `double` values in our linked list. Let's put strings inside
instead:

{% highlight cpp %}
int main()
{
    LinkedList<string> mylist;
    mylist.push_back("hugo");
    mylist.insert_front("chavez");

    mylist.print();

    // etc...
}
{% endhighlight %}

The linked list that stores string values is the same class as above. We can
create two linked lists storing different types of values, if we wish:

{% highlight cpp %}
int main()
{
    LinkedList<string> words;
    LinkedList<int> frequencies;

    words.push_back("bean");
    frequencies.push_back(15);

    // etc...
}
{% endhighlight %}

That feeling of elation that you must have is the feeling of freeing yourself
from strong typing. You didn't really free yourself; the types are all still
there (`double`, `string`, etc.). But it's close enough (we don't need much to
be thrilled).

## Another example: Template specialization

This example is borrowed from [cplusplus.com](http://www.cplusplus.com/doc/tutorial/templates/). It shows how we can "specialize" a template class by writing another class with a specific type for the template type, and even add new methods that that specialized class.

{% highlight cpp %}
// template specialization
#include <iostream>
using namespace std;

// class template:
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};

int main () {
  mycontainer<int> myint (7);
  mycontainer<char> mychar ('j');
  cout << myint.increase() << endl;
  cout << mychar.uppercase() << endl;
  return 0;
}
{% endhighlight %}

Output:

<pre>
8
J
</pre>

## Function templates

You can use templates on functions, too, and not just classes. Example from [cppreference.com](http://en.cppreference.com/w/cpp/language/function_template)

{% highlight cpp %}
#include <iostream>
 
template<typename T>
void f(T s)
{
    std::cout << s << '\n';
}
 
int main()
{
    f<double>(1); // instantiates and calls f<double>(double)
    f<>('a'); // instantiates and calls f<char>(char)
    f(7); // instantiates and calls f<int>(int)
    void (*ptr)(std::string) = f; // instantiates f<string>(string)
}
{% endhighlight %}

## More information

- [cppreference.com - Class templates](http://en.cppreference.com/w/cpp/language/class_template)
- [cppreference.com - Function templates](http://en.cppreference.com/w/cpp/language/function_template)


<a href="http://imgs.xkcd.com/comics/hofstadter.png">
![Hofstadter](/images/xkcd-hofstadter.png "Hofstadter")
</a>

