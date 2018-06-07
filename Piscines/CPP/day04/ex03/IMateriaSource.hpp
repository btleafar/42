/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:47:32 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:47:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIAL_SOURCE_HPP
# define IMATERIAL_SOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual             ~IMateriaSource(void) { return ; }

        virtual void        learnMateria(AMateria*) = 0;
        virtual AMateria    *createMateria(std::string const & type) = 0;
};

#endif
