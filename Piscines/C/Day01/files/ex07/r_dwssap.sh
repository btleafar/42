# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    r_dwssap.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 14:50:13 by rtorres-          #+#    #+#              #
#    Updated: 2018/09/05 15:20:32 by rtorres-         ###   ########.us        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

#-- Test Variables
#FT_LINE1=8
#FT_LINE2=16

#-- Version 1
#A="$((${FT_LINE2}-1))"
#B="$((${FT_LINE2}-${FT_LINE1}+1))"

#cat /etc/passwd | grep -v "^#" | sed -n 'n;p' | cut -d : -f 1 | rev | \
#sort -r | head -n $A | tail -n $B | tr "\n" "," | sed "s/,/, /g" | \
#sed "s/, $/./" | tr -d '\n'

#-- Version 2
cat /etc/passwd | sed -e 's/#.*//' -e 's/[ ^I]*$//' -e '/^$/ d' -e 's/:.*//g' \
| tr '\n' ',' | rev | tr "," "\n" | sort -r | tr "\n" ","  \
| sed -e 's/, */, /g' -e 's/.$//' -e 's/.\{3\}$//'
