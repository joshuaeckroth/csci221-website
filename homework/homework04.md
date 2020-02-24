---
layout: default
title: "HW04: Cyclic Bidirectional Linked List"
due: "Wed Feb 26, 11:59pm"
categories: [assignments]
---

# HW04: Cyclic Bidirectional Linked List

Add test cases (using Google Test framework as shown in class), particularly for edge cases, and fix any bugs and memory leaks in the code below. Most functions should probably have at least three test cases. Also add this feature:

- Print the linked list. This function should be provided a function pointer for printing each element (since they're `void*` pointers, the linked list code cannot know how to print the values without being provided such a function). Print starting at the current element until the end of the list (when current element cycles back around).

Name your bitbucket repository exactly `csci221-hw04`. Make sure to add me ('eckroth@cse.ohio-state.edu') as a "reader" to your repository.

## linkedlist.cpp

```
#include "linkedlist.h"

LinkedList *new_list() {
    LinkedList *list = new LinkedList;
    list->cur = nullptr;
    return list;
}

void push(LinkedList *list, void *val) {
    Node *node = new Node;
    node->val = val;
    node->next = list->cur->next;
    node->prev = list->cur;
}

void *peek(LinkedList *list) {
    if(list->cur != nullptr) {
        return list->cur->val;
    }
    return nullptr;
}

void forward(LinkedList *list) {
    list->cur = list->cur->next;
}

void backward(LinkedList *list) {
    list->cur = list->cur->prev;
}

void *pop(LinkedList *list) {
    void *val = list->cur->val;
    Node *tmp = list->cur;
    list->cur = tmp->next;
    tmp->prev->next = list->cur;
    list->cur->prev = tmp->prev;
    delete tmp;
    return val;
}

void delete_list(LinkedList *list) {
    Node *start = list->cur;
    list->cur = list->cur->next;
    while(start != list->cur) {
        Node *next = list->cur->next;
        delete list->cur;
        list->cur = next;
    }
}

int list_count(LinkedList *list) {
    int count = 1;
    Node *start = list->cur;
    list->cur = list->cur->next;
    while(start != list->cur) {
        count++;
    }
    return count;
}
```

## linkedlist.h

```
struct Node {
    void *val;
    Node *next;
    Node *prev;
};

struct LinkedList {
    Node *cur;
};

LinkedList *new_list();
// add node to right of cur
void push(LinkedList *list, void *val);
// get value from cur node
void *peek(LinkedList *list);
// delete cur node and return its value
void *pop(LinkedList *list);
// move cur forward (right)
void forward(LinkedList *list);
// move cur backward (left)
void backward(LinkedList *list);
// clean up memory
void delete_list(LinkedList *list);
// count items
int list_count(LinkedList *list);
```

## test.cpp

```
#include <iostream>
using namespace std;
#include "gtest/gtest.h"

#include "linkedlist.h"

TEST(list, blank) {
    LinkedList *list = new_list();
    ASSERT_EQ(list->cur, nullptr);
    delete_list(list);
}

TEST(list, push_to_blank_double) {
    LinkedList *list = new_list();
    double val = 55.0;
    push(list, &val);
    ASSERT_NE(list->cur, nullptr);
    ASSERT_EQ(peek(list), &val);
    delete_list(list);
}

TEST(list, push_to_blank_struct) {
    struct Student {
        double gpa; int year;
    };
    LinkedList *list = new_list();
    Student s;
    s.gpa = 3.5;
    s.year = 3;
    push(list, &s);
    ASSERT_NE(list->cur, nullptr);
    ASSERT_EQ(((Student*)peek(list))->gpa, 3.5);
    delete_list(list);
}
```

## Makefile

```
GTEST_DIR = /opt/google-test/googletest
CXX = g++
CXXFLAGS = -std=c++11 -Wall -L$(GTEST_DIR)/lib -isystem $(GTEST_DIR)/include -Wextra -lpthread

all: test

test: test.o linkedlist.o
    $(CXX) $(CXXFLAGS) -o test test.o linkedlist.o $(GTEST_DIR)/lib/libgtest_main.a $(GTEST_DIR)/lib/libgtest.a

test.o: test.cpp linkedlist.h
    $(CXX) $(CXXFLAGS) -c test.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
    $(CXX) $(CXXFLAGS) -c linkedlist.cpp

.PHONY: clean
clean:
    rm -f test *.o
```

