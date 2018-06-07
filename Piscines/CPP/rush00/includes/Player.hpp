/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 19:15:44 by dhuang            #+#    #+#             */
/*   Updated: 2017/07/09 22:06:18 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include "Vec.hpp"
# include "ProjField.hpp"

class Player {
 public:
  Player(void);
  Player(Vec pos, Vec size, char disp);
  Player(Player const & src);
  virtual ~Player(void);

  Player &       operator=(Player const & src);

  void           move(Vec change);
  Vec            getPos(void) const;
  Vec            getSize(void) const;
  char           getDisp(void) const;
  ObjectField *  getPF(void) const;
  void	         setBounds(Vec min, Vec max);
  void	         fire(void);

 private:
  Vec            _pos;
  Vec            _size;
  char           _disp;
  ObjectField *  _pf;
};

#endif
