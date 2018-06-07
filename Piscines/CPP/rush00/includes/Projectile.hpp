/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:30:36 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/09 22:12:55 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "SpaceObject.hpp"
# include "Vec.hpp"

class Projectile : public SpaceObject {
 public:
  Projectile(void);
  Projectile(Vec pos, Vec size, int damage, char disp);
  Projectile(const Projectile & rhs);

  ~Projectile(void);

  Projectile &  operator=(const Projectile & src);

  virtual void  move(void);

  int           getDamage(void) const;
  char          getDisp(void) const;
  void          setDamage(int damage);
  void          setPos(Vec pos);
  void          setSize(Vec size);

  private:
    int           _damage;
    char          _disp;
};

#endif
