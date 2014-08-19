---
layout: default
title: Linux
---

Here are some useful videos to help you get up to speed on Linux:

- [Copying files from your computer to Linux and vice versa](http://www.youtube.com/watch?v=nwEnzrhtPDc&feature=related)

- [Basic commands and "nano" editor](http://www.youtube.com/watch?v=UhS2f_NqxkY) (be sure to mute your speakers)

- [Basic commands](http://www.youtube.com/watch?v=Nx4v4XziEHw&feature=related) (a little more in-depth)

- [Creating and compiling a C++ file](http://www.youtube.com/watch?v=yzahMaUfL4A&feature=related)

## Creating an ssh key

```
ssh-keygen -t rsa -C "your@email.com"
```

Accept the default file path for the key.

Type a password if you want (though it's annoying to retype it all the
time). Or, just press Enter for no password.

You'll get some fun art:

```
+--[ RSA 2048]----+
|       .=Ooo+    |
|        o o= o   |
|          o o .  |
|       o o o .   |
|      . S = o    |
|       . + o     |
|          E      |
|         o .     |
|          .      |
+-----------------+
```

Now, you need to copy the "public" key and give it to BitBucket in
your account settings.

```
cat ~/.ssh/id_rsa.pub
```

It will look something like this:

```
ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAy+VVfZMrKWCt0wee+lPiGT...
```

