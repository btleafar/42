/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:07 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:08 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

class HostnameModule
{
    HostnameModule(void);
    HostnameModule(const HostnameModule &rhs);

    ~HostnameModule(void);

    HostnameModule    &operator= (const HostnameModule &rhs);
};

#endif
