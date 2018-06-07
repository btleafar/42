/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 01:52:02 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/16 01:52:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

class Vector
{
public:
    Vector(void);
    Vector(int x, int y);
    Vector(Vector const & src);

    ~Vector(void);

    Vector       &operator= (Vector const & src);
    Vector       operator+  (Vector const & rhs) const;
    Vector       operator-  (Vector const & rhs) const;

    bool         operator== (Vector const & rhs) const;
    bool         operator!= (Vector const & rhs) const;

    int   x;
    int   y;
};

#endif
