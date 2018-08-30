### [back](https://github.com/idevHive/42/tree/master/Piscines/C/Day01/files/ex04)

------------------------------------------
#### First lets see the options for IFCONFIG on `man ifconfig`
* Due to the present requirements we can see that we need the flag[OPTION] `-a`
because that one `display all interfaces which are currently available,
even if down`
* And now we run the `ifconfig -a` to see the output, because depending on your
system output the future commands may need some tweaking. I get this:
```
enp4s0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
		inet 10.0.0.24  netmask 255.255.255.0  broadcast 10.0.0.255
		inet6 2601:249:a00:2e70:866d:1978:82a0:4751  prefixlen 64  scopeid 0x0<global>
		inet6 2601:249:a00:2e70::b42e  prefixlen 128  scopeid 0x0<global>
		inet6 fe80::3380:4712:1f5d:a51b  prefixlen 64  scopeid 0x20<link>
		ether dc:fe:07:12:20:98  txqueuelen 1000  (Ethernet)
		RX packets 292585  bytes 310900744 (296.4 MiB)
		RX errors 0  dropped 0  overruns 0  frame 0
		TX packets 86975  bytes 16259802 (15.5 MiB)
		TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

eth0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
		ether 62:92:17:19:98:16  txqueuelen 1000  (Ethernet)
		RX packets 0  bytes 0 (0.0 B)
		RX errors 0  dropped 0  overruns 0  frame 0
		TX packets 0  bytes 0 (0.0 B)
		TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
		inet 127.0.0.1  netmask 255.0.0.0
		inet6 ::1  prefixlen 128  scopeid 0x10<host>
		loop  txqueuelen 1000  (Local Loopback)
		RX packets 1209  bytes 82632 (80.6 KiB)
		RX errors 0  dropped 0  overruns 0  frame 0
		TX packets 1209  bytes 82632 (80.6 KiB)
		TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

virbr0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
		inet 192.168.122.1  netmask 255.255.255.0  broadcast 192.168.122.255
		ether 52:54:00:36:ae:fd  txqueuelen 1000  (Ethernet)
		RX packets 0  bytes 0 (0.0 B)
		RX errors 0  dropped 0  overruns 0  frame 0
		TX packets 0  bytes 0 (0.0 B)
		TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

virbr0-nic: flags=4098<BROADCAST,MULTICAST>  mtu 1500
		ether 52:54:00:36:ae:fd  txqueuelen 1000  (Ethernet)
		RX packets 0  bytes 0 (0.0 B)
		RX errors 0  dropped 0  overruns 0  frame 0
		TX packets 0  bytes 0 (0.0 B)
		TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

wlp3s0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
		inet 10.0.0.79  netmask 255.255.255.0  broadcast 10.0.0.255
		inet6 2601:249:a00:2e70:ba61:c3:d7f8:c23e  prefixlen 64  scopeid 0x0<global>
		inet6 2601:249:a00:2e70::ebd0  prefixlen 128  scopeid 0x0<global>
		inet6 fe80::14de:8ae:4b6e:82f7  prefixlen 64  scopeid 0x20<link>
		ether 48:45:20:5d:82:a7  txqueuelen 1000  (Ethernet)
		RX packets 20506  bytes 2833158 (2.7 MiB)
		RX errors 0  dropped 0  overruns 0  frame 0
		TX packets 2477  bytes 418788 (408.9 KiB)
		TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```
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
