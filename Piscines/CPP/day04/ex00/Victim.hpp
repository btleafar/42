/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:28:53 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:28:54 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>

class Victim
{
    public:
        // Constructors
        Victim(void);
        Victim(const Victim &src);
        Victim(std::string name);
        // Destructors
        ~Victim(void);
        // Operators
        Victim        &operator= (const Victim &rhs);
        // Set methods
        void          setName(std::string name);
        // Get methods
        std::string   getName(void) const;
        void          getPolymorphed(void) const;

    private:
        std::string   _name;
};

std::ostream          &operator<< (std::ostream &out, const Victim &rhs);

#endif
