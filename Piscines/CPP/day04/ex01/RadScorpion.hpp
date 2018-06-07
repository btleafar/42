/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:32:17 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:32:18 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include <iostream>

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
    public:
        RadScorpion(void);
        RadScorpion(const RadScorpion &src);

        ~RadScorpion(void);

        RadScorpion   &operator= (const RadScorpion &rhs);
};

#endif
