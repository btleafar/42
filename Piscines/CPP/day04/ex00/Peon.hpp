/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:28:29 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:28:29 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{
    public:
        // Constructors
        Peon(void);
        Peon(const Peon &src);
        Peon(std::string name);
        // Destructors
        ~Peon(void);
        // Operators
        Peon        &operator= (const Peon &rhs);
        // Get methods
        virtual void        getPolymorphed(void) const;

    private:
        std::string _name;
};

#endif
