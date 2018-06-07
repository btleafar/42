/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMInfoModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:52:17 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/15 18:52:17 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMINFOMODULE_HPP
# define RAMINFOMODULE_HPP

class RAMInfoModule
{
    RAMInfoModule(void);
    RAMInfoModule(const RAMInfoModule &rhs);

    ~RAMInfoModule(void);

    RAMInfoModule    &operator= (const RAMInfoModule &rhs);
};

#endif
