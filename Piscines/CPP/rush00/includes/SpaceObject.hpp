/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceObject.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:27:09 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 22:17:31 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACEOBJECT_HPP
# define SPACEOBJECT_HPP

# include <string>
# include "Vec.hpp"

class SpaceObject {
 public:
  SpaceObject(void);
  SpaceObject(Vec pos, Vec size);
  SpaceObject(SpaceObject const & src);
  virtual ~SpaceObject(void);

  SpaceObject &  operator=(SpaceObject const & src);

  virtual void   move(void);
  Vec            getPos(void) const;
  Vec            getSize(void) const;

 protected:
  Vec            _pos;
  Vec            _size;
};

#endif
