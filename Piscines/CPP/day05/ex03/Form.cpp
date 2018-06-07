/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:18:14 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/11 20:18:15 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) :
    _signed(false),
    _grade_to_sign(1),
    _grade_to_execute(1),
    _name("undefined"),
    _target("undefined")
{
    return ;
}

Form::Form(const Form &src) :
    _signed(src._signed),
    _grade_to_sign(src._grade_to_sign),
    _grade_to_execute(src._grade_to_execute),
    _name(src._name),
    _target(src._target)
{
    *this = src;
    return ;
}


Form::Form(std::string target, std::string name, \
            int grade_to_sign, int grade_to_execute) :
    _signed(false),
    _grade_to_sign(grade_to_sign),
    _grade_to_execute(grade_to_execute),
    _name(name),
    _target(target)
{
    if (this->_grade_to_sign < 1 || this->_grade_to_execute < 1)
    {
        throw Form::GradeTooHighException();
    }
    else if (this->_grade_to_sign > 150 || this->_grade_to_execute > 150)
    {
        throw Form::GradeTooLowException();
    }
    return ;
}

Form::~Form(void)
{
    return ;
}

Form
&Form::operator= (const Form &rhs)
{
    if (this != &rhs)
    {
        this->_signed = rhs._signed;
    }
    return (*this);
}

Form::
GradeTooHighException::GradeTooHighException(void)
{
    return ;
}

Form::
GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
    *this = src;
    return ;
}

Form::
GradeTooHighException::~GradeTooHighException(void) throw()
{
    return ;
}

Form::GradeTooHighException
&Form::GradeTooHighException::operator= (const GradeTooHighException &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char
*Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high...");
}


Form::
GradeTooLowException::GradeTooLowException(void)
{
    return ;
}

Form::
GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
    *this = src;
    return ;
}

Form::
GradeTooLowException::~GradeTooLowException(void) throw()
{
    return ;
}

Form::GradeTooLowException
&Form::GradeTooLowException::operator= (const GradeTooLowException &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char
*Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low...");
}

Form::NotSignedException::NotSignedException(void)
{
    return ;
}

Form::NotSignedException::NotSignedException(const NotSignedException& src)
{
    *this = src;
    return ;
}

Form::NotSignedException::~NotSignedException(void) throw()
{
    return ;
}

Form::NotSignedException
&Form::NotSignedException::operator= (const NotSignedException &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
Form::NotSignedException::what(void) const throw()
{
    return ("Form not signed, yet");
}

void
Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_grade_to_sign)
    {
        throw Form::GradeTooLowException();
    }
    else
    {
        this->_signed = true;
    }
    return ;
}

void
Form::setTarget(std::string target)
{
    this->_target = target;
    return ;
}

bool
Form::getSigned(void) const
{
    return (this->_signed);
}

int
Form::getGradeToSign(void) const
{
    return (this->_grade_to_sign);
}

int
Form::getGradeToExecute(void) const
{
    return (this->_grade_to_execute);
}

std::string
Form::getName(void) const
{
    return (this->_name);
}

std::string
Form::getTarget(void) const
{
    return (this->_target);
}

void
Form::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > _grade_to_execute) {
        throw Form::GradeTooLowException();
    } else if (!_signed) {
        throw Form::NotSignedException();
    }
}

std::ostream
&operator<< (std::ostream &out, const Form &rhs)
{
    out << "The form: " << rhs.getName() << " which is " \
        << (rhs.getSigned() ? "" : "not ") \
        << " signed, which requires a grade " << rhs.getGradeToSign() \
        << " to sign, and " << rhs.getGradeToExecute() << " to be executed." \
        << std::endl;
    return (out);
}
