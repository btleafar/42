/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:32:29 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:32:29 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <iostream>

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
    public:
        SuperMutant(void);
        SuperMutant(const SuperMutant &src);

        ~SuperMutant(void);

        SuperMutant   &operator= (const SuperMutant &rhs);

        virtual void  takeDamage(int damage);
};

#endif
