/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:32:06 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:32:07 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <iostream>

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    public:
        PowerFist(void);
        PowerFist(const PowerFist &src);

        ~PowerFist(void);

        PowerFist     &operator= (const PowerFist &rhs);

        virtual void  attack(void) const;
};

#endif
