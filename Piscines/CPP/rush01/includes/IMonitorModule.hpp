/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:26:47 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/14 21:26:48 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

// Describes the behaviour of one of the monitor’s modules.

class IMonitorModule
{
public:
    IMonitorModule(void) { return ; }
    IMonitorModule(const IMonitorModule &src) { *this = src; return ; }

    IMonitorModule &operator= (const IMonitorModule &rhs) \
                              { static_cast <void> (rhs); return (*this);  }

    virtual ~IMonitorModule(void) { return ; }
};

#endif
