/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceObject.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:57:39 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 18:06:56 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceObject.hpp"

SpaceObject::SpaceObject(void) : _pos(Vec(0, 0)), _size(Vec(1, 1)) { return; }

SpaceObject::SpaceObject(Vec pos, Vec size) : _pos(pos), _size(size) { return; }

SpaceObject::SpaceObject(SpaceObject const& src) { *this = src; }

SpaceObject::~SpaceObject(void) { return; }

SpaceObject& SpaceObject::operator=(SpaceObject const& src) {
  this->_pos = src.getPos();
  this->_size = src.getSize();
  return *this;
}

void SpaceObject::move(void) { this->_pos.y++; }

Vec SpaceObject::getPos(void) const { return this->_pos; }

Vec SpaceObject::getSize(void) const { return this->_size; }
