# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_sh.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 16:02:05 by rtorres-          #+#    #+#              #
#    Updated: 2018/08/24 20:53:20 by rtorres-         ###   ########.us        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
#v.0.0
#find . -name "*.sh" | rev | cut -d "/" -f1 | rev | cut -d "." -f1
#v.1.0
#find . -type f -name '*.sh' -print0 | xargs -0 basename -a -s .sh
#v.2.0
find . -type f -name '*.sh' -printf "%f\n" | sed 's/\.sh$//'
