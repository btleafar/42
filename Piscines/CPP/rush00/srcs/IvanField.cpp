/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IvanField.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 23:12:45 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 23:26:02 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IvanField.hpp"

IvanField::IvanField(void) {
  std::srand(std::time(NULL));
  return;
}

IvanField::IvanField(IvanField const& src) {
  std::srand(std::time(NULL));
  *this = src;
}

IvanField::~IvanField(void) {
  if (_count) {
    t_list* tmp;

    for (int i = 0; i < _count; i++) {
      tmp = _objs;
      _objs = _objs->next;
      delete tmp->obj;
      delete tmp;
    }
  }
}

IvanField& IvanField::operator=(IvanField const& rhs) {
  _count = rhs.getCount();
  SpaceObject* tmp;

  for (int i = 0; i < _count; i++) {
    if (i == 0) {
      *(&_objs) = new t_list;
      tmp = new SpaceObject(rhs.getObj(i)->getPos(), rhs.getObj(i)->getSize());
      _objs->obj = tmp;
      _objs = _objs->next;
    } else {
      _objs = new t_list;
      tmp = new SpaceObject(rhs.getObj(i)->getPos(), rhs.getObj(i)->getSize());
      _objs->obj = tmp;
      _objs = _objs->next;
    }
  }
  return *this;
}

void IvanField::update(void) {
  t_list* tmp;
  int todel;
  int end;
  Vec tmpvec;

  tmp = _objs;
  end = _count;
  todel = 0;
  for (int i = 0; i < end; i++) {
    tmpvec = tmp->obj->getPos();
    if (tmpvec.y > _bmax.y || tmpvec.y < _bmin.y || tmpvec.x > _bmax.x ||
        tmpvec.x < _bmin.x) {
      todel = 1;
    }
    tmp->obj->move();
    tmp = tmp->next;
    if (todel) {
      this->del(i);
      todel = 0;
    }

    SpaceObject* s = new SpaceObject(
        Vec(std::rand() % _bmax.x, std::rand() % _bmax.y), Vec(1, 1));
    this->push(s);
  }
}
