---
title: Londo access
layout: default
---

# Londo access

You are free to use a server on Stetson campus known as "londo" for writing and submitting code. I will test your code on this server; if your code does not compile and run on londo, it will receive no credit.

You can access londo on-campus using just Putty or SSH, or off-campus using a VPN and Putty or SSH. Instructions are shown below for Windows and Mac systems.

For future reference, londo's address is `londo.stetson.edu`

## Console access

Most of your work with londo will use console access. For Windows, I recommend you use Putty. For Mac, you can use the builtin SSH tool.

### Windows

Putty is already installed on the school machines. [Download Putty](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html) for your own machine if you wish (choose "putty.exe" link).

Launch Putty:

![Putty](/images/putty-1.png)

Type in londo's address:

![Putty](/images/putty-2.png)

The first time you connect, you will be asked if you trust the machine you are connecting to. Say "Yes."

![Putty](/images/putty-3.png)

Type your username and password:

![Putty](/images/putty-4.png)

The first time you connect, run: `tmux`. Every time you reconnect (for the rest of the semester), run `tmux attach` instead.

![Putty](/images/putty-5.png)

Now you are just where you left off from your last connection:

![Putty](/images/putty-6.png)

When you are done, just close the Putty window.

### Mac

Start the Terminal app and run `ssh username@londo.stetson.edu` where "username" is your username.

The first time you connect, you will be asked if you trust the machine you are connecting to. Type "yes", and then type your password.

![Terminal](/images/ssh-2.png)

The first time you connect, run: `tmux`. Every time you reconnect (for the rest of the semester), run `tmux attach` instead.

![Terminal](/images/ssh-3.png)

Now you are just where you left off from your last connection:

![Terminal](/images/ssh-4.png)

When you are done, just close the Terminal window.

## File transfer

You can write your files on your machine or on londo itself (in the console). If you write on your machine, you'll need to transfer files to londo. You may also wish to copy files out of londo for backup purposes.

### Windows

Use [FileZilla](https://filezilla-project.org/download.php?type=client) on Windows to transfer files to/from londo. Start FileZilla:

![FileZilla](/images/filezilla-1.png)

Type in the host (londo's address), your username and password, and port "22", and click "Quickconnect":

![FileZilla](/images/filezilla-2.png)

Find your local files on the left, and londo files on the right. Drag files back and forth to copy to/from londo:

![FileZilla](/images/filezilla-3.png)

### Mac

Use [Cyberduck](https://cyberduck.io/?l=en) on Mac to transfer files to/from londo. Use this address in the "Quick Connect" box (change the username):

```
sftp://jeckroth@londo.stetson.edu
```

![Cyberduck](/images/cyberduck-1.png)

The window will show londo files. Find your files in the window and drag/drop with the Finder on your Mac:

![Cyberduck](/images/cyberduck-2.png)

## Off-campus VPN

If you are off campus, you cannot connect to londo with Putty/SSH until you first connect to the VPN.

Download [FortiClient](http://www.forticlient.com/downloads). Configure it as an SSL VPN, IP address 147.253.200.11, port 443, and your Stetson username (e.g., jeckroth or dplante) and Stetson password (not londo password!).

![FortiClient VPN](/images/forticlient.png)

## tmux

Whenever I use londo or other servers, I use tmux ("terminal
multiplexer"). tmux allows me to quit Putty or the Terminal and come
back later without disrupting what I was doing.

If you have never started tmux, then you'll need to run the `tmux`
command after connecting to londo. If you already have tmux running
(or at least you think you might), run `tmux attach` instead after
connecting.

Once inside tmux, you can do some fancy "window" operations:

- `Ctrl-b c` -- create a new window (windows are listed at the bottom of the screen)
- `Ctrl-b n` -- switch to "next" window
- `Ctrl-b p` -- switch to "previous" window
- `Ctrl-b [` -- freeze the window and scroll up/down with arrow keys or page-up/page-down; use `q` or `Escape` to unfreeze

You can also split a window into "panes":

- `Ctrl-b %` -- split the window vertically
- `Ctrl-b "` -- split the window horizontally
- `Ctrl-b o` -- switch to the other pane

Type "exit" in the console to close a window or pane.

