### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day00/files/ex02)

------------------------------------------
#### Objective:
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

------------------------------------------
#### Command `ls -l` output explanation
```
-rwxrw-r--    10    root   root 2048    Jan 13 07:11 afile.exe
?UUUGGGOOOS   00  UUUUUU GGGGGG ####    └─ date stamp and file name are obvious ;-)
↑ ↑  ↑  ↑ ↑    ↑      ↑      ↑    ↑
│ │  │  │ │    │      │      │    └─── File Size
│ │  │  │ │    │      │      └──────── Group Name (for example, Users, Administrators, etc)
│ │  │  │ │    │      └─────────────── Owner Acct
│ │  │  │ │    └────────────────────── Link count (what constitutes a "link" here varies)
│ │  │  │ └─────────────────────────── Alternative Access (blank means none defined, anything else varies)
│ └──┴──┴───────────────────────────── Read, Write and Special access modes for [U]ser, [G]roup, and [O]thers (everyone else)
└───────────────────────────────────── File type flag -
```
>The permissions (mode) flags (UUUGGGOOO) are three sets of three chars, where
the first set is "User" (i.e., Owner), the second set is "Group" and the third
set is "Others" (i.e., everyone else; anyone who is neither Owner nor Group).

------------------------------------------
#### How to create all that we need

> * Remember that we use `touch` and `mkdir` to create files and folders
respectively.

But now to the new part: we need to create a _soft link_ for the folder `test0`
> That is what the symbol `->` means.

And if we pay attention to detail we notice that `test5` is a __hard link__**
of the file `test3`
> We determine that due to the __link count__** size on both files plus the
fact that they share the same `date-stamp`

And as a review of the difference between __hard__** and __soft__** links we can
review this image:

![linktypes](42/Piscines/C/Day00/resources/picts/hard-link_vs_soft-link.jpg "Hard Link vs Soft Link")

Here is how we get to that picture:
1. Create a name `myfile.txt` in the file system that points to a new inode
(which contains the metadata for the file and points to the blocks of data that
contain its contents, i.e. the text "Hello, World!":
`$ echo 'Hello, World!' > myfile.txt`
2. Create a hard link `my-hard-link` to the file `myfile.txt`, which means
"create a file that should point to the same inode that `myfile.txt` points to":
`ln myfile.txt my-hard-link`
3. Create a soft link `my-soft-link` to the file `myfile.txt`, which means
"create a file that should point to the file `myfile.txt`":
`ln -s myfile.txt my-soft-link`
Look what will now happen if `myfile.txt` is deleted (or moved): `my-hard-link`
still points to the same contents, and is thus unaffected, whereas
`my-soft-link` now points to nothing. Is up to future tasks to evaluate the
pros/cons of each.

------------------------------------------
#### Changing the timestamp of a symlink
We just need to add the [OPTION] -h to `touch`
```
touch -h -a -m -t 201806012220.00 test6
```
> Use `man touch` for more info.

------------------------------------------
#### Change the FILE SIZE + timestamp + permissions
Go here for the __previous__**
[answer](https://github.com/idevHive/42/blob/master/Piscines/C/Day00/answers/ex01/README.md)
> But is better to leave it to the end, and for now focus on how to create all
the folders and files accordingly with the requirements and come back to it
latter.

------------------------------------------
#### How do file permissions apply to symlinks?
It depends on how you call `chmod` and the platform you are running on.
For example, on a Linux system, `man chmod` says this:
>**chmod**  never changes the permissions of symbolic links; the **chmod**
system call cannot change their permissions.  This is not a problem since the
permissions of symbolic links are never used.  However, for each symbolic link
listed on the command line, **chmod** changes the permissions of the pointed-to
file. In contrast, **chmod** ignores symbolic links encountered during recursive
directory traversals.

However, on a Mac, _chmod_ can be used to modify the permissions of a symbolic
link using options such as this (from `man chmod`):
>**-h** If the file is a symbolic link, change the mode of the link itself
rather than the file that the link points to.

------------------------------------------
### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day00/files/ex02)
