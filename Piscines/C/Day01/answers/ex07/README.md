### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex07)

------------------------------------------
#### Pending:
* Looking inside 'cat /etc/passwd':
We still need to deconstruct the problem and explain the solution for...
	```
	cat /etc/passwd | sed -e 's/#.*//' -e 's/[ ^I]*$//' -e '/^$/ d' -e 's/:.*//g' \
	| tr '\n' ',' | rev | tr "," "\n" | sort -r | tr "\n" ","  \
	| sed -e 's/, */, /g' -e 's/.$//' -e 's/.\{3\}$//'
	```

>> This answer is still missing the ending with a dot (.)
