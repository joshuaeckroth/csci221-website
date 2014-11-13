---
layout: default
title: "Library: SQLite"
---

SQLite provides simple database access. It is modeled after relational databases: you have tables with rows & columns, column types (int, double, text), and SQL statements (`INSERT INTO ...`, `SELECT * FROM ...`). The database is stored in a single file, which is created when it's opened (if it doesn't exist yet).

You can look at this database file, and run SQL commands, using the command line program `sqlite3`. You may have to install this on your machine. You can also compile it, as described [here](http://www.sqlite.org/howtocompile.html), section "Compiling the command-line interface." For a graphical interface, I recommend [SQLite Browser](http://sqlitebrowser.org/) or [SQLite Studio](http://sqlitestudio.pl/?act=download).

## Details

Download the "amalgamation" [zip file](http://www.sqlite.org/2014/sqlite-amalgamation-3080701.zip). You'll find `sqlite3.c` and `sqlite3.h` in there. Copy these to your project's folder.

Build a `Makefile` like this:

```
all: main

main: main.o sqlite3.o
	g++ -o main main.o sqlite3.o

main.o: main.cpp sqlite3.h
	g++ -c main.cpp

# Use gcc to compile this C code
sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c
```

Here are some example uses:

{% highlight cpp %}
#include <iostream>
#include "sqlite3.h"
using namespace std;

int main() {
    sqlite3 *db;
    int retval; // for checking function return values, for error codes

    // open the database, creating the file if it doesn't exist
    retval = sqlite3_open("test.db", &db);
    if(retval != 0)
    {
        cout << "Cannot open test.db: " << sqlite3_errcode(db) << endl;
        exit(1);
    }
    cout << "Successfully opened." << endl;

    cout << "Creating a table..." << endl;
    char *errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE mytable (id int, val text, x double);", NULL, NULL, &errmsg);
    if(retval != SQLITE_OK)
    {
        cout << "Error in previous command: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "INSERT INTO mytable VALUES (1, \"hello\", 2.1), (2, \"goodbye\", -0.3);", NULL, NULL, &errmsg);
    if(retval != SQLITE_OK)
    {
        cout << "Error in previous command: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    // SELECT queries
    sqlite3_stmt *s;
    const char *sql = "SELECT * FROM mytable ORDER BY id";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if(retval != SQLITE_OK)
    {
        cout << "Error in preparing statement." << endl;
    }
    while(sqlite3_step(s) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(s, 0);
        const unsigned char *val = sqlite3_column_text(s, 1);
        double x = sqlite3_column_double(s, 2);
        cout << "ID = " << id << ", val = " << val << ", x = " << x << endl;
    }
    sqlite3_finalize(s);



    sqlite3_close(db);

    return 0;
}
{% endhighlight %}