---
title: Git
layout: default
---

Git is a version control system (VCS) that allows you to keep track of
changes to your code and label certain versions as "v1.0" or "v2.0",
etc. In this class, you will use git to submit your homework and
project code. Git is widely used in industry, so it's a good idea to
learn it early and use it often.

## Basic concepts

- **repository**: git stores data about versions in a repository. If
  you put your files in a folder called, for example, `homework1`, and
  then run the `git init` command (described below), then the
  repository will be created in a special hidden folder `.git` inside
  the `homework1` folder. You can look in this folder if you want;
  just don't change anything (except possibly the `config` file, in
  special circumstances). We'll also keep a copy of the repository on
  the free service BitBucket, as a backup, and as a way for me to
  look at your code. More on this below.
  
- **commit**: a snapshot of your files; these snapshots are made when
  you run the `git commit` command. Usually, a commit has a message
  that you type when you run that command; the message describes the
  changes you have made to your files since the prior commit.

- **branch**: git allows you to keep track of different commit
  histories on different "branches." This will be discussed more
  below.

## Basic workflow

You'll want to do something like this for
[homework 1](/homework/homework-1.html). Comments are shown after the
`#` on each line.

    mkdir homework1                       # create a new directory
    cd homework1                          # go into that directory
    git init                              # create a new empty git repository

    (...create BitBucket repository, send an "invitation" to me...)

    # next, register the BitBucket repository
    git remote add origin git@bitbucket.org:joshuaeckroth/csci221-demo.git

    (...write some code...)

    git add myfile1.txt myfile2.txt       # indicate which files to save in the commit
    git commit -m "My first commit!"      # do the commit

    (...write some code...)

    git commit -a -m "My second commit!"  # record all changed files in the second commit
    git tag "v1.0"                        # save a label (tag) on the last commit
    git push --all                        # upload all commits to BitBucket
    git push --tags                       # upload tags to BitBucket

## Branches

![git branches](/images/git-branches.png "git branches")

(Image from:
[GitGuys](http://www.gitguys.com/topics/merging-branches-without-a-conflict/))

In this example, there are two branches: master and test. The master
branch is the usual name for the main development branch. When working
in teams, eventually everybody's changes get collected into the master
branch. HEAD always points to the active branch; no matter which
branch you're on, HEAD points to it. We see from the diagram that T1
is a commit that is based off of C2. C3 is a different commit also
based off C2. And C2 is based off of C1. The following commands would
have produced this scenario:

    (...make some changes...)
    git checkout master
    git commit -a -m "This is commit C1."
    (...make some changes...)
    git commit -a -m "This is commit C2."
    (...make some changes...)
    git commit -a -m "This is commit C3."
    git checkout <commit id for commit C2>
    git branch test
    (...make some changes...)
    git commit -a -m "This is commit T1."

More details about each command:

- `git checkout master` --- This command switches the master branch,
  if we're not already on that branch.
  
- `git commit -a -m "This is commit C1."` --- This command takes a
  snapshot of the current files and includes the message "This is
  commit C1." The `-a` means record all changed files; if you forget
  `-a`, you have to `git add` each file whose changes you want to save
  in the snapshot. The `-m` means you are going to provide the commit
  message (which follows); if you forget this, an editor opens up so
  you can type the message. I find it easier to put the message on the
  command line like I've shown.
  
- `git checkout <commit id for commit C2>` --- in order to switch to
  commit C2 and branch off of there, we need to know the commit id
  (also called a SHA: secure hash algorithm) for commit C2. Every
  commit has an id that looks something like "4b3a4d7cb65...". Usually
  you only need to type the first six or so characters.
  
- `git branch test` --- this creates a branch named "test" starting
  at the current commit (which is C2). Any new commits will be on this
  branch rather than master, until we switch back to master with
  another `git checkout master`.

## Books and cheatsheets

- [Official book](http://git-scm.com/book) (PDF, mobi, epub links on the left)

- [GitHub's cheatsheet](https://github.com/github/training-materials/blob/master/downloads/github-git-cheat-sheet.pdf?raw=true)

- [Tower's cheatsheet](http://www.git-tower.com/blog/git-cheat-sheet-detail/)

- [Crazy interactive cheatsheet](http://ndpsoftware.com/git-cheatsheet.html)

- [How to get out of a git mess](http://justinhileman.info/article/git-pretty/git-pretty.png)

