/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:33:59 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:34:00 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
    public:
        virtual ~ISquad(void) { return ; }

        virtual int           push(ISpaceMarine *marine) = 0;
        virtual int           getCount(void) const = 0;
        virtual ISpaceMarine  *getUnit(int n) const = 0;

};

#endif
