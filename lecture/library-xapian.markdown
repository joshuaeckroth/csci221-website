---
layout: default
title: "Library: Xapian"
---

Xapian provides search capabilities to your program. It supports fulltext search and complex boolean queries. Xapian uses an index, so you have to add data to an index before you can search the index. The index can be on-disk or in-memory; if it's on-disk, you won't need to rebuild it every time your program starts.

{% highlight cpp %}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <xapian.h>
using namespace std;

// Read a file into a string.
// from: http://stackoverflow.com/a/525103
string readFile(const string &fileName)
{
    ifstream ifs(fileName.c_str(), ios::in | ios::binary | ios::ate);

    ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, ios::beg);

    vector<char> bytes(fileSize);
    ifs.read(&bytes[0], fileSize);

    return string(&bytes[0], fileSize);
}

// command-line arguments will be filenames to index
int main(int argc, char **argv) {

    // Create or open the database we're going to be writing to.
    Xapian::WritableDatabase db("test.idx", Xapian::DB_CREATE_OR_OPEN);

    // Alternative: in-memory db:
    //Xapian::WritableDatabase db = Xapian::InMemory::open();

    // Set up a TermGenerator that we'll use in indexing.
    Xapian::TermGenerator termgenerator;

    // Use a "stemmer", which reduces words like "root", "rooting", "rooted", etc. to their common stem "root"
    // before adding to the index. Queries will need to be stemmed, too (see below).
    termgenerator.set_stemmer(Xapian::Stem("en"));

    for(int i = 1; i < argc; i++)
    {
        string fname(argv[i]);
        ifstream f(fname.c_str());
        if(f.is_open())
        {
            string body = readFile(fname);
            Xapian::Document doc;
            termgenerator.set_document(doc);

            termgenerator.index_text(body);

            // set the human-readable doc data; Xapian ignores this, but can show it to the user
            doc.set_data(fname + "\n\n" + body.substr(0, min((unsigned long)body.size(), (unsigned long)100)) + "...");

            // give each doc a unique ID based on filename; this ensures we don't add the same doc twice
            // (if the program is run multiple times, or the filename is specified twice on the command line)
            string idterm = "FNAME" + fname;
            doc.add_boolean_term(idterm);
            // instead of add_document, use replace_document, so it only is included once in the index
            db.replace_document(idterm, doc);
            f.close();
        }
    }

    // Now let's search
    int offset = 0;
    int pagesize = 10;
    Xapian::QueryParser queryparser;
    string querystring;
    while(true)
    {
        cout << "Enter a search query (or \"quit\"): ";
        getline(cin, querystring);
        if(querystring == "quit")
        {
            break;
        }
        queryparser.set_stemmer(Xapian::Stem("en"));
        queryparser.set_stemming_strategy(queryparser.STEM_SOME);
        Xapian::Query query = queryparser.parse_query(querystring);
        Xapian::Enquire enquire(db);
        enquire.set_query(query);
        Xapian::MSet mset = enquire.get_mset(offset, pagesize);

        cout << "Showing results " << offset + 1 << "-" << min(offset + pagesize, (int)mset.size())
             << " of " << mset.size() << endl;
        for(Xapian::MSetIterator m = mset.begin(); m != mset.end(); ++m)
        {
            Xapian::docid did = *m;
            cout << m.get_rank() + 1 << ": DocID " << did << ", match score: " << m.get_percent() << endl;

            string data = m.get_document().get_data();
            cout << data << endl << endl << endl;
        }
        cout << endl << endl;
    }

    return 0;
}
{% endhighlight %}

## Makefile

Use a `Makefile` like this. You'll need to have installed Xapian so that `xapian-config` is executable. This works on Londo.

```
CXX=g++
CXXFLAGS=-g -Wall -ansi `xapian-config --cxxflags` `xapian-config --libs`

all: main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o
```

## Delve: Tool for inspecting indexes

Xapian comes with a command-line tool called `delve`. If you created an index on-disk (as opposed to in-memory), you can use this tool to see what's in there.

You can get some stats:

<pre>
$ <u>delve test.idx</u>
UUID = cb27339f-1cfd-49aa-81a3-539909fb0887
number of documents = 31
average document length = 355968
document length lower bound = 72850
document length upper bound = 4749922
highest document id ever used = 31
has positional information = true
</pre>

And you can list all details for some record (document) number:

<pre>
$ <u>delve -r 1 -d test.idx</u>

Data for record #1:
/Users/JoshuaEckroth/Documents/git/csci221/2014-fall/class-examples/xapian/gutenberg/0ws0610.txt

***The Project Gutenberg's Etext of Shakespeare's First Folio***
**********************The Comedie of Errors*********************

This is our 3rd edition of most of these plays.  See the index.


Copyright laws are changing all over the world, be sure to check
the copyright laws for your country before posting these files!!

...

FINIS. The Comedie of Errors.

Term List for record #1: abbey abbreviations abetting abhorre abiect ...
</pre>
