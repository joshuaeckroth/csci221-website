---
title: Homework 6
layout: default
---

Create a simple MP3 file browser.

Skills needed to complete this assignment:

- [Linked lists](/lecture/linked-lists.html)

- [Input/output](/lecture/input-output.html), particularly working
  with files

## Requirements

- Read all MP3 files (extension `.mp3`) in the current directory and all
subdirectories (recursively), and add them to a linked list.

- When reading an MP3 file, read its filename, title, artist, year, and genre. See the ID3v1 tag
  specification below). Convert genre id's to strings using the `genres.h` file in `/home/jeckroth/csci221-public/homework-6/genres.h`. Initialize the genres array with a call to `initialize_genres()` (in your `main()`) and then look up the genre id only in cases where it's `>= 0` and `< 148`. Other genre ids are considered to be in the "Unknown" genre.

- Each MP3 file should be an instance of an MP3 class. Create this class. It should have fields for the different attributes of an MP3 (from the ID3v1 tag), plus its file path.

- The linked list, containing all MP3 instances, should be managed by   an
instance of a Database class. The Database class should also provide a
handful of search functions: `search_title`, `search_artist`,
`search_album`, and `search_year`.

- Provide an interactive search mechanism, which asks whether to   search
on title or artist or year, and then asks for the search   value. The
response should be a list of all MP3 files that match the search
criteria. For title and artist, check for partial string matches   (use
the `find` string function). For year, check for exact   matches. The
Database class should do the search and print the   results, but the
`main` function should handle the user interaction.

## ID3v1 tag specification

Look at last 128 bytes of the file. It should start with "TAG" (3
bytes). Then:

- Song Title: 30 characters
- Artist: 30 characters
- Album: 30 characters
- Year: 4 characters
- Comment: 30 characters
- Genre: 1 byte

Those fields add up to 125 bytes; plus "TAG", we get 128 bytes.

Example:

{% highlight cpp %}
char title[31]; // reserve space for the terminating \0 character
f.read(title, 30); // read 30 characters from the file
title[30] = 0; // set the terminating character to \0 (integer 0)
{% endhighlight %}

Note the extra terminating character, which is required for "C-style" (old-style) strings.

## Example interaction

Given these files, available on Londo in `/home/jeckroth/csci221-public/homework-6/`,

<pre>

</pre>

These albums are as follows:

- [Calendar](https://archive.org/details/calendar)
- [Nine Inch Nails - The Slip](https://archive.org/details/nine_inch_nails_the_slip)
- [Pulse of the Earth](https://archive.org/details/Pulse_of_the_Earth)

The other files are [id3v1 tag test files](http://id3.org/Developer%20Information?action=AttachFile&do=view&target=id3v1_test_suite.tar.gz)
