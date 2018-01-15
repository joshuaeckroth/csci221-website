---
title: Proficiency exams
layout: default
categories: [studyguides]
---

# Proficiency exams

Exams will take place twice in the semester. You can choose which of
the major topics that make up your individual examination on each exam
day. Due to time, you will be asked to perform a random subset of
actions. You cannot use notes while being examined.

## Linux

All tasks must be completed with a single command line.

- list files in the current directory, sorted by date (newest last), with file sizes reported
- show hidden files (dot files)
- list the names of all *.txt files in the current directory or deeper, with a size greater than 1024 bytes
- show 3 lines before/after each mention of a certain phrase (regex) in a collection of files
- show matches among the first 200 lines of a file that contain a certain regex
- replace all instances of one phrase with another in a file, without using an editor
- create a symbolic link
- count the number of unique words in a text file
- demonstrate the use of man pages
- show which man pages contain a certain keyword
- show a list of processes in such a way that you can pick out the process using the most CPU
- show a tree of processes
- print the process id of a certain running program (don't print more than this processor id)
- show the amount of free memory on the system
- show disk space free in GB/MB/etc. units
- show the initial bootup log messages produced by the kernel
- explain what an environment variable is
- explain the `PATH` environment variable
- change your password, then change it back
- change the permissions of some file or directory to a certain configuration
- print the system date/time in a particular format
- make a directory, remove a directory (recursively)
- show who is logged in to the system
- start a program (e.g., `less`), and send it to the background; then start another; send it to background and bring back first
- send a command to background (stopped) and then revive it but still in background (so it is now running, but in the background)
- show all running/stopped background jobs
- create a gz compressed file
- add a bunch of files into a compressed archive (tarball), keeping directory structure; then extract somewhere else; then do the same for zip
- show all contents of a tarball/zipfile

## Bash

- run a program like grep and show its return value (an integer), also known as an error code
- create a loop that runs the 'file' command on every file listed by a certain ls expression (e.g., ls *.txt)
- demonstrate searching through command line history
- set a variable and then use that variable in a future command line
- start a subshell, then leave it

## Tmux / Screen

- create a session, detach from it, log out, log back in, reattach session
- list all active sessions
- create multiple windows in session, switch among them
- split a window into panes (both panes visible on screen), switch among the panes

## Git

- clone a repository from bitbucket or github
- create a new repository in a new folder
- add files to a repo, commit those files
- delete some files, commit the deletion
- make some changes to files, then show the changes before committing or "adding" ("staging") them
- make some changes to files, stage them, then show the changes before committing
- show the diff of a specific commit
- show the diff between two arbitrary commits
- replace the current contents of the repo (workspace) with the files as they looked at a certain commit
- create a branch from some arbitrary commit
- make changes in a branch, commit them, then merge the branch back into "master"
- make incompatible changes (non-auto-mergable) across two branches, then merge them and fix the merge conflicts
- list all branches, delete a branch
- show a "graphical" (ASCII) log of commit history with all branches shown
- change the log message on the most recent commit
- merge changes from upstream (e.g., bitbucket/github) without using "git pull"
- fork one of my github repos, create a pull request
- find a random github repo with pull requests, clone it (do not fork it), then merge in someone's pull request
- demonstrate the use of 'git bisect' to find a particular version of the code with some property (e.g., tests pass)

## Vim

Note: all actions must be performed without using arrow keys or the mouse; and every action should be a single command, unless stated otherwise.

- replace every occurrence of some word with another in a single line / in the whole file
- translate a Windows text file with \r\n line-endings to a Unix text file with \n line endings
- jump to the top of the file, jump to the bottom
- delete from the current point to the end of the file
- delete from the current point to the first occurrence of a certain symbol/phrase
- delete from the current point backwards to the most recent occurrence of a certain symbol/phrase
- delete from a current point to the end of the line
- delete 5 lines
- repeat the last command 10 times
- undo the last 3 commands; then redo them
- delete something, then paste it somewhere else (this is multiple commands)
- "copy" something, then paste it somewhere else (without deleting it first; this is multiple commands)
- "visually" select a block of text, cut it, then paste it elsewhere
- in a few keystrokes, "visually" select the entire file
- in a C++ file or similar, jump from inside a block {} to the end of the block
- in a C++ file or similar, cut a block, then paste it elsewhere
- save a file and quit; quit without saving the file
- split the window vertically / horizontally, switch back and forth among the windows
- using a "tags" file for some code, jump to the definition of some function / variable, then jump back
- show the internal help pages matching a certain phrase
- turn on/off line numbers (along the left margin)
- reindent a section of code

## Emacs

Note: all actions must be performed without using arrow keys or the mouse.

- replace every occurrence of some word with another in a single line / in the whole file
- translate a Windows text file with \r\n line-endings to a Unix text file with \n line endings
- jump to the top of the file, jump to the bottom
- delete from the current point to the end of the file
- delete from the current point to the first occurrence of a certain symbol/phrase
- delete from the current point backwards to the most recent occurrence of a certain symbol/phrase
- delete from a current point to the end of the line
- delete 5 lines
- repeat the last command 10 times
- undo the last 3 commands; then redo them
- delete something, then paste it somewhere else
- "copy" something, then paste it somewhere else (without deleting it first; this is multiple commands)
- in a C++ file or similar, jump from inside a block {} to the end of the block
- in a C++ file or similar, cut a block, then paste it elsewhere
- save a file and quit; quit without saving the file
- using a "tags" file for some code, jump to the definition of some function / variable, then jump back
- split the window vertically / horizontally, switch back and forth among the windows
- show what function will execute for a certain key press
- open the "customize" feature and show how to permanently change a variable
- turn on/off line numbers (along the left margin)
- reindent a section of code

