/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/11 20:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void)
{
    this->_name = "undefined";
    this->_grade = 1;
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
      this->_name = name;
      this->_grade = grade;
    }
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

Bureaucrat
&Bureaucrat::operator= (const Bureaucrat &rhs)
{
    if (this != &rhs)
    {
        this->_name  = rhs._name;
        this->_grade = rhs._grade;
    }
    return (*this);
}

Bureaucrat::
GradeTooLowException::GradeTooLowException(void)
{
    return ;
}

Bureaucrat::
GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
    *this = src;
    return ;
}

Bureaucrat::
GradeTooLowException::~GradeTooLowException(void) throw()
{
    return ;
}

Bureaucrat::GradeTooLowException
&Bureaucrat::GradeTooLowException::operator= (const GradeTooLowException &rhs)
{
    (void)rhs;
    return (*this);
}

const char
*Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low...");
}

Bureaucrat::
GradeTooHighException::GradeTooHighException(void)
{
    return ;
}

Bureaucrat::
GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
    *this = src;
    return ;
}

Bureaucrat::
GradeTooHighException::~GradeTooHighException(void) throw()
{
    return ;
}

Bureaucrat::GradeTooHighException
&Bureaucrat::GradeTooHighException::operator= (const GradeTooHighException &rhs)
{
    (void)rhs;
    return (*this);
}

const char
*Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high...");
}

void
Bureaucrat::setName(std::string name)
{
    this->_name = name;
    return ;
}

void
Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        this->_grade = grade;
    }
    return ;
}

void
Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " cannot sign " << form.getName() \
                  << " because " << e.what() << std::endl;
    }
    return ;
}

void
Bureaucrat::executeForm(const Form &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executes " \
                  << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " has failed to execute " \
                  << form.getName() << " becuase " << e.what() << std::endl;
    }
}

void
Bureaucrat::incrementGrade(void)
{
    if (this->_grade <= 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        this->_grade -= 1;
    }
    return ;
}

void
Bureaucrat::decrementGrade(void)
{
    if (this->_grade >= 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        this->_grade += 1;
    }
    return ;
}

std::string
Bureaucrat::getName(void) const
{
    return (this->_name);
}

int
Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

std::ostream
&operator<< (std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() \
        << std::endl;
    return (out);
}
