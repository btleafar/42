/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:33:51 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:33:52 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

class ISpaceMarine
{
    public:
        virtual               ~ISpaceMarine(void) { return ; }

        virtual void          battleCry(void) const = 0;
        virtual void          meleeAttack(void) const = 0;
        virtual void          rangedAttack(void) const = 0;

        virtual ISpaceMarine  *clone(void) const = 0;
};

#endif
