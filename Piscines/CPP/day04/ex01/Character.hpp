/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:31:13 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:31:14 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <cstdlib>

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
    public:
        Character(void);
        Character(const Character &src);
        Character(const std::string &name);

        ~Character(void);

        Character           &operator= (const Character &rhs);

        void                recoverAP(void);
        void                equip(AWeapon *weapon);
        void                attack(Enemy *enemy);

        int                 getAP(void) const;
        AWeapon            *getWeapon(void) const;
        const std::string   getName(void) const;

    private:
        int                 _ap;
        AWeapon             *_weapon;
        std::string         _name;
};

std::ostream                &operator<< (std::ostream &o, const Character &rhs);

#endif
