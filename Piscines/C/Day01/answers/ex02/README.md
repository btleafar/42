### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex02)

------------------------------------------
#### Using your favorite search engine go for:
`command line that searches for all file names that end with ".sh"`
And you will encounter a variety of answers that range from not necessary to
very useful. I found a very nice page with all that we need
[here](https://unix.stackexchange.com/questions/391872/command-line-bash-sh-filter).
As we can see (if this page still exist when you search for it, if not we always
have [Wayback Machine](http://archive.org/web/web.php)) the first answer gives
us this:
`find . -name \*.sh -print0 | xargs -0 basename -a -s .sh`

> This is something that need to be modified for a simpler and straightforward
method so that we don't use so many different functions, I'm particularly fond
of the following method:

`find . -type f -name '*.sh' -printf "%f\n" | sed 's/\.sh$//'`

Here we get the same result but is more easy to understand, I think:
```
-type c
	File is of type c:
	b      block (buffered) special

	c      character (unbuffered) special

	d      directory

	p      named pipe (FIFO)

	f      regular file

	l      symbolic  link; this is never true if the -L option or the -follow
	option is in effect, unless the symbolic link is broken. If you want to
	search for symbolic links when -L is in effect, use -xtype.

	s      socket

	D      door (Solaris)

-name pattern
	Base of file name (the path with the leading directories removed) matches
	shell pattern pattern. Because the leading directories are removed, the file
	names considered for a match with -name will never include a slash, so
	`-name a/b' will never match anything (you probably need to use -path instead).
	A warning is issued if you try to do this, unless the environment variable
	POSIXLY_CORRECT is set.  The metacharacters (`*', `?', and `[]') match a `.'
	at the start of the base name (this is a change in findutils-4.2.2; see
	section STANDARDS CONFORMANCE below). To ignore a directory and the files
	under it, use -prune; see an example in the description of -path. Braces are
	not recognized as being special, despite the fact that some shells including
	Bash imbue braces with a special meaning in shell patterns. The filename
	matching  is performed with the use of the fnmatch(3) library function.
	Don't forget to enclose the pattern in quotes in order to protect it from
	expansion by the shell.

-printf format
	True; print format on the standard output, interpreting `\' escapes and `%'
	directives. Field widths and precision can be specified as with the `printf'
	C function. Please note that many of the fields are printed as %s rather
	than %d, and this may mean that flags don't work as you might expect. This
	also means that the `-' flag does work (it forces fields to be left-aligned).
	Unlike -print, -printf does not add a newline at the end of the string.
	The escapes and directives are:
%f: File's name with any leading directories removed (only the last element).
```

#### Solution for the message "bash: ./find_sh.sh Permission denied”:
```
$ chmod u+x find_sh.sh
```
