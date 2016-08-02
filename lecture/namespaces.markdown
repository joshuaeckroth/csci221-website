---
layout: default
title: Namespaces
---

# Namespaces

Namespaces are like packages in Java. They set a prefix for all variables/functions/classes defined inside.

## Syntax

{% highlight cpp %}
namespace foo {
    int x;
    void bar();
    class Baz {
      public:
          void quux();
    };
}

int main()
{
    foo::x = 4;
    cout << foo::x << endl;
    foo::Baz *obj = new foo::Baz;

    int y = 12; // not foo's y

    using namespace foo;
    x = 7;
    cout << x << endl;
}
{% endhighlight %}

## The "using" command

There are two kinds of `using`:

- Using namespaces: `using namespace foo;`
- Using particular variables/functions/classes: `using foo::x;`

## Unnamed namespaces

You can define a namespace with no name, but only code in the same file can refer to stuff inside the unnamed namespace.

{% highlight cpp %}
namespace {
    int x;
}

// only this file can refer to that x
{% endhighlight %}

Technically, the compiler generates a random unique name for the unnamed namespace, and includes a `using` statement with that name in the same file. So, an unnamed namespace is equivalent to:

{% highlight cpp %}
namespace x3hsy5806shsl45 {
    int x;
}

using namespace x3hsy5806shsl45;
{% endhighlight %}

No other file can refer to this namespace because you (as the programmer) don't know what that random unique id is going to be.

