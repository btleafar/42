/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 05:39:02 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 05:39:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <string>
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde
{
public:
    ZombieHorde(int);
    ZombieHorde(void);
    ~ZombieHorde(void);
    void        announce(void);
    std::string randomChump(void);

private:
    Zombie      *_zombie;
    int         _number;
};

#endif
