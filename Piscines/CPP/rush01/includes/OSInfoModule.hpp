/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:12 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:13 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

class OSInfoModule
{
    OSInfoModule(void);
    OSInfoModule(const OSInfoModule &rhs);

    ~OSInfoModule(void);

    OSInfoModule    &operator= (const OSInfoModule &rhs);
};

#endif
