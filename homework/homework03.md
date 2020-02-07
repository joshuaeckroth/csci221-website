---
layout: default
title: "HW03: Tables"
due: "Mon Feb 10, 11:59pm"
categories: [assignments]
---

# HW03: Tables

Fill in the code below by adding the functions indicated. Also add at least two test cases for each function. Note, we are using the "coordinate list" ([COO](https://en.wikipedia.org/wiki/Sparse_matrix#Coordinate_list_(COO))) format for storing these sparse tables.

See the comment labeled "TODO" below for the functions that need to be added.

Name your bitbucket repository exactly `csci221-hw03`. Make sure to add me ('eckroth@cse.ohio-state.edu') as a "reader" to your repository.

## Template code

```
#include <iostream>
using namespace std;

struct Tval {
    int row;
    int col;
    double val;
};

struct Table {
    // array of Tval objects
    Tval *tvals;
    int tvals_size;
    int max_row;
    int max_col;
};

int compareTval(const void *a, const void *b) {
    Tval *t1 = (Tval*)a;
    Tval *t2 = (Tval*)b;
    if(t1->row < t2->row) {
        return -1;
    } else if(t1->row > t2->row) {
        return 1;
    } else { // rows match
        if(t1->col < t2->col) {
            return -1;
        } else if(t1->col > t2->col) {
            return 1;
        } else { // same row and col
            return 0;
        }
    }
}

void print_table(Table *t) {
    int idx = 0;
    for(int i = 0; i <= t->max_row; i++) {
        for(int j = 0; j <= t->max_col; j++) {
            if(idx < t->tvals_size && t->tvals[idx].row == i && t->tvals[idx].col == j) {
                cout << t->tvals[idx].val;
                idx++;
            }
            cout << "\t";
        }
        cout << endl;
    }
}

Table *new_table() {
    Table *t = new Table;
    t->max_row = 0;
    t->max_col = 0;
    t->tvals_size = 0;
    t->tvals = NULL; // aka 0
    return t;
}

void delete_table(Table *t) {
    if(t->tvals != NULL) {
        delete[] t->tvals;
    }
    delete t;
}

// TODO:
// - set table value at certain row/column
// - get table value at certain row/column
// - add new row at row position (possibly in middle)
//   - all tvals below need their row updated to +1
// - add new col at col position (possibly in middle)
//   - all tvals to the right need their col updated to +1
// ALL of above: no memory leaks, no crashes; watch edge cases (empty tables)

int main() {

    // build a simple table for testing
    Table *t1 = new Table;
    t1->max_row = 3;
    t1->max_col = 4;
    t1->tvals_size = 2;
    // make three Tval objects
    t1->tvals = new Tval[2];
    t1->tvals[0].row = 3;
    t1->tvals[0].col = 2;
    t1->tvals[0].val = 99.28;
    t1->tvals[1].row = 2;
    t1->tvals[1].col = 4;
    t1->tvals[1].val = 10.11;
    qsort(t1->tvals, 2, sizeof(Tval), compareTval);
    print_table(t1);
    delete_table(t1);

    // make a big table
    Table *tbig = new Table;
    tbig->max_row = 2000;
    tbig->max_col = 500;
    tbig->tvals_size = (2001*501);
    tbig->tvals = new Tval[2001*501];
    int idx = 0;
    for(int i = 0; i <= 2000; i++) {
        for(int j = 0; j <= 500; j++) {
            tbig->tvals[idx].row = i;
            tbig->tvals[idx].col = j;
            tbig->tvals[idx].val = 0;
            idx++;
        }
    }
    qsort(tbig->tvals, 2001*501, sizeof(Tval), compareTval);
    //print_table(tbig);
    delete_table(tbig);

    return 0;
}
```
