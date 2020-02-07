---
title: Week 4 notes
layout: default
categories: [studyguides]
---

# Week 4 notes

## Table code

```
set_val:

- case 1: overwrite something that exists
- case 2: grow the array
  - call old array: t->tvals
  - call new array: new_tvals
  - make new array 1+ size of old array
  - copy everything from old array
  - add new Tval values at end of new array
  - delete [] t->tvals
  - replace t->tvals with new_tvals pointer
  - sort t->tvals

get_val:

- loop to find requested row/col
- if not found, return 0.0?

add_new_row:

- if parameter is > max_row:
  - set max_row = parameter
- else if parameter < 0:
  - undefined
- else:
  - for each tval:
    - if tval row is >= to parameter (row added),
      increase tval row by 1
  - max_row++

add_new_col:

- if parameter > max_col:
  - set max_col = parameter
- else if parameter < 0:
  - undefined
- else:
  - for each tval:
    - if tval col is >= parameter, increase tval
      col by 1
  - max_col++


test.cpp:

#include "gtest/gtest.h"
#include "table.h"

TEST(table, blank) {
    Table *t = new_table();
    ASSERT_EQ(t->tvals_size, 0);
    ASSERT_EQ(t->max_row, 0);
    ASSERT_EQ(t->max_col, 0);
    delete_table(t);
}

TEST(table, set_val) {
    Table *t = new_table();
    set_val(t, 1, 1, 10);
    ASSERT_EQ(t->max_row, 1);
    ASSERT_EQ(t->max_col, 1);
    ASSERT_EQ(t->tvals_size, 1);
    ASSERT_EQ(t->tvals[0].row, 1);
    ASSERT_EQ(t->tvals[0].col, 1);
    ASSERT_EQ(t->tvals[0].val, 10);
    delete_table(t);
}

TEST(table, get_val) {
    Table *t = new_table();
    set_val(t, 1, 1, 10);
    ASSERT_EQ(get_val(t, 1, 1), 10);
    delete_table(t);
}

TEST(table, complex) {
    Table *t = new_table();
    set_val(t, 1, 1, 10);
    set_val(t, 2, 5, 11);
    set_val(t, 1, 1, 22);
    ASSERT_EQ(get_val(t, 1, 1), 22);
    ASSERT_EQ(get_val(t, 2, 5), 11);
    ASSERT_EQ(t->max_row, 2);
    ASSERT_EQ(t->max_col, 5);
    ASSERT_EQ(t->tvals_size, 2);
    delete_table(t);
}


Makefile:

GTEST_DIR = /opt/google-test/googletest
CXX = g++
CXXFLAGS = -std=c++11 -Wall -L$(GTEST_DIR)/lib -isystem $(GTEST_DIR)/include -Wextra -lpthread

all: tables tablestest

tables: main.o table.o
    $(CXX) $(CXXFLAGS) -o tables main.o table.o

tablestest: test.o table.o
    $(CXX) $(CXXFLAGS) -o tablestest test.o table.o $(GTEST_DIR)/lib/libgtest_main.a $(GTEST_DIR)/lib/libgtest.a

test.o: test.cpp table.h
    $(CXX) $(CXXFLAGS) -c test.cpp

main.o: main.cpp table.h
    $(CXX) $(CXXFLAGS) -c main.cpp

table.o: table.cpp table.h
    $(CXX) $(CXXFLAGS) -c table.cpp

.PHONY: clean
clean:
    rm -f main.o table.o test.o tables tablestest
```
