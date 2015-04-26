---
layout: default
title: Final exam study guide
---


## Trees

Define a small class of public data, but no methods, and a small
`main()` function that creates a binary tree representing the
mathematical expression `5+2*4`.

Write a function that finds the maximum value in a binary tree
containing `float`'s (no "operators", just left-subtree,
right-subtree, and a `float` value).

Write a function that prints all leaf nodes (nodes with no children)
of a binary tree with `float` values.

Write a class declaration containing public data, but no methods, for
a tree that has an aribtrary number of children and a `float` value.

Given some diagram of a tree, write the values in post/pre/in-order
format.

Write a class declaration with private data and one method (described
momentarily) for a binary tree with `float` values. This single method
should be called `find_root()` and returns a tree pointer to the root of
the tree. This method should work on any subtree of the larger tree,
and return the root of the larger tree. Note, you'll need more than
left-subtree, right-subtree for this class declaration. What other
private data do you need, and what are their default values as set in
a constructor? Also write the code for the `find_root()` method.

{% comment %}
## Input/output

Write a few lines of code that open a text file `input.txt` for reading, and print each line of text in the file. Be sure to check if the file was successfully opened, and be sure to close the file.

Write a few lines of code that open a text file `output.txt` for writing (not appending), and print 10 lines of text (or whatever) into the file. Be sure to check if the file was successfully opened, and be sure to close the file.
{% endcomment %}

## Inheritance

Given,

{% highlight cpp %}
class Foo
{
  private:
    int x;
    void abc();
  protected:
    double y;
    void def();
  public:
    char z;
    void ghi();
};
{% endhighlight %}

Which members/methods from `Foo` would be private/protected/public in `Bar` if we have `class Bar : public Foo`?

Which members/methods from `Foo` would be private/protected/public in `Bar` if we have `class Bar : protected Foo`?

Which members/methods from `Foo` would be private/protected/public in `Bar` if we have `class Bar : private Foo`?

What must be written in place of `...` to (publicly) inherit from both `Foo` and `Baz` in this line of code: `class Bar : ...`?

## Polymorphism

Describe how to achieve the equivalent of a Java interface in C++.

Describe how to achieve the equivalent of a Java abstract class in C++.

What makes a C++ class "abstract"?

Suppose you have two classes, `Super` and `Sub`, and `Super` has a method `foo` that `Sub` needs to override. Describe how you would do this in Java. Then write a minimum amount of C++ code to do the same thing.

Suppose you have code `Super *p = new Super; p->foo();`. Write code, including class definitions for `Super` and `Sub` (where `Sub` inherits from `Super`), that causes `p->foo()` to execute `Super`'s definition of `foo`. Only use polymorphism if necessary.

Suppose you have code `Sub *p = new Sub; p->foo();`. Write code, including class definitions for `Super` and `Sub` (where `Sub` inherits from `Super`), that causes `p->foo()` to execute `Sub`'s definition of `foo`. Only use polymorphism if necessary.

Suppose you have code `Super *p = new Sub; p->foo();`. Write code, including class definitions for `Super` and `Sub` (where `Sub` inherits from `Super`), that causes `p->foo()` to execute `Sub`'s definition of `foo`. Only use polymorphism if necessary.

Suppose you have code `Super *p = new Super; p->foo();`. Write code, including class definitions for `Super` and `Sub` (where `Sub` inherits from `Super`), that causes the compiler to reject this code due to `Super` being an abstract class. Then fix the given code so it calls `Sub`'s version of `foo`. Only use polymorphism if necessary.

## Templates

Explain why code with templates cannot be separately compiled into a `.o` file (i.e., all such code must live in `.h` files).

Write a template function that finds and returns the maximum value of some numeric array. Also show how you would use it (e.g., from `main()`).

Write a template class header and implementation (separately, but in the same `.h` file) that has two private members: `x` and `y` of some numeric type, and has two public functions: `add` and `sub` which return `x+y` and `x-y`, respectively. Finally, show how you would use such a class and both functions (e.g., from `main()`).

## Vectors

What data structure is used by the C++ STL `vector` class?

Which is (generally) faster on vectors: `insert_front` or `push_back`? Why?

Create a vector that holds 1000 integers, and fill it with values (any values).

Create a vector that holds 1000 floats, and fill it with values (any values).

Create a vector that holds 1000 vectors with five integers each, and fill it with values (any values).

Create a 3D vector: a vector of vectors of vectors of floats. Put some values in it.

Print a vector's values (in order) using array syntax.

Print a vector's values (in order) using an iterator.

Print a vector's values, in sorted order (so sort the vector first).

Print a vector's values in reverse sorted order.

Print a vector's values in shuffled order.

Write the condition for an `if()` that is true when some vector `vals` is empty.

Write the condition for an `if()` that is true when some vector `vals` contains the integer 52.

Write a function that receives an integer `n` and integer `x` and returns a newly generated vector of `n` integers, all equal to `x`.

## Maps

Create a map with integer keys and float values. Add three key-value pairs to it, using array syntax.

Create a map with integer keys and float values. Add three key-value pairs to it, not using array syntax.

Create a map with integer keys and vector-of-strings values. Add three key-value pairs to it.

Given a map `m` with string keys and integer values, print all the keys (in whatever order).

Given a map `m` with string keys and integer values, print all the values (in whatever order).

Given a map `m` with string keys and integer values, print all key-value pairs (with whatever formatting, in whatever order).

Write the condition for an `if()` that is true when a map `m` (with string keys and integer values) contains the key `"foo"`.

## UML

Given the following UML class diagram, write a basic template for the represented classes. Include the necessary member variables such as pointers, collections, etc.

![Person/house UML](/images/final-exam-review-person-house.png)

Write a reasonable UML class diagram for a file transfer program that can support FTP and SFTP. Keep it simple; don't include every member of every class. Use polymorphism in the right places.

{% comment %}
## Development methodologies

Give two differences between "waterfall" and "agile" development methodologies.

What are two benefits and drawbacks to "agile" processes?
{% endcomment %}

