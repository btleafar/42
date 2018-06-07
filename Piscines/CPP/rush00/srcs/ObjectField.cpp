/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectField.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:09:01 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 21:57:41 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObjectField.hpp"

ObjectField::ObjectField(void) : _objs(NULL), _count(0) {
  std::srand(std::time(NULL));
  return;
}

ObjectField::ObjectField(ObjectField const& src) {
  *this = src;
  std::srand(std::time(NULL));
}

ObjectField::~ObjectField(void) {
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

ObjectField& ObjectField::operator=(ObjectField const& rhs) {
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

int ObjectField::getCount(void) const { return _count; }

SpaceObject* ObjectField::getObj(int n) const {
  t_list* tmp;

  if (_count > n) {
    tmp = _objs;
    for (int i = 0; i < n; i++) {
      tmp = tmp->next;
    }
    return tmp->obj;
  } else {
    return NULL;
  }
}

int ObjectField::push(SpaceObject* newobj) {
  t_list* tmp = new t_list;
  t_list* j;

  tmp->obj = newobj;
  if (_count) {
    j = _objs;
    for (int i = 0; i < _count - 1; i++) {
      j = j->next;
    }
    j->next = tmp;
  } else {
    *(&_objs) = tmp;
  }
  _count++;
  return _count;
}

int ObjectField::del(int n) {
  t_list* tmp;
  t_list* tmpbef;
  t_list* tmpaft;

  if (_count > n) {
    tmpbef = _objs;
    if (n == 0) {
      *(&_objs) = _objs->next;
      delete tmpbef->obj;
      delete tmpbef;
      _count--;
    } else {
      for (int i = 0; i < n - 1; i++) {
        tmpbef = tmpbef->next;
      }
      tmp = tmpbef->next;
      tmpaft = tmp->next;
      delete tmp->obj;
      delete tmp;
      tmpbef->next = tmpaft;
      _count--;
    }
  }
  return _count;
}

void ObjectField::setBounds(Vec min, Vec max) {
  _bmax = max;
  _bmin = min;
}

void ObjectField::update() {
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
  }

  SpaceObject* s =
      new SpaceObject(Vec(std::rand() % _bmax.x, _bmin.y), Vec(1, 1));
  this->push(s);
}
