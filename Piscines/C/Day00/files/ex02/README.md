# Exercise 02 : testDay00

## Oh yeah, mooore...

|               Exercise 02             |
|---------------------------------------|
| Turn-in directory : ex02/				|
| Files to turn in : exo2.tar			|
| Allowed functions : None				|
| Notes : n/a							|

### TODO

* Create the following files and directories. Do what’s necessary so that when
you use the `ls -l` command in your directory, the output will looks like this :
```
$ ls -l
total 42
drwx--xr-x 2 login wheel XX	Jun 1 20:47 test0
-rwx--xr-- 1 login wheel 4	Jun 1 21:46 test1
dr-x---r-- 2 login wheel XX	Jun 1 22:45 test2
-r-----r-- 2 login wheel 1	Jun 1 23:44 test3
-rw-r----x 1 login wheel 2	Jun 1 23:43 test4
-r-----r-- 2 login wheel 1	Jun 1 23:44 test5
lrwxr-xr-x 1 login wheel 5	Jun 1 22:20 test6 -> test0
$
```
* Once you’ve done that, run `$ tar -cf exo2.tar *`
to create the file to be submitted.

> Notes:
> 1. "login" and "wheel" will be respectively replaced by your login and
your group.
> 2. You won’t be able to have the same "total 42" line as shown in the
example.
> 3. Don’t worry about what you’ve got instead of "XX".
> 4. A year will be accepted instead of the time, on the timestamp of the
files.
