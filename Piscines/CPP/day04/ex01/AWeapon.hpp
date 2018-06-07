/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:31:03 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:31:04 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
    public:
        AWeapon(void);
        AWeapon(const AWeapon &src);
        AWeapon(const std::string &name, int apcost, int damage);

        virtual           ~AWeapon(void);

        AWeapon           &operator= (const AWeapon &rhs);

        virtual void      attack(void) const = 0;

        int               getAPCost(void) const;
        int               getDamage(void) const;
        const std::string getName(void) const;

    protected:
        int               _damage;
        int               _apcost;
        std::string       _name;
};

#endif
