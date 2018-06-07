/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:18:05 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/11 20:18:07 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Form;

class Bureaucrat
{
public:

    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException(void);
        GradeTooLowException(const GradeTooLowException &src);

        virtual ~GradeTooLowException(void) throw();

        GradeTooLowException  &operator= (const GradeTooLowException &rhs);

        virtual const char    *what(void) const throw();
    };

    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException(void);
        GradeTooHighException(const GradeTooHighException &src);

        virtual ~GradeTooHighException(void) throw();

        GradeTooHighException &operator= (const GradeTooHighException &rhs);

        virtual const char    *what(void) const throw();
    };

public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);

    ~Bureaucrat(void);

    Bureaucrat                &operator= (const Bureaucrat &rhs);

    void                      setGrade(int grade);
    void                      setName(std::string name);

    void                      signForm(Form &form);
    void                      executeForm(const Form &form);

    void                      incrementGrade(void);
    void                      decrementGrade(void);

    int                       getGrade(void) const;
    std::string               getName(void) const;

private:
    int                       _grade;
    std::string               _name;
};

std::ostream                    &operator<< (std::ostream &out, \
                                  const Bureaucrat &rhs);

#endif
