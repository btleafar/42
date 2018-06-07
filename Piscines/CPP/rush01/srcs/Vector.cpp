/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 01:51:51 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/16 01:51:52 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector(void) : x(0), y(0) { return; }

Vector::Vector(int x, int y) : x(x), y(y) { return; }

Vector::Vector(Vector const &src) { *this = src; }

Vector::~Vector(void) { return; }

Vector& Vector::operator=(Vector const& src) {
  this->x = src.x;
  this->y = src.y;
  return *this;
}

Vector Vector::operator+(Vector const& rhs) const {
  Vector tmp(this->x + rhs.x, this->y + rhs.y);

  return tmp;
}

Vector Vector::operator-(Vector const& rhs) const {
  Vector tmp(this->x - rhs.x, this->y - rhs.y);

  return tmp;
}

bool Vector::operator==(Vector const& rhs) const {
  if (this->x == rhs.x && this->y == rhs.y)
    return true;
  else
    return false;
}

bool Vector::operator!=(Vector const& rhs) const {
  if (this->x == rhs.x && this->y == rhs.y)
    return false;
  else
    return true;
}
