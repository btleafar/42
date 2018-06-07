/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:59:35 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/12 11:59:36 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class A;
class B;
class C;

class Base
{
public:
    Base(void);
    Base(const Base &src);

    virtual ~Base(void);

    Base    &operator= (const Base &rhs);
};

#endif
