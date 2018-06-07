/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:30:44 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/09 22:16:42 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(void) : _damage(1), _disp('|') {
  this->setPos(Vec(0, 0));
  this->setSize(Vec(1, 1));
  return;
}

Projectile::Projectile(Vec pos, Vec size, int damage, char disp)
    : _damage(damage), _disp(disp) {
  this->setPos(pos);
  this->setSize(size);
  return;
}

Projectile::Projectile(const Projectile& rhs) {
  *this = rhs;
  return;
}

Projectile::~Projectile(void) { return; }

Projectile& Projectile::operator=(Projectile const& src) {
  this->_pos = src.getPos();
  this->_size = src.getSize();
  this->_damage = src.getDamage();
  this->_disp = src.getDisp();
  return *this;
}

void Projectile::setDamage(int damage) {
  this->_damage = damage;
  return;
}

void Projectile::setPos(Vec pos) { this->_pos = pos; }

void Projectile::setSize(Vec size) { this->_size = size; }

void Projectile::move(void) { this->_pos = this->_pos + Vec(0, -1); }

int Projectile::getDamage(void) const { return this->_damage; }

char Projectile::getDisp(void) const { return this->_disp; }
