/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:12:07 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:12:08 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
public:
    Human(void);
    ~Human(void);
    Brain getBrain(void);
    std::string identify(void);

private:
    Brain _brain;
};

#endif
