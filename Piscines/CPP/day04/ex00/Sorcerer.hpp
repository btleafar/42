/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 21:28:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/08 21:28:41 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
    public:
        // Constructors
        Sorcerer(void);
        Sorcerer(const Sorcerer &src);
        Sorcerer(std::string name, std::string title);
        // Destructors
        ~Sorcerer(void);
        // Operators
        Sorcerer     &operator= (const Sorcerer &rhs);
        // Set methods
        void         setName(std::string name);
        void         setTitle(std::string title);
        void         polymorph(Victim const &victim) const;
        // Get methods
        std::string  getName(void) const;
        std::string  getTitle(void) const;

    private:
        std::string  _name;
        std::string  _title;
};

std::ostream         &operator<< (std::ostream &out, const Sorcerer &rhs);

#endif
