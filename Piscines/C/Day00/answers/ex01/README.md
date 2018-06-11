### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day00)

------------------------------------------
#### Objective:
```
$ ls -l
total 1
-r--r-xr-x 1 login wheel 40 Jun 1 23:42 testDay00
$
```

------------------------------------------
#### Make size of file "40"
When we create the file `testDay00` we just need to open it any text editor
like `vim, atom, code or subl` and add `40` characters/symbols.
If you have any doubt take a look of the at the
[ASCII TABLE](https://www.ascii-code.com/)
Example:
```
$ cat testDay00
each symbol/char added sums one in size
```
> If we count all the letters including spaces, we'll see that it adds up to 40

------------------------------------------
#### Change the timestamp (Except ctime/Change time)
Using the command [TOUCH](https://linux.die.net/man/1/touch):
```
$ touch -a -m -t 202406012342.00
```
Where:
```
-a = accessed
-m = modified
-t = timestamp - use [[CC]YY]MMDDhhmm[.ss] time format
```
To verify they are all the same: `$ stat testDay00`

>We cannot change the ctime by ordinary means. This is by design: the ctime
is always updated to the current when you change any of the file's metadata,
and there is no way to impose a different ctime. To change the ctime of a file,
you need to do one of the following:
> 1. Set the system time to the ctime you want to impose, then touch the file,
then reset the system time.
> 2. Modify the kernel to add an interface to change the ctime.
> 3. Access the disk image directly (e.g. with `debugfs`) and twiddle the bits
on the disk (don't do it while the filesystem is mounted).

------------------------------------------
#### Change file permissions with [CHMOD](https://en.wikipedia.org/wiki/Chmod)
The chmod command is used to change the permissions of a file or directory.
To use it, you specify the desired permission settings and the file or files
that you wish to modify. There are two ways to specify the permissions, but
I am only going to teach one way.

It is easy to think of the permission settings as a series of bits
(which is how the computer thinks about them). Here's how it works:

```
rwx rwx rwx = 111 111 111
rw- rw- rw- = 110 110 110
rwx --- --- = 111 000 000
```
and so on...
```
rwx = 111 in binary = 7
rw- = 110 in binary = 6
r-x = 101 in binary = 5
r-- = 100 in binary = 4
```

Example:
```
$ chmod 455 testDay00
```

Here the digits 4, 5, and 5 each individually represent the permissions for the
user, group, and others, in that order. Each digit is a combination of the
numbers 4, 2, 1, and 0:

* 4 stands for "read",
* 2 stands for "write",
* 1 stands for "execute", and
* 0 stands for "no permission."

So 7 is the combination of permissions 4+2+1 (read, write, and execute),
5 is 4+0+1 (read, no write, and execute), and 4 is 4+0+0
(read, no write, and no execute).

|  #  |       Permission        | bin | rwx |
|:---:|:-----------------------:|:---:|:---:|
|  7  | read, write and execute | 111 | rwx |
|  6  | read and write			| 110 | rw- |
|  5  | read and execute		| 101 | r-x |
|  4  | read only				| 100 | r-- |
|  3  | write and execute		| 011 | -wx |
|  2  | write only				| 010 | -w- |
|  1  | execute only			| 001 | --x |
|  0  | none					| 000 | --- |

For more detail read `man` entry of `chmod`:
```
$ man chmod
```
------------------------------------------
### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day00)
