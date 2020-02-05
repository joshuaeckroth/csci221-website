---
title: Week 3 notes
layout: default
categories: [studyguides]
---

# Week 3 notes

## Linux

```
History:
- Unix 1970s from Bell Labs
- Unix was distributed to universities, etc. with the source; and it was written in the newly
  invented C language (for Unix), which made it portable
  - so we got a lot of Unixes that were kind of similar
- Linus Torvalds invented Linux to be a Unix that ran on Intel 386
- BSD forked off Unix also, from UC Berkeley
- Richard Stallman started GNU Project in 1983 (GNU = GNU's Not Unix)
  - purpose: completely free Unix
  - Stallman never wrote the kernel
- In 1990's Torvalds combined his kernel with Stallman's programs, and created Linux OS

fast forward:

- Linux is on every top-500 supercomputer
- Linux == Cloud Computing
- Linux runs Android
- BSD is every Apple device

Shells: terminal program for typing commands

- bash
- zsh

Bash language:

- ls | head <---- "pipe" result from ls to head
- ls | tail
- * or foo* --- collect all files or all files that start with foo
- for myvar in 1 2 3; do ABC; done
- for myvar in `ls *.txt`; do ABC; done
- echo $myvar

Bash command history:

- history
- !570 --- run history command 570
- Ctrl-r foo --- search history for foo
- !$ --- insert last parameter from prior command


Common programs:

- ls
  - ls -l --- long (all details)
  - ls -lt --- long and sorted by time
  - ls -ltr --- long and reverse sorted by time
  - ls -a --- show hidden files (e.g., .git folders; any file that start with a .)

- head -n 5
- tail -n 5
- man head --- get manual page
- cat --- show file contents
- less --- scroll file (q to quit)
- grep --- search file for matching lines
  - grep merica rockyou.txt
  - grep [0-9] rockyou.txt
  - grep -v [0-9] rockyou.txt (inverse: no digits)
- wc --- count words, lines
  - wc -l --- count lines
- htop --- show running programs (q to quit)
- file --- show type of file (txt, image, etc.)
```
