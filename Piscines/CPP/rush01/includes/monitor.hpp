/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 01:49:36 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/16 01:49:38 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

# include "CPUInfoModule.hpp"
# include "HostnameModule.hpp"
# include "OSInfoModule.hpp"
# include "RAMInfoModule.hpp"
# include "TimeModule.hpp"

# include "ncurses.h"
# include "Vector.hpp"

# include <iostream>

typedef struct	s_coordinates
{
	int		x;
	int		y;
}				t_coordinates;

void 		initMonitor(void);

#endif
