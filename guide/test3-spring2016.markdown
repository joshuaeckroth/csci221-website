---
title: Test 3 from Spring 2016
layout: default
categories: [studyguides]
---

# Test 3 from Spring 2016

Total: 70pts.

1\. (10pts) This question tests that you can read UML. Here is a random UML diagram (from: [http://spacecraft.sourceforge.net/doc/api/ProgrammingRefresher.html](http://spacecraft.sourceforge.net/doc/api/ProgrammingRefresher.html))

![Random UML diagram](http://spacecraft.sourceforge.net/doc/api/ExampleUML.jpg)

Implement everything specified in the diagram (in .h and .cpp files). Don't bother writing any code for the methods. Don't bother writing a main method. Make sure you include appropriate fields for the relationship between Car and Axel and Axel and Wheel. Take note of abstract polymorphic methods (italics) and public vs. private.


2\. (30pts) This question tests that you can implement a template data structure. Create a template class called OrderedSet that uses STL vectors for the actual implementation. Your class should work on any data type (hence the phrase "template class") and should meet the following constraints: no element appears twice (hence "set") and when iterating through the set, elements are in ascending order (hence "ordered"). Use the STL sort method to achieve this. Do not use the STL set class for any part of this class. Support the operations insert(val), erase(val), at(index), size(), and clear(). Create a main() method that tests each of these methods at least once.

3\. (30pts) This question tests that you can make sense of library documentation. Create a program that uses the jansson v2.6 ([docs](https://jansson.readthedocs.org/en/2.6/index.html)) library to read a recent Wikipedia JSON dump. This JSON dump includes all sorts of info about every page on Wikipedia; we only want a list of titles. Jansson is already installed on londo (and can be built on Windows).

The format of the Wikipedia JSON dump is described [here](https://www.mediawiki.org/wiki/Wikibase/DataModel/JSON). The file may be found on londo at /usr/local/csci221sp2016/wikidata-20160418-all.json.gz. Every line of the dump is a separate JSON entity representing an article. We only want the English title of the article, which appears like so: `{"label": {"en": {"value": "we care about this value"}}}`. Print this value ("we care about this value"), one per line. Hint: skip the first line of the dump, which is just a left-bracket, and chop off the last character (a comma) of each line (after the skipped first line).

The Wikipedia dump is compressed in gzip format, and we don't want to uncompress it (it's too big). So, we can use the Boost library to read the file in gzip format (this library can be built on Windows also):

```
// example code for using the Boost gzip library

#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
using namespace std;
using namespace boost::iostreams;
using namespace boost::iostreams::gzip;

int main()
{
    ifstream file("/usr/local/csci221sp2016/wikidata-20160418-all.json.gz", ios_base::in | ios_base::binary);
    filtering_stream<input> in;
    in.push(gzip_decompressor());
    in.push(file);

    // this is how you read a line at a time:
    string line;
    getline(in, line);

    // if you need a C-style string, convert the C++ string:
    const char *str = line.c_str();
}
```

Compile with this command on londo: `g++ -Wall -g -ljansson -lboost_iostreams -o wikipedia wikipedia.cpp`

Don't leak memory. Check with valgrind.

Example output (stopping after first 10 records):

```
universe
happiness
highway system
place of birth
father
George Washington
Jack Bauer
Belgium
instance of
Finland
```
