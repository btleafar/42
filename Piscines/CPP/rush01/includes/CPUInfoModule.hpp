/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfoModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:02 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUINFOMODULE_HPP
# define CPUINFOMODULE_HPP

class CPUInfoModule
{
    CPUInfoModule(void);
    CPUInfoModule(const CPUInfoModule &rhs);

    ~CPUInfoModule(void);

    CPUInfoModule    &operator= (const CPUInfoModule &rhs);
};

#endif
