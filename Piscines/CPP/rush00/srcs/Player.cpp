/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 19:19:35 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 22:18:35 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void)
    : _pos(Vec(10, 10)), _size(Vec(3, 1)), _disp('0'), _pf(new ProjField()) {
  return;
}

Player::Player(Vec pos, Vec size, char disp)
    : _pos(pos), _size(size), _disp(disp), _pf(new ProjField) {
  return;
}

Player::Player(Player const& src) { *this = src; }

Player::~Player(void) {
  delete _pf;
  return;
}

Player& Player::operator=(Player const& src) {
  this->_pos = src.getPos();
  this->_size = src.getSize();
  this->_disp = src.getDisp();
  return *this;
}

void Player::move(Vec change) { this->_pos = this->_pos + change; }

Vec Player::getPos(void) const { return this->_pos; }

Vec Player::getSize(void) const { return this->_size; }

char Player::getDisp(void) const { return this->_disp; }

ObjectField* Player::getPF(void) const { return this->_pf; }

void Player::setBounds(Vec min, Vec max) { _pf->setBounds(min, max); }

void Player::fire(void) {
  SpaceObject* p = new Projectile(_pos + Vec(0, -1), Vec(1, 1), 1, '|');
  _pf->push(p);
}
