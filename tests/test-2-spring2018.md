---
layout: default
title: Test 2
categories: [tests]
due: "Mon Apr 16, 11:59pm"
---

# Test 2

Create a bitbucket repo called `csci221-test2`. **Do not work with anyone else on this test. Evidence of cheating will result in a zero.**

## Honor Statement

Create a `README` file that states you worked alone on this test and did not receive help from others. Type your full name in the file as your signature. **Without this statement and signature, I will not grade your submission.**

## Task

Create a simple "triplestore" ([Wikipedia](https://en.wikipedia.org/wiki/Triplestore)). A triplestore holds triples, e.g., "bob knows jane". A triple always has a subject, predicate, and object, in that order. Create the TripleStore class plus a Makefile. The main file is provided below, as well as the Triple class.

Your triplestore should have a query function that receives a string like "bob knows ?", where "?" means we want a list of all the people bob knows. The "?" may appear anywhere in the query, e.g., "? loves ?". See the main file for examples.

As usual, valgrind should return no errors (no memory leaks or bad memory accesses). Do not modify any files provided below.

## triple.h

Note that the copy constructor is private, hence it is disabled. So code like `Triple t = t2;` won't work, and you will not be able to make a datastructure like `set<Triple> triples` since adding to the set with `triples.insert(t)` would create a copy of `t`. You must use pointers to Triple objects in the triplestore (this saves memory space), e.g., `set<const Triple*>`. (The `const` part means the Triple object cannot be modified by the pointer, which is good because Triples should not change once created. Notice Triples have no `setSubject()` etc. methods.)

```
#ifndef TRIPLE_H
#define TRIPLE_H

#include <string>

class Triple {
    private:
        std::string subject;
        std::string predicate;
        std::string object;
        // make copy-constructor private to disallow its use
        Triple(const Triple&);
    public:
        Triple(std::string, std::string, std::string);
        std::string getSubject() const;
        std::string getPredicate() const;
        std::string getObject() const;
        std::string toString() const;
};

#endif
```

## triple.cpp

```
#include "triple.h"
using namespace std;

Triple::Triple(string _subject, string _predicate, string _object)
    : subject(_subject), predicate(_predicate), object(_object) {}

string Triple::getSubject() const { return subject; }
string Triple::getPredicate() const { return predicate; }
string Triple::getObject() const { return object; }
string Triple::toString() const { return subject + " " + predicate + " " + object; }
```

## main.cpp

```
#include <iostream>
#include <set>
using namespace std;

#include "triple.h"
#include "triplestore.h"

void query(TripleStore &store, string q) {
    set<const Triple*> result = store.query(q);
    cout << "Query \"" << q << "\", result:" << endl;
    for(set<const Triple*>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << (*it)->toString() << endl;
    }
    cout << endl;
}

int main() {
    TripleStore store;

    store.add("bob", "knows", "jane");
    store.add("bob", "loves", "jane");
    store.add("frank", "knows", "jane");
    store.add("bob", "works_at", "lowes");
    store.add("jane", "works_at", "homedepot");
    store.add("lowes", "isa", "store");
    store.add("homedepot", "isa", "store");
    store.add("homedepot", "isa", "store"); // isn't added twice

    cout << "Size: " << store.size() << endl;

    query(store, "bob ? jane");
    query(store, "? ? jane");
    query(store, "? works_at ?");
    query(store, "lowes isa ?");
    query(store, "? ? ?");

    store.del("bob", "loves", "jane");
    store.del("foo", "bar", "baz"); // does nothing

    cout << "Size: " << store.size() << endl;

    query(store, "bob ? jane");

    return 0;
}
```

## Expected output

```
$ valgrind ./main
==53180== Memcheck, a memory error detector
==53180== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==53180== Using Valgrind-3.9.0 and LibVEX; rerun with -h for copyright info
==53180== Command: ./main
==53180==
Size: 8
Query "bob ? jane", result:
bob knows jane
bob loves jane

Query "? ? jane", result:
bob knows jane
bob loves jane
frank knows jane

Query "? works_at ?", result:
bob works_at lowes
jane works_at homedepot

Query "lowes isa ?", result:
lowes isa store

Query "? ? ?", result:
bob knows jane
bob loves jane
frank knows jane
bob works_at lowes
jane works_at homedepot
lowes isa store
homedepot isa store
homedepot isa store

Size: 7
Query "bob ? jane", result:
bob knows jane

==53180==
==53180== HEAP SUMMARY:
==53180==     in use at exit: 0 bytes in 0 blocks
==53180==   total heap usage: 178 allocs, 178 frees, 6,243 bytes allocated
==53180==
==53180== All heap blocks were freed -- no leaks are possible
==53180==
==53180== For counts of detected and suppressed errors, rerun with: -v
==53180== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 6 from 6)
```


