/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IvanField.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 23:09:56 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 23:17:43 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVANFIELD_HPP
# define IVANFIELD_HPP

# include <ctime>
# include <cstdlib>
# include "SpaceObject.hpp"
# include "ObjectField.hpp"
# include "Ivan.hpp"
# include "Vec.hpp"

class IvanField : public virtual ObjectField {
 public:
  IvanField(void);
  IvanField(IvanField const & src);
  virtual ~IvanField(void);

  IvanField &    operator=(IvanField const & src);

  virtual void	 update(void);
};

#endif
