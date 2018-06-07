/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectField.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:03:23 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 21:58:42 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTFIELD_HPP
# define OBJECTFIELD_HPP

# include <ctime>
# include <cstdlib>
# include "SpaceObject.hpp"
# include "Vec.hpp"

class ObjectField {
 public:
  typedef struct    s_list {
    SpaceObject *     obj;
    s_list *          next;
  }                 t_list;

  ObjectField(void);
  ObjectField(ObjectField const & src);
  virtual ~ObjectField(void);

  ObjectField &  operator=(ObjectField const & src);

  int            getCount(void) const;
  SpaceObject *  getObj(int n) const;
  int            push(SpaceObject * newobj);
  int            del(int n);

  virtual void   update(void);
  void           setBounds(Vec min, Vec max);

 protected:
  t_list *       _objs;
  int            _count;
  Vec            _bmin;
  Vec            _bmax;
};

#endif
