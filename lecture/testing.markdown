---
layout: default
title: Testing
---

# Testing

These notes show how to use the Google Test library.

- [Download Google Test](https://code.google.com/p/googletest/downloads/detail?name=gtest-1.7.0.zip&can=2&q=)

## Tests and test cases

A "test case" is a group of "tests." Each test is specified like so:

{% highlight cpp %}
TEST(my_test_cases, my_test)
{
  // ... something something ASSERT_EQ(..., ...) or whatever
}
{% endhighlight %}

`TEST(my_test_cases, my_test)` creates an ordinary `void` C++ function. Put C++ code and Google Test assertions in here. The `my_test_cases` should name a group of tests ("test case"), and `my_test` should name the particular test you're defining. Whatever you write for `my_test_cases` and `my_test` must be valid C++ function names.

You can assert/expect various ways:

- `ASSERT_EQ(a, b);` -- crashes if fails
- `ASSERT_EQ(a, b) << "yeah yeah yeah";` -- print a message on failure, and crash
- `EXPECT_EQ(a, b);` -- don't crash on fail, just print failure message
- `EXPECT_EQ(a, b) << "yeah yeah yeah";` -- print a message on failure, but don't crash

More variations exist like `ASSERT_LE` (less-than-or-equal), `ASSERT_STRNE` to assert two strings are not equal, etc. See the [primer](https://code.google.com/p/googletest/wiki/V1_7_Primer) and [advanced guide](https://code.google.com/p/googletest/wiki/V1_7_AdvancedGuide).

## Example: Testing the linked list library

### Makefile

You'll need to compile Google Test in your `Makefile`, and include it in your final program. Here is an example `Makefile`, where the Google Test download was extracted in the parent folder. This `Makefile` generates a `testll` binary for the testing code and a `main` binary for the `main.cpp` code (which does not include test cases).

```
GTEST_DIR = ../gtest-1.7.0
CXX = g++
CXXFLAGS = -ansi -Wall -ggdb3 -isystem $(GTEST_DIR)/include -Wextra -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all: main testll

gtest-all.o: $(GTEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

testll.o: testll.cpp linkedlist.h node.h $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c testll.cpp

testll: testll.o gtest_main.a
	$(CXX) $(CXXFLAGS) -o testll testll.o gtest_main.a

main.o: main.cpp linkedlist.h node.h
	$(CXX) $(CXXFLAGS) -c main.cpp

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o

clean:
	rm -f *.o testll gtest.a gtest_main.a
```

### Tests

Here are some tests for the linked list code.

{% highlight cpp %}
#include <iostream>
#include "linkedlist.h"
#include "gtest/gtest.h"
using namespace std;

TEST(linkedlist, insertions)
{
    LinkedList<int> *list = new LinkedList<int>;
    ASSERT_EQ(list->length(), 0);
    list->push_back(17);
    ASSERT_EQ(list->length(), 1);
    list->push_back(52);
    ASSERT_EQ(list->length(), 2);
    list->insert_front(10);
    ASSERT_EQ(list->length(), 3);
    delete list;
}

TEST(linkedlist, iterate)
{
    LinkedList<int> *list = new LinkedList<int>;
    list->push_back(17);
    list->push_back(52);
    list->insert_front(10);
    list->reset();
    ASSERT_FALSE(list->end());
    ASSERT_EQ(list->get_val(), 10);
    list->next();
    ASSERT_FALSE(list->end());
    ASSERT_EQ(list->get_val(), 17);
    list->next();
    ASSERT_FALSE(list->end());
    ASSERT_EQ(list->get_val(), 52);
    list->next();
    ASSERT_TRUE(list->end());

    ASSERT_EQ(list->val_at(0), 10);
    ASSERT_EQ(list->val_at(1), 17);
    ASSERT_EQ(list->val_at(3), 52);
    delete list;
}

TEST(linkedlist, contains)
{
    LinkedList<int> *list = new LinkedList<int>;
    list->push_back(17);
    list->push_back(52);
    ASSERT_TRUE(list->contains(17));
    ASSERT_TRUE(list->contains(52));
    ASSERT_FALSE(list->contains(10));
    delete list;
}

TEST(linkedlist, duplicates)
{
    LinkedList<int> *list = new LinkedList<int>;
    list->push_back(17);
    list->push_back(52);
    list->insert_front(99);
    list->insert_front(99);
    list->push_back(99);
    ASSERT_EQ(list->length(), 5);
    list->remove_duplicates();
    ASSERT_EQ(list->length(), 3);
    ASSERT_TRUE(list->contains(99));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
{% endhighlight %}

### Output

Running the compiled test program gives you a report like this:

```
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from linkedlist
[ RUN      ] linkedlist.insertions
[       OK ] linkedlist.insertions (0 ms)
[ RUN      ] linkedlist.iterate
[       OK ] linkedlist.iterate (0 ms)
[ RUN      ] linkedlist.contains
[       OK ] linkedlist.contains (0 ms)
[ RUN      ] linkedlist.duplicates
[       OK ] linkedlist.duplicates (0 ms)
[----------] 4 tests from linkedlist (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
```
