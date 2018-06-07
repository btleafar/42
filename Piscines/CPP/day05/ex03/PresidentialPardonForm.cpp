/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:24:44 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/11 20:24:46 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::_sign = 25;
const int PresidentialPardonForm::_exec = 5;

PresidentialPardonForm::PresidentialPardonForm(void) :
    Form("Anonymous", "Presidential", \
    PresidentialPardonForm::_sign, PresidentialPardonForm::_exec)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    Form(target, "Presidential", \
    PresidentialPardonForm::_sign, PresidentialPardonForm::_exec)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s):
    Form("Anonymous", "Presidential", \
    PresidentialPardonForm::_sign, PresidentialPardonForm::_exec)
{
    *this = s;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

PresidentialPardonForm
&PresidentialPardonForm::operator= (const PresidentialPardonForm &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

void
PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    Form::execute(executor);
    std::cout << getTarget() << " has been pardoned by Zafod Beebkerox." \
              << std::endl;
    return ;
}
