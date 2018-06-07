/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:26:54 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/14 21:26:55 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

// Describes the behaviour of a display mode.

class IMonitorDisplay
{
public:
    IMonitorDisplay(void) { return ; }
    IMonitorDisplay(const IMonitorDisplay &src) { *this = src; return ; }

    IMonitorDisplay &operator= (const IMonitorDisplay &rhs) \
                              { static_cast <void> (rhs); return (*this); }

    virtual ~IMonitorDisplay(void) { return ; }

    virtual void launchDisplay(void) = 0;
};

#endif
