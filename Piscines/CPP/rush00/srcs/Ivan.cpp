/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivan.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 22:56:36 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 23:18:28 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ivan.hpp"

Ivan::Ivan(void) {
  std::srand(std::time(NULL));
  return;
}

Ivan::Ivan(Vec pos, Vec size) {
  this->setPos(pos);
  this->setSize(size);
  std::srand(std::time(NULL));
}

Ivan::Ivan(Ivan const& src) {
  *this = src;
  std::srand(std::time(NULL));
}

Ivan::~Ivan(void) { return; }

Ivan& Ivan::operator=(Ivan const& src) {
  this->_pos = src.getPos();
  this->_size = src.getSize();
  return *this;
}

void Ivan::move(void) {
  int i = std::rand() % 4;

  if (!i) {
    this->_pos.x++;
  } else if (i == 1) {
    this->_pos.x--;
  } else if (i == 2) {
    this->_pos.y++;
  } else {
    this->_pos.y--;
  }
}

void Ivan::setPos(Vec pos) { this->_pos = pos; }

void Ivan::setSize(Vec size) { this->_size = size; }
