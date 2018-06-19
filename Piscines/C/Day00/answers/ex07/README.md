### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day00/files/ex07)

------------------------------------------
#### If we RTFM!(`man ls`) we will see that:
```
**-t**	sort by modification time, newest first
**-r**	**--reverse**
		reverse order while sorting
**-h**	**--human-readable**
		with **-l** and **-s**, print sizes like 1K 234M 2G etc.
**-p**	**--indicator-style**=slash
		*append / indicator to directories*
**-m**	*fill width with a comma separated list of entries*
```

> Here we encounter a problem, because at least with the command `ls` we can't
truly sort the results by creation date, so we need to create a script or use
other methods to ensure we display the results in the desired manner. This is
given because most UNIXes do not have a concept of file creation time, so we
can't make `ls` print it because the information is not recorded.

------------------------------------------
#### Going deeper into why we can't use `ls` to sort by date:

The POSIX standard only defines
[three distinct timestamps](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap04.html)
to be stored for each file: *the time of last data access*, *the time of last
data modification* and *the time the file status last changed*.

That said, modern Linux filesystems, such as ext4, Btrfs and JFS, do store the
file creation time (aka birth time), but use different names for the field in
question:
```
ufs2	→	st_birthtime
zfs		→	crtime
ext4	→	crtime
btrfs	→	otime
jfs		→	di_otime
```
However
, [currently Linux does not provide a kernel API for accessing the file creation times](https://lwn.net/Articles/397442/)
, even on filesystems supporting them.

------------------------------------------
#### As a note I did find this to be really useful:

In `ext4` it is possible; because `ext4` file-system store the file creation
time. But still you will find that the `stat` command is unable to show the
date, this is because I think the kernel is still not having any APIs for the
same.
Anyway the file birth time is stored in `ext4` and you can find it out, although
not a direct method, but using `debugfs`.

```
$ sudo debugfs -R "stat /ABSOLUTE/PATH" /dev/sdxX | grep crtime
$ sudo fdisk -l ──────────────────────────────┘
```

For those looking for more go to my [sources](https://unix.stackexchange.com/questions/91197/how-to-find-creation-date-of-file)
here.

------------------------------------------
### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day00/files/ex07)
