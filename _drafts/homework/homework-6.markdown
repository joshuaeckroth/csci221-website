---
title: Homework 6
layout: default
---

Create a simple MP3 file browser. Document your design with UML.

Skills needed to complete this assignment:

- [Types and classes](/lecture/types-and-classes.html), particularly
  working with the string type

- [Linked lists](/lecture/linked-lists.html)

- [Input/output](/lecture/input-output.html), particularly working
  with files

- [UML](/lecture/uml.html)

## Requirements

- Read all MP3 files in the current directory (recursively), and add
  them to a linked list.

- When reading an MP3 file, read its filename (string), title
  (string), artist (string), and year (as an integer; see ID3v1 tag
  specification below).

- Each MP3 file should be an instance of an MP3 class.

- The linked list, containing all MP3 instances, should be managed by
  an instance of a Database class.

- Provide an interactive search mechanism, which asks whether to
  search on title or artist or year, and then asks for the search
  value. The response should be all MP3 files that match the search
  criteria. For title and artist, check for partial string matches
  (use the `find` string function). For year, check for exact
  matches. The Database class should do the search and print the
  results, but the `main` function should handle the user interaction.

- Construct a UML diagram that shows the MP3 and Database classes,
  plus their fields and methods, and their relationship.

## ID3v1 tag specification

http://id3.org/ID3v1

Look at last 128 bytes of the file. It should start with "TAG" (3
bytes). Use `seekg` on the file, with a negative number. Then:

- Song Title: 30 characters (i.e., 30 `char`'s, each 1 byte)
- Artist: 30 characters
- Album: 30 characters
- Year: 4 characters
- Comment: 30 characters
- Genre: 1 byte

Those fields add up to 125 bytes; plus "TAG", we get 128 bytes.

