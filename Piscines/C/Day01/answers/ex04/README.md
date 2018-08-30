### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex04)

------------------------------------------
#### First lets see the options for IFCONFIG on `man ifconfig`
* Due to the present requirements we can see that we need the flag[OPTION] `-a`
because that one `display all interfaces which are currently available,
even if down`
* And now we run the `ifconfig -a` to see the output, because depending on your
system output the future commands may need some tweaking.

------------------------------------------
#### Here are a few ways:

* __grep__. There are various regular expressions that will pick these up. Here,
I am looking for 5 repetitions of 2 letters or numbers followed by a colon, then
any two characters. The **-i** makes the match case insensitive and the **-o**
makes grep print only the matched portion. **-E** enables extended regular
expressions. The same regex also works with PCREs (**-P**).
```
ifconfig -a | grep -ioE '([a-z0-9]{2}:){5}..'
```

* __sed__. The **-n** suppresses normal output and the **-r** enables extended
regular expressions. Using the same regex as above, this script will attempt to
replace everything on the line with the part of it that matches the regex. If
the substitution was successful, the resulting line is printed
(because of the p at the end of the substitution).
```
ifconfig -a | sed -rn 's/.*(([a-z0-9]{2}:){5}..).*/\1/p'
```

* __awk__. If the line starts with a word character *([a-zA-Z0-9_])*, and has
5 fields, print the last one.
```
ifconfig -a | awk '/^\w/&&NF==5{print $NF}'
```

* __Perl__, where, as usual, there are more than one ways to do it. This one is
the same logic as the awk above. The **-a** tells perl to split each input line
into the @F array.
```
ifconfig -a | perl -lane 'if(/^\w/&&$#F==4){print $F[$#F]}'
```
Alternatively, you can use the regex from the previous approaches:
```
ifconfig -a | perl -lne '/(([a-z0-9]{2}:){5}..)/ && print $1'
```

* __Coreutils__.
```
LANG_ALL=C ifconfig -a | grep 'ether' | tr -s ' ' '\t' | cut -f 3
```
OR
```
LANG_ALL=C ifconfig -a | grep 'HWadd' | tr -s ' ' '\t' | cut -f 5
```

> In the end we can mix the concepts and come with a simplified way or use
another one entirely, for example I just think this is a good answer if you're
doing this on a linux machine like me:

```
ifconfig -a | grep ether | awk '{print $2}'
```
I chose this option since my MAC addresses are next to the word "ether" so the
option grep gives me back the line where this word happens, and next with awk
I can select the second group of word per line, which are the MACs.
------------------------------------------
### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex04)
