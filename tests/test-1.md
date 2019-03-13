---
layout: default
title: Test 1
categories: [tests]
due: "Mon Mar 18, 11:59pm"
---

# Test 1

Create a bitbucket repo called `csci221-test1`. **Do not work with or talk about this test with anyone else. Evidence of cheating will result in a zero.**

## Honor Statement

Create a `README` file that states you worked alone on this test and did not receive help or advice from others. Type your full name in the file as your signature. **Without this statement and signature, I will not grade your submission.**

## Task

Create classes such that the `main.cpp` file below runs without errors and without any memory leaks or invalid memory accesses. Make sure all files compile without compiler warnings. Also, create a `Makefile` that compiles each file separately, has a `clean` target, and builds everything by just running `make`. Also, in your class files, do not create any functions that are not required (e.g., don't create empty functions). Also, in your class files, use `private` and `public` appopriately (use good object-oriented design). You will not need any class inheritance.

Here is the `main.cpp` file:

```
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "directory.h"
#include "file.h"

int main() {
    Directory *root = new Directory();
    assert(root->get_name() == "");
    assert(root->get_parent() == NULL);
    assert(root->get_subdir_count() == 0);
    assert(root->get_file_count() == 0);

    root->mkdir("dir1");
    assert(root->get_subdir_count() == 1);
    assert(root->get_subdirs()[0]->get_name() == "dir1");

    // making a directory wih the same name in the same place just returns existing one
    root->mkdir("dir1");
    assert(root->get_subdir_count() == 1);
    assert(root->get_subdirs()[0]->get_name() == "dir1");

    Directory *dir1 = root->get_subdir("dir1");
    assert(dir1->get_parent() == root);
    assert(dir1->get_subdir_count() == 0);
    assert(dir1->get_file_count() == 0);

    File *f1 = dir1->get_file("file1");
    assert(dir1->get_files()[0] == f1);
    f1->set_contents("foo bar");
    assert(f1->get_name() == "file1");
    assert(f1->get_contents() == "foo bar");
    assert(f1->get_size() == 7); // return contents.size()
    assert(f1->get_directory() == dir1);

    // returns existing file if filename already exists in directory
    assert(dir1->get_file("file1") == f1);

    File *f2 = dir1->get_file("file2");
    assert(f2->get_name() == "file2");
    assert(f2->get_directory() == dir1);

    assert(dir1->get_file("file1") == f1);
    assert(dir1->get_file("file2") == f2);
    assert(dir1->get_file_count() == 2);
    assert(dir1->get_files()[0] == f1);
    assert(dir1->get_files()[1] == f2);

    Directory *dir2 = dir1->mkdir("dir2");
    Directory *dir3 = root->mkdir("dir3");
    assert(dir2->get_parent() == dir1);
    assert(dir3->get_parent() == root);
    assert(dir1->get_subdir_count() == 1);
    assert(root->get_subdir_count() == 2);
    assert(root->get_subdirs()[0]->get_name() == "dir1");
    assert(root->get_subdirs()[1]->get_name() == "dir3");
    assert(dir1->get_subdirs()[0]->get_name() == "dir2");

    // root "owns" all subdirectories and files, recursively;
    // this one delete cleans up all memory
    delete root;

    cout << "All tests pass." << endl;
    return 0;
}
```

