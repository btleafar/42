/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivan.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 22:57:05 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 23:17:48 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVAN_HPP
# define IVAN_HPP

# include <cstdlib>
# include <ctime>
# include "Vec.hpp"
# include "SpaceObject.hpp"

class Ivan : public virtual SpaceObject {
 public:
  Ivan(void);
  Ivan(Vec pos, Vec size);
  Ivan(Ivan const & src);
  virtual ~Ivan(void);

  Ivan &                operator=(Ivan const & src);

  virtual void	        move(void);
  void	                setPos(Vec pos);
  void	                setSize(Vec size);
};

#endif
