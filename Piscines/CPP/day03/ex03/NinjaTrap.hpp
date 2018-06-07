/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 22:58:53 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/07 22:58:53 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
    // Constructors and destructors
	NinjaTrap(void);
	NinjaTrap(std::string name);
	~NinjaTrap(void);
	// Operators
	NinjaTrap  &operator=(NinjaTrap const &rhs);
	// Damage methods
	void          meleeAttack(std::string const &target);
    void          rangedAttack(std::string const &target);
	// Shoebox
	void 		ninjaShoebox(NinjaTrap &attack);
	void 		ninjaShoebox(ClapTrap &attack);
	void 		ninjaShoebox(FragTrap &attack);
	void 		ninjaShoebox(ScavTrap &attack);
};

#endif
