/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:31:54 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:31:55 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <iostream>

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:
        PlasmaRifle(void);
        PlasmaRifle(const PlasmaRifle &src);
        ~PlasmaRifle(void);

        PlasmaRifle   &operator= (const PlasmaRifle &rhs);

        virtual void  attack(void) const;
};

#endif
