/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjField.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:09:35 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 22:12:16 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJFIELD_HPP
# define PROJFIELD_HPP

# include <string>
# include "SpaceObject.hpp"
# include "ObjectField.hpp"
# include "Projectile.hpp"
# include "Vec.hpp"

class ProjField : public virtual ObjectField {
 public:
  ProjField(void);
  ProjField(ProjField const & src);
  virtual ~ProjField(void);

  ProjField &   operator=(ProjField const & src);

  virtual void  update(void);
};

#endif
