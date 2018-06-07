/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:31:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:31:39 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
    public:
        Enemy(void);
        Enemy(const Enemy &src);
        Enemy(int hp, const std::string &type);

        virtual           ~Enemy(void);

        Enemy             &operator= (const Enemy &rhs);

        int               getHP(void) const;
        const std::string getType(void) const;

        virtual void      takeDamage(int damage);

    protected:
        int               _hp;
        std::string       _type;
};

#endif
