### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex06)

------------------------------------------
#### We can use `ls` in combination with `awk` for this:
* First we use the command `ls -l` to display all contents on the current
directory in a list format, then pass the results forward using pipe `|` for
`awk` with the option:
NR → The total number of input records seen so far.
And the `% 2 == 0` to print every second line counting from line 0.
	```
	ls -l | awk 'NR % 2 == 0'
	```
