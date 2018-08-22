### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex01)

------------------------------------------
#### If we `man groups` we will see that:
```
NAME:
	groups - print the groups a user is in
SYNOPSIS:
	groups [OPTION]... [USERNAME]...

which help to bouild the beggining of the command:
$ groups $FT_USER
```

> The result of the command `$ groups $FT_USER` is only displaying the list,
but we need to separate it into a comma-separated list.

#### Next to make it a comma-separated list we need `man tr` and:
```
NAME:
	tr - translate or delete characters
SYNOPSIS:
	tr [OPTION]... SET1 [SET2]
DESCRIPTION:
	Translate, squeeze, and/or delete characters from standard input, writing to
	standard output.
	-d, --delete
		delete characters in SET1, do not translate
```

> In this case as the description suggest we we only need one [OPTION], because
with the output of `groups $FT_USER` that translate to all the groups that the
FT_USER belong to, separated by a space and ending with a new line division on
the output, we only need to replace the SPACES for COMAS, and delete the ending
with `\n`. So we end up with this:
```
$ tr ' ' ','
$ tr -d '\n'
```

But for this commands to be of use, what we need next is a tool called `PIPES`.

#### [Pipeline](https://en.wikipedia.org/wiki/Pipeline_%28Unix%29)
Now we'll take a look at a mechanism for sending data from one program to
another. It's called piping and the operator we use is ( `|` ) (found above the
backslash ( `\` ) key on most keyboards). What this operator does is feed the
output from the program on the left as input to the program on the right. In the
example below we will list only the first 3 files in the directory.
```
$ ls
barry.txt bob example.png firstfile foo1 myoutput video.mpeg
$ ls | head -3
barry.txt
bob
example.png
$
```

#### End result:
We can now use this past three elements to create the solution as follows:
```
$ groups $FT_USER | tr ' ' ',' | tr -d '\n'
```

------------------------------------------
### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex01)
