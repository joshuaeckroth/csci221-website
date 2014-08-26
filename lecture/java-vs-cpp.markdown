---
layout: default
title: Java vs. C++
---

The assumption in CSCI221 is that you have prior experience
programming with Java. This should mean you have seen virtually all
the features of the Java language that appear on this page. We will
learn the basics of C++ by looking at the similarities and differences
with Java.

Also consider:

- [A summary of differences](http://en.wikipedia.org/wiki/Comparison_of_Java_and_C%2B%2B)
  and
  [another summary](http://stackoverflow.com/questions/9192309/the-main-difference-between-java-c)
- [A history of C++](http://www.cplusplus.com/info/history/) as well
  as a
  [historical essay by C++'s author](http://www.stroustrup.com/hopl2.pdf)

## A note about completeness

Some techniques not mentioned here, e.g., `if`'s, `for` loops, math
operations like `+`, `-`, `%`, etc., work the same in Java and C++.

## Hello World

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
<pre class="simple">
public class HelloWorld {
  public static void main(String[] args) {
    System.out.println("Hello, world!");
  }
}
</pre>
</td>
<td>
<pre class="simple">
#include &lt;iostream&gt;
using namespace std;

int main() {
  cout &lt;&lt; "Hello, world!" &lt;&lt; endl;
}
</pre>
</td>
</tr>
</tbody>
</table>

## Compiling, running

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
<pre class="simple">
$ javac HelloWorld.java
$ java HelloWorld
</pre>
</td>
<td>
<pre class="simple">
$ g++ -o hello_world hello_world.cpp
$ ./hello_world
</pre>
</td>
</tr>
</tbody>
</table>

## Primitive data types

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
<ul>
<li><code>byte</code> &mdash; 8 bits, -128 to 127</li>
<li><code>short</code> &mdash; 16 bits, -32768 to 32767</li>
<li><code>int</code> &mdash; 32 bits, -2<sup>31</sup> to
2<sup>31</sup>-1</li>
<li><code>long</code> &mdash; 64 bits, -2<sup>63</sup> to
2<sup>63</sup>-1</li>
<li><code>float</code> &mdash; 32 bits, IEEE 754</li>
<li><code>double</code> &mdash; 64 bits, IEEE 754</li>
<li><code>boolean</code> &mdash; <code>true</code> or
<code>false</code></li>
<li><code>char</code> &mdash; 16-bit Unicode character</li>
</ul>
</td>
<td>
<ul>
<li><code>char</code> &mdash; (equiv to <code>byte</code> in Java)</li>
<li><code>short</code> &mdash; at least 16 bits
<li><code>int</code> &mdash; at least 16 bits, usually 32 bits
<li><code>long</code> &mdash; at least 32 bits, usually 64 bits
<li><code>long long</code> &mdash; at least 64 bits, usually 64 bits
<li><code>float</code> &mdash; 32 bits, IEEE 754</li>
<li><code>double</code> &mdash; 64 bits, IEEE 754</li>
<li><code>long double</code> &mdash; usually 80-bit floating point</li>
<li><code>bool</code> &mdash; <code>true</code> or <code>false</code>
</ul>
</td>
</tr>
</tbody>
</table>

## String functions

In both languages, strings are arrays of `char`'s. The `String` class
is built into Java, so you don't need to do anything special to use
it. *In C++, you must write `#include <string>` at the top of your
file.* Note that `String` is capitalized in Java (like all Java
classes), while in C++ it is not.

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
Create a string:
<pre class="simple">
String msg = "Test...";
</pre>
</td>
<td>
Create a string:
<pre class="simple">
string msg = "Test...";
</pre>
</td>
</tr>

<tr>
<td>
Test if two strings are equal:
<pre class="simple">
String msg1 = "Abc";
String msg2 = "Xyz";
if(msg1.equals(msg2)) {
  // they are equal
}
</pre>
</td>
<td>
Test if two strings are equal:
<pre class="simple">
string msg1 = "Abc";
string msg2 = "Xyz";
if(msg1 == msg2) {
  // they are equal
}
</pre>
</td>
</tr>

<tr>
<td>
Append strings:
<pre class="simple">
String s1 = "Abc";
String s2 = "Xyz";
String s3 = s1 + s2;
</pre>
</td>
<td>
Append strings:
<pre class="simple">
string s1 = "Abc";
string s2 = "Xyz";
string s3 = s1 + s2;
</pre>
</td>
</tr>

<tr>
<td>
Copy a string:
<pre class="simple">
String s1 = "Abc";
// Don't do this with other class types!
// It works with String because Strings
// are immutable.
String s2 = s1;
</pre>
</td>
<td>
Copy a string:
<pre class="simple">
string s1 = "Abc";
string s2 = s1;
</pre>
</td>
</tr>

<tr>
<td>
Get the length:
<pre class="simple">
String msg = "Abc";
int msgLength = msg.length();
</pre>
</td>
<td>
Get the length:
<pre class="simple">
string msg = "Abc";
int msgLength = msg.length();
</pre>
</td>
</tr>

<tr>
<td>
Get a particular character:
<pre class="simple">
String msg = "Abc";
char letterB = msg.charAt(1);
</pre>
</td>
<td>
Get a particular character:
<pre class="simple">
string msg = "Abc";
char letterB = msg.at(1);
char letterC = msg[2];
</pre>
</td>
</tr>

<tr>
<td>
Extract a substring:
<pre class="simple">
String longMsg = "AbcXyz";
// substring args: start_idx, end_idx-1
// if end_idx is missing, take rest
// result for both commands: "Xyz"
String shortMsg = longMsg.substring(3, 6);
String shortMsg2 = longMsg.substring(3);
</pre>
</td>
<td>
Extract a substring:
<pre class="simple">
string longMsg = "AbcXyz";
// substr args: start_idx, length
// if length is missing, take rest
// result for both commands: "Xyz"
string shortMsg = longMsg.substr(3, 3);
string shortMsg2 = longMsg.substr(3);
</pre>
</td>
</tr>

<tr>
<td>
Search for a string:
<pre class="simple">
String s = "AbcXyz";
int pos = s.indexOf("Xyz");
// pos equals 3
int pos2 = s.indexOf("foo");
// pos2 equals -1
</pre>
</td>
<td>
Search for a string:
<pre class="simple">
string s = "AbcXyz";
int pos = s.find("Xyz");
// pos equals 3
int pos2 = s.find("foo");
// pos equals -1
</pre>
</td>
</tr>

<tr>
<td>
Convert a string to a number:
<pre class="simple">
String s = "123";
int x = Integer.parseInt(s);
String s2 = "123.45";
float x2 = Float.parseFloat(s2);
String s3 = "123.45";
double x3 = Double.parseDouble(s3);
</pre>
</td>
<td>
Convert a string to a number:
<pre class="simple">
// this needs: #include &lt;sstream&gt;

string s = "123";
stringstream my_converter(s);
int x;
if(!(my_converter >> x)) {
  // conversion failed
  x = 0; // default value
}

// same technique for float, double, etc;
// just change x's data type
</pre>
</td>
</tr>

<tr>
<td>
Convert a number to a string:
<pre class="simple">
String s = Integer.toString(123);
String s2 = Float.toString(123.45);
String s3 = Double.toString(123.45);
</pre>
</td>
<td>
Convert a number to a string:
<pre class="simple">
// this needs: #include &lt;sstream&gt;

stringstream my_converter;
my_converter << 123; // or a variable
string s = my_converter.str();

my_converter << 123.45;
string s = my_converter.str();
</pre>
</td>
</tr>

</tbody>
</table>

## Input/output (keyboard/console)

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
Read from the keyboard:
<pre class="simple">
Scanner sc = new Scanner(System.in);
int i = sc.nextInt();
float x = sc.nextFloat();
String line = sc.nextLine();
</pre>
</td>
<td>
Read from the keyboard:
<pre class="simple">
// this needs: #include &lt;iostream&gt;
// use of strings needs: #include &lt;string&gt;

int i;
cin >> i;
float x;
cin >> x;

// cin with a string gets a word, not a line!
string word;
cin >> word;

string line;
getline(cin, line); // get the whole line
</pre>
</td>
</tr>

<tr>
<td>
Print to the console:
<pre class="simple">
System.out.println("Hello, world!");
int x = 5;
System.out.println("X = " + x);
// print y with four decimal places
double y = 4.35;
System.out.format("Y = %.4f%n", y);
// print h in hex
int h = 5038;
System.out.format("H in hex = %X%n", h);
</pre>
</td>
<td>
Print to the console:
<pre class="simple">
// this needs: #include &lt;iostream&gt;
// and: #include &lt;iomanip&gt;

cout << "Hello, world!" << endl;
int x = 5;
cout << "X = " << x << endl;
// print y with four decimal places
double y = 4.35;
cout << "Y = " << setprecision(4)
     << fixed << y << endl;
// print h in hex
int h = 5038;
cout << "H in hex = " << hex << h << endl;
</pre>
</td>
</tr>
</tbody>
</table>

## Input/output (files)

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
Write to a file:
<pre class="simple">
FileWriter fout = new FileWriter("foo.txt");
PrintWriter out = new PrintWriter(fout);
out.println("Hello, world!");
out.close();
</pre>
</td>
<td>
Write to a file:
<pre class="simple">
// this needs: #include &lt;iostream&gt;
// and: #include &lt;fstream&gt;

ofstream out;
out.open("foo.txt");
out << "Hello, world!" << endl;
out.close();
</pre>
</td>
</tr>

<tr>
<td>
Read from a file:
<pre class="simple">
FileReader fin = new FileReader("foo.txt");
BufferedReader in = new BufferedReader(fin);
String line = in.readLine();
int x = Integer.parseInt(line);
in.close();
</pre>
</td>
<td>
Read from a file:
<pre class="simple">
ifstream in;
in.open("foo.txt");
int x;
in >> x;
in.close();
</pre>
</td>
</tr>

</tbody>
</table>

## Math functions

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
<pre class="simple">


Math.abs(-15);
Math.ceil(2.35);
Math.floor(2.35);
Math.round(2.35);
Math.log(2.35);
Math.max(5, 3);
Math.min(5, 3);
Math.pow(5, 3);
</pre>
</td>
<td>
<pre class="simple">
// these need: #include &lt;cmath&gt;

abs(-15);
ceil(2.35);
floor(2.35);
round(2.35);
log(2.35);
fmax(5, 3);
fmin(5, 3);
pow(5, 3);
</pre>
</td>
</tr>

</tbody>
</table>

## Classes

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
Define a class. This code must be in a file with the same name as the
class, i.e., `MyClass.java`.
<pre class="simple">
public class MyClass {
  public int x;
  private float y;

  public MyClass(int x) {
    this.x = x;
    y = 35.25;
  }

  public float getY() {
    return y;
  }

  private void incrementX() {
    x++;
  }
}
</td>
<td>
Typically in C++, we declare the class in a file like `myclass.h` and
define its methods in a file like `myclass.cpp`.
<pre class="simple">
// myclass.h

class MyClass {
  public:
    int x;
    MyClass(int x);
    float getY();
    
  private:
    float y;
    void incrementX();
}



// myclass.cpp
#include &lt;myclass.h&gt;

MyClass::MyClass(int x) {
  this->x = x;
}

float MyClass::getY() {
  return y;
}

void MyClass::incrementX() {
  x++;
}
</td>
</tr>

</tbody>
</table>

## Type casting and polymorphism

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
Cast primitive types:
<pre class="simple">
float a = 5.5;
int b = 3;

int x = (int)a;
float y = (float)b;
</pre>
</td>
<td>
Cast primitive types:
<pre class="simple">
float a = 5.5;
int b = 3;

int x = (int)a;
float y = (float)b;
</pre>
</td>
</tr>

<tr>
<td>
Single inheritance:
<pre class="simple">
public class A { ... }
public class B extends A { ...}
</pre>
This means that class <code>B</code> inherits all public members
(variables, methods) of class <code>A</code>. Furthermore, those
public members of <code>A</code> are <strong>public</strong> in
<code>B</code>. (Note, I'm ignoring "protected" members and their
inheritance rules.)
</td>
<td>
Single inheritance:
<pre class="simple">
class A { ... }
class B : public A { ... }
</pre>
<p>
This means that class <code>B</code> inherits all public members
(variables, methods) of class <code>A</code>. Furthermore, those
public members of <code>A</code> are <strong>public</strong> in
<code>B</code>. (Note, I'm ignoring "protected" members and their
inheritance rules.)
</p>
<p>
Another variant:
<pre class="simple">
class A { ... }
class B : private A { ... }
</pre>
</p>
<p>
This means that class <code>B</code> inherits all public members
(variables, methods) of class <code>A</code>. Furthermore, those
public members of <code>A</code> are <strong>private</strong> in
<code>B</code>.
</td>
</tr>

<tr>
<td>
Multiple inheritance: Not possible. Use interfaces (see below) as a
work-around.
</td>
<td>
Multiple inheritance:
<pre class="simple">
class A { ... }
class B { ... }
class C : public class A, public class B
{ ... }
</pre>
This means that class <code>C</code> inherits all public members of
classes <code>A</code> and <code>B</code>. If both <code>A</code> and
<code>B</code> include some of the same members (e.g., same function
names), then code in class <code>C</code> must be explicit about
whether it is referring to members inherited from <code>A</code> or
<code>B</code>.
</td>
</tr>

<tr>
<td>
Override inherited methods:
<pre class="simple">
public class A {
  public void foo() { ... }
}

public class B extends A {
  // override inherited foo()
  public void foo() { ... }
}
</pre>
</td>
<td>
Override inherited methods:
<pre class="simple">
class A {
  public:
  virtual void foo();
}

class B : public A {
  public:
  // override inherited foo()
  virtual void foo();
}
</pre>
In other words, only <code>virtual</code> functions can be overridden
in the way you would expect from Java. The <code>virtual</code>
keyword activates polymorphism. So, if we have a <code>B</code>
object but cast it to an <code>A</code> object, and then call its
<code>foo()</code> method, it would use <code>B</code>'s
<code>foo()</code> method. If <code>foo()</code> was not virtual in
the base class, then after casting our <code>B</code> object to an
<code>A</code>, <code>A</code>'s <code>foo()</code> function would
be used and <code>B</code>'s <code>foo()</code> function would be
inaccessible.
</td>
  
<tr>
<td>
Interfaces:
<pre class="simple">
interface Foo {
  void methodA();
  int methodB(int bar);
}

class Quux implements Foo {
  void methodA() { ... }
  int methodB(int bar) { ... }
}
</pre>
</td>
<td>
Interfaces in C++ are accomplished with "pure" virtual functions,
e.g., class functions that have no code, but must be defined in
descendent classes.
<pre class="simple">
class Foo {
  virtual void methodA() = 0;
  virtual int methodB(int bar) = 0;
}

class Quux : public Foo {
  virtual void methodA() { ... }
  virtual int methodB(int bar) { ... }
}
</pre>
</td>
</tr>

</tbody>
</table>

## Arrays

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
Create and initialize arrays:
<pre class="simple">
int[] xs = new int[10];
int[][] matrix = new int[5][7];
int[] ys = {1, 2, 3, 4};

// ragged array
int[][] matrix2 = { {1, 2}, {3, 4, 5} };
</pre>
</td>
<td>
Create and initialize arrays:
<pre class="simple">
int xs[10];
int matrix[5][7];
int ys[] = {1, 2, 3, 4};

// ragged array is not possible
// without multiple lines of code
// (often involving a loop)

// instead, try this rectangular
// 2d array
int matrix2 = { {1, 2, 3}, {4, 5, 6} };
</pre>
</td>
</tr>

</tbody>
</table>

## Collections

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
Lists:
<pre class="simple">
Integer myint = new Integer(5);
List&lt;Integer&gt; mylist = new ArrayList&lt;Integer&gt;();

mylist.add(myint);
boolean yeah = mylist.contains(myint);

// get from index 0
Integer myint2 = mylist.get(0);

int count = mylist.size();
mylist.clear();
</pre>
</td>
<td>
Vectors are used more commonly:
<pre class="simple">
// this needs #include &lt;vector&gt;
// and #include &lt;algorithm&gt;
// (the latter for the find() function)

vector&lt;int&gt; mylist;
mylist.push_back(5);
vector&lt;int&gt;::iterator myIt;
myIt = find(mylist.begin(), mylist.end(), 5);
if(myIt != mylist.end()) {
  cout << "found the number 5." << endl;
}

int x = mylist[0];
mylist.clear();
</pre>
</td>
</tr>

<tr>
<td>
Maps (key-value pairs):
<pre class="simple">
Map&lt;String, Integer&gt; mymap =
  new HashMap&lt;String, Integer&gt;();
mymap.put("foo", 5);
Integer c = mymap.get("foo");
mymap.remove("foo");
</pre>
</td>
<td>
Maps (key-value pairs):
<pre class="simple">
// this needs #include &lt;map&gt;

map&lt;string, int&gt; mymap;
mymap["foo"] = 5;
int c = mymap["foo"];
mymap.erase("foo");
</pre>
</td>
</tr>
</tbody>
</table>

## Generics / Templates

<table>
<thead>
<tr>
<th>Java</th>
<th>C++</th>
</tr>
</thead>
<tbody>

<tr>
<td>
<pre class="simple">
public class Foo&lt;T&gt; {
  T value;
  T func(T arg) { ... }
}
</pre>
</td>
<td>
<pre class="simple">
template&lt;typename T&gt;
class Foo {
  public:
  T value;
  T func(T arg);
}
</pre>
</td>
</tr>

</tbody>
</table>

