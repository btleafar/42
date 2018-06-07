/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:53:37 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:53:38 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB
{
public:
    HumanB(std::string);
    ~HumanB(void);
    void        attack();
    void        setWeapon(Weapon&);

private:
    Weapon*     _weapon;
    std::string _name;
};

#endif
