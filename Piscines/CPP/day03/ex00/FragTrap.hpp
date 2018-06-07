/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:28:41 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/07 20:28:41 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>

class FragTrap
{
public:
    // Constructors and destructors
    FragTrap(void);
    ~FragTrap(void);
    FragTrap(std::string);
    // Operators
    FragTrap  &operator=(FragTrap const &rhs);
    // Damage methods
    void          takeDamage(unsigned int amount);
    void          beRepaired(unsigned int amount);
    // Attack methods
    void          meleeAttack(std::string const &target);
    void          rangedAttack(std::string const &target);
    // Random attack methods
    void          vaulthunter_dot_exe(std::string const &target);
    void          memeAttack(std::string const &target);
    void          fartAttack(std::string const &target);
    void          weedAttack(std::string const &target);
    void          troloAttack(std::string const &target);
    void          laserAttack(std::string const &target);
    // Get methods
    std::string   getName(void);
    unsigned int  getMeleeAttackDamage(void);
    unsigned int  getRangedAttackDamage(void);
    unsigned int  getArmourDamageReduction(void);
    unsigned int  getVaulHunter_dot_exeDamage(void);
    unsigned int  getMemeAttackDamage(void);
    unsigned int  getFartAttackDamage(void);
    unsigned int  getWeedAttackDamage(void);
    unsigned int  getTroloAttackDamage(void);
    unsigned int  getLaserAttackDamage(void);

private:
    // Player attributes
    std::string   _name;
    unsigned int  _hitPoints;
    unsigned int  _maxHitPoints;
    unsigned int  _energyPoints;
    unsigned int  _maxEnergyPoints;
    unsigned int  _level;
    // Damage points
    unsigned int  _meleeAttackDamagePoints;
    unsigned int  _rangedAttackDamagePoints;
    unsigned int  _armourDamageReductionPoints;
    unsigned int  _vaulhunterDamagePoints;
    unsigned int  _memeAttackDamagePoints;
    unsigned int  _fartAttackDamagePoints;
    unsigned int  _weedAttackDamagePoints;
    unsigned int  _troloAttackDamagePoints;
    unsigned int  _laserAttackDamagePoints;
};

#endif
