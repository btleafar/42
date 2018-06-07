/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 10:34:45 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 10:34:46 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int    Fixed::_fracBits = 8;

Fixed::Fixed(void)
{
    this->_fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int value)
{
    this->_fixedPointValue = value << _fracBits;
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const float value)
{
    this->_fixedPointValue = roundf(value * (1 << _fracBits));
    std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed
&Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
    {
        this->_fixedPointValue = rhs.getRawBits();
    }
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

std::ostream
&operator<<(std::ostream &out, Fixed const &val)
{
    out << val.toFloat();
    return (out);
}

int
Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void
Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
    return ;
}

float
Fixed::toFloat(void) const
{
    return ((float)(this->_fixedPointValue) / (1 << _fracBits));
}

int
Fixed::toInt(void) const
{
    return ((int)(this->_fixedPointValue >> _fracBits));
}
