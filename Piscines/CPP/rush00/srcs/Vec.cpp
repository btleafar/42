/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:43:37 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 16:54:22 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec.hpp"

Vec::Vec(void) : x(0), y(0) { return; }

Vec::Vec(int x, int y) : x(x), y(y) { return; }

Vec::Vec(Vec const& src) { *this = src; }

Vec::~Vec(void) { return; }

Vec& Vec::operator=(Vec const& src) {
  this->x = src.x;
  this->y = src.y;
  return *this;
}

Vec Vec::operator+(Vec const& rhs) const {
  Vec tmp(this->x + rhs.x, this->y + rhs.y);

  return tmp;
}

Vec Vec::operator-(Vec const& rhs) const {
  Vec tmp(this->x - rhs.x, this->y - rhs.y);

  return tmp;
}

bool Vec::operator==(Vec const& rhs) const {
  if (this->x == rhs.x && this->y == rhs.y)
    return true;
  else
    return false;
}

bool Vec::operator!=(Vec const& rhs) const {
  if (this->x == rhs.x && this->y == rhs.y)
    return false;
  else
    return true;
}
