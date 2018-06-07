/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:33:50 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 16:48:32 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_HPP
# define VEC_HPP

class Vec {
 public:
  Vec(void);
  Vec(int x, int y);
  Vec(Vec const & src);
  ~Vec(void);

  Vec & operator=(Vec const & src);
  Vec   operator+(Vec const & rhs) const;
  Vec   operator-(Vec const & rhs) const;

  bool  operator==(Vec const & rhs) const;
  bool  operator!=(Vec const & rhs) const;

  int   x;
  int   y;
};

#endif
