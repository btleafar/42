/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 03:40:08 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 03:40:09 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include <cstdlib>
# include "Zombie.hpp"

class ZombieEvent
{
public:
    ZombieEvent(void);
    ~ZombieEvent(void);
    void        setZombieType(std::string);
    std::string getZombieType(void);
    Zombie      *newZombie(std::string);
    Zombie      *randomChump(void);

private:
    std::string  _type;
};

#endif
