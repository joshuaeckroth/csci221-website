---
title: Git
layout: default
---

# Git

Git is a version control system (VCS) that allows you to keep track of
changes to your code and label certain versions as "v1.0" or "v2.0",
etc. In this class, you will use git to submit your homework and
project code. Git is widely used in industry, so it's a good idea to
learn it early and use it often.

## BitBucket setup

You are required to keep a copy of your homework on the free service
[BitBucket](https://bitbucket.org), as a backup, and as a way for me
to look at your code. Sign up for an account there, and tell me your
username (as we discussed in class).

Create a new repository for each homework assignment. Keep it private,
but add me as a viewer. This will be demonstrated in class.

## Git installation

### Linux

If you use Ubuntu or some other Debian variant, this should work:

    sudo apt-get install git

For other distributions, refer to Google, or ask me.

### Windows

Download [msysGit](http://msysgit.github.io/). Use the default
options. Run the "Git Bash" program that's installed in order to use
git commands.

### Mac OS X

You can install git by installing "Xcode command line tools" with the
following command in a terminal:

    xcode-select --install

Or, download directly from the
[git project](http://git-scm.com/download/mac).

### Post-installation configuration

You'll need to tell git your name and email. Every commit is recorded
with a name and email. You should use the same email address you used
when you created a BitBucket account.

Execute these commands (use your own name and email!):

    git config --global user.name "Joshua Eckroth"
    git config --global user.email "jeckroth@stetson.edu"

## Basic concepts

- **repository**: git stores data about versions in a repository. If
  you put your files in a folder called, for example, `homework0`, and
  next run the `git init` command (described below), then the
  repository will be created in a special hidden folder `.git` inside
  the `homework0` folder. You can look in this folder if you want;
  just don't change anything (except possibly the `config` file, in
  special circumstances).
  
- **commit**: a snapshot of your files; these snapshots are made when
  you run the `git commit` command. Usually, a commit has a message
  that you type when you run that command; the message describes the
  changes you have made to your files since the prior commit.

- **branch**: git allows you to keep track of different commit
  histories on different "branches." This will be discussed more
  below.

- **tag**: a label for a particular commit; we will "turn in" homework
  by adding a tag to the "master" branch with the tag name
  "v1.0". Whichever version of code that you tag as "v1.0" is the
  version that is graded.

## Basic workflow

You'll want to do something like this for
[homework 0](/homework/homework-0.html). Comments are shown after the
`#` on each line. These commands should work on Linux/Mac OS
X/Windows, assuming you have installed Git.

    mkdir homework0                       # create a new directory
    cd homework0                          # go into that directory
    git init                              # create a new empty git repository

    (...create BitBucket repository, send an "invitation" to me...)

    # next, register the BitBucket repository;
    # of course, CHANGE THIS EXAMPLE to your repository location!
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

As stated above, git allows you to keep track of different commit
histories on different "branches." It's a good idea, in larger
projects, to create a branch for every crazy idea so that you are not
mucking with the "master" branch, which usually is the branch
delivered to users. Eventually, if your crazy idea works out, you
would merge the branch back into master.

![git branches](/images/git-branches.png "git branches")

(Image from:
[GitGuys](http://www.gitguys.com/topics/merging-branches-without-a-conflict/))

In this example, there are two branches: master and test. The master
branch is the usual name for the main production branch. When working
in teams, eventually everybody's changes get collected into the master
branch. HEAD always points to the active branch on your personal
machine; no matter which branch you're on, HEAD points to it. We see
from the diagram that T1 is a commit that is based off of C2. C3 is a
different commit also based off C2. And C2 is based off of C1. The
following commands would have produced this scenario:

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
  you only need to type the first six or so characters. You can see
  commit id's with the command `git log`, or better, `git log --graph
  --all`.
  
- `git branch test` --- this creates a branch named "test" starting
  at the current commit (which is C2). Any new commits will be on this
  branch rather than master, until we switch back to master with
  another `git checkout master`.

## Tags

Sometimes, you'll want to label or "tag" a particular version of your
code with some descriptive name. This is often done to label version
numbers. For example, when code is delivered to a client, the current
version may be tagged "v1.0". You can "checkout", i.e., retrieve or
copy the version of the code as it looked at the tagged commit.

We will use tags to "turn in" our code. When you tag a particular
commit as "v1.0", you are telling me that you want me to grade that
version of code. If you make further changes, you might want to erase
the prior tag and tag the newer version of code. Also, be sure to tag
the master branch.

You must make a commit before you make a tag. The tag always applies
to the most recent commit (and current branch).

Examples:

    (...make some changes...)
    git commit -a -m "Some message..."
    git tag "v1.0"

If you need to erase a tag, do this:

    git tag -d "v1.0"  # use the same tag name; -d means delete

You can also list your tags:

    git tag -l

## Books and cheatsheets

- [Official book](http://git-scm.com/book) (PDF, mobi, epub links on the left)

- [GitHub's cheatsheet](https://github.com/github/training-materials/blob/master/downloads/github-git-cheat-sheet.pdf?raw=true)

- [Tower's cheatsheet](http://www.git-tower.com/blog/git-cheat-sheet-detail/)

- [Crazy interactive cheatsheet](http://ndpsoftware.com/git-cheatsheet.html)

- [How to get out of a git mess](http://justinhileman.info/article/git-pretty/git-pretty.png)

