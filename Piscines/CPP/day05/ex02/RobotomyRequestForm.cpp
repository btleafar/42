/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:24:57 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/11 20:24:58 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::_sign = 72;
const int RobotomyRequestForm::_exec = 45;

RobotomyRequestForm::RobotomyRequestForm(void) :
    Form("Anonymous", "Robotomy", \
    RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{
    srand(time(NULL));
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    Form(target, "Robotomy", \
    RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{
    srand(time(NULL));
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
    Form("Anonymous", "Robotomy", \
    RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{
    srand(time(NULL));
    *this = src;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

RobotomyRequestForm
&RobotomyRequestForm::operator= (const RobotomyRequestForm &rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

void
RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    Form::execute(executor);
    if (rand() & 1)
    {
        std::cout << "BZZZZZZZZZZ..." << getTarget() \
                  << " has been robotomized successfully !" << std::endl;
    }
    else
    {
        std::cout << "The " << getTarget() << "robotomization failed !" \
                  << std::endl;
    }
    return ;
}
