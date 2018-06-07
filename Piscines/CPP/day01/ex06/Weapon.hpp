/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:53:05 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:53:06 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
public:
    Weapon(std::string);
    ~Weapon(void);
    void                setType(std::string);
    const std::string&  getType(void);

private:
    std::string         _type;
};

#endif
