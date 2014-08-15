---
layout: default
title: Java vs. C++
---

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
it. In C++, you must write `#include <string>` at the top of your
file. Note that `String` is capitalized in Java (like all Java
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
</td>
<td>
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
</td>
<td>
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
</td>
<td>
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
</td>
<td>
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
</td>
<td>
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
</td>
<td>
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
</td>
<td>
</td>
</tr>

</tbody>
</table>

