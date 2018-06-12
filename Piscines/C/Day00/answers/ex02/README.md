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
#### We can refer the previous ex01 for all the steps that we must repeat:
Go here for the __previous__**
[answer](https://github.com/idevHive/42/blob/master/Piscines/C/Day00/answers/ex01/README.md)
But is better to leave it to the end, and for now focus on how to create all
the folders and files accordingly with the requirements and come back to it
latter.

------------------------------------------
#### How to create all that we need

> * Remember that we use `touch` and `mkdir` to create files and folders
respectively.

But now to the new part we need to create a link for the folder `test0`
> That is what the symbol `->` means.

And as a review of the difference between __hard__** and __soft__** links we can
review this image:

![alt text][link]
[link]: https://github.com/idevHive/42/tree/master/Piscines/C/Day00/resources/picts/hard-link_vs_soft-link.jpg

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
### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day00/files/ex02)
