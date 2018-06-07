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
    return ;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
    return ;
}

Fixed::Fixed(const int value)
{
    this->_fixedPointValue = value << _fracBits;
    return ;
}

Fixed::Fixed(const float value)
{
    this->_fixedPointValue = roundf(value * (1 << _fracBits));
    return ;
}

Fixed::~Fixed(void)
{
    return ;
}

Fixed
&Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
    {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return (*this);
}

bool
Fixed::operator>(const Fixed &rhs) const
{
    return (this->_fixedPointValue > rhs._fixedPointValue);
}

bool
Fixed::operator<(const Fixed &rhs) const
{
    return (this->_fixedPointValue < rhs._fixedPointValue);
}

bool
Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_fixedPointValue >= rhs._fixedPointValue);
}

bool
Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_fixedPointValue <= rhs._fixedPointValue);
}

bool
Fixed::operator==(const Fixed &rhs) const
{
    return (this->_fixedPointValue == rhs._fixedPointValue);
}

bool
Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_fixedPointValue != rhs._fixedPointValue);
}

Fixed
Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed
Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed
Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed
Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed
&Fixed::operator++(void)
{
    this->_fixedPointValue += 1;
    return (*this);
}

Fixed
&Fixed::operator--(void)
{
    this->_fixedPointValue -= 1;
    return (*this);
}

Fixed
Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed
Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed
&Fixed::min( Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed
&Fixed::min( const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed
&Fixed::max( Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const
Fixed &Fixed::max( const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
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
    return (this->_fixedPointValue);
}

void
Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
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
