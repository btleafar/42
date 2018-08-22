## Exercise 01 : print_groups

|               Exercise 01             |
|---------------------------------------|
|             print_groups.sh           |
| Turn-in directory : ex01/             |
| Files to turn in : print_groups.sh    |
| Allowed functions : None              |
| Notes : n/a                           |


### TODO

* Write a command line that will display the list of groups for which the login,
contained in the environment variable **FT_USER** , is a member. Separated by
commas without spaces.
* Examples:
	1. for FT_USER=nours, the result is "god,root,admin,master,nours,bocal"
	(with-out quotation marks)
	```
	$>./print_groups.sh
	god,root,admin,master,nours,bocal$>
	```
	2. for FT_USER=daemon, the result is "daemon,bin" (without quotation marks)
	```
	$>./print_groups.sh
	daemon,bin$>
	```

> Notes: Search for man groups, man tr and piping

#### As a last resort, find the answer
[here](https://github.com/idevHive/42/blob/master/Piscines/C/Day00/answers/ex01/README.md)
