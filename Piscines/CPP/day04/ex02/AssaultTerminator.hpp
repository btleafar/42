/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:33:27 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:33:28 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
    public:
        AssaultTerminator(void);
        AssaultTerminator(const AssaultTerminator &src);

        ~AssaultTerminator(void);

        AssaultTerminator   &operator= (const AssaultTerminator &rhs);

        virtual void          battleCry(void) const;
        virtual void          meleeAttack(void) const;
        virtual void          rangedAttack(void) const;
        virtual ISpaceMarine  *clone(void) const;
};

#endif
