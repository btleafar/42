/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:21 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:22 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

class TimeModule
{
    TimeModule(void);
    TimeModule(const TimeModule &rhs);

    ~TimeModule(void);

    TimeModule    &operator= (const TimeModule &rhs);
};

#endif
