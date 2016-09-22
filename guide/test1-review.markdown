---
layout: default
title: Test 1 Review
categories: [studyguides]
date: Wed Oct 5
---

# Test 1 Review

## Makefiles

Given this Makefile:

<pre>
file2: file1
    cmd1

file3: file2 file1
    cmd2

file4: file3
    cmd3

file5: file2 file3
    cmd4
</pre>

What commands will be executed when `make file5` is run, if the
relevant files have these timestamps:

<pre>
[jeckroth@londo makefiles]$ ls -l
total 4
-rw-rw-r--. 1 jeckroth jeckroth 0   Sep 25 12:28 file1
-rw-rw-r--. 1 jeckroth jeckroth 0   Sep 25 12:30 file2
-rw-rw-r--. 1 jeckroth jeckroth 0   Sep 25 12:27 file3
-rw-rw-r--. 1 jeckroth jeckroth 0   Sep 25 12:15 file4
-rw-rw-r--. 1 jeckroth jeckroth 0   Sep 25 12:21 file5
-rw-rw-r--. 1 jeckroth jeckroth 112 Sep 25 12:36 Makefile
</pre>

## Pointers

Create a cycle of (at least three) pointers, so that you can
dereference infinitely-many times and still have a valid pointer.

Answer in a sentence or two: why can't you use "pointer arithmetic"
(i.e., `*(px + 1)`) on `void*` pointers?

Write a recursive factorial function that has two arguments: an
integer, and a function pointer to itself, and calls itself
recursively with that function pointer.

Describe how you would diagnose a segmentation fault
that you suspect is caused by dereferencing an invalid pointer.

## Memory management

Show how to reserve memory for an array, and then properly clean up
that memory.

Create a small scenario that results in an indirect leak. An indirect
leak is one where the memory is still being pointed to, by a valid
pointer, but the pointer to that pointer is lost. There might be more
pointers in the chain.

## Arrays

Given the code below, what kind of object (describe in English) is
the variable `xs`? (Note, "an array" is not the right answer.)

{% highlight cpp %}
int xs[] = {4, 2, 5, 2, 7};
{% endhighlight cpp %}

Given `xs` above, write code that changes the `7` to an `8`, without
using `[` or `]`.

Create an array of arrays with the following counts: first array
has 1 element, second array has 2, etc., up to five.

Write a function header (just the top line of the function) that is
capable of summing all the `float` values in any 2D rectangular
array. Use pointer syntax, not `[]` syntax.

## Linked lists

Given this class:

{% highlight cpp %}
class Node {
public:
    double value;
    Node* pnext;
};

class List {
public:
    Node* first;
    int count;
};
{% endhighlight %}

Write the `void List::push_back(double val)` function, without memory
leaks, so that these asserts hold true:

{% highlight cpp %}
List *mylist = new List;
mylist->push_back(3.3);
assert(mylist->first->value == 3.3);
mylist->push_back(5.5);
assert(mylist->first->value == 3.3);
assert(mylist->first->pnext->value == 5.5);
mylist->push_back(7.7);
assert(mylist->first->value == 3.3);
assert(mylist->first->pnext->value == 5.5);
assert(mylist->first->pnext->pnext->value == 7.7);
{% endhighlight %}

Rewrite this function so that all memory leaks are fixed:

{% highlight cpp %}
// chops off the rest of the list starting at position 'index'
void List::truncate_at(int index)
{
    assert(index >= 0 && index < count);
    Node *n = first;
    for(int i = 0; i < index; i++)
    {
        n = n->pnext;
    }
    n->pnext = NULL;
}
{% endhighlight %}

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
