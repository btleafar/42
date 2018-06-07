/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:11:53 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 06:11:54 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <sstream>

class Brain
{
public:
    Brain(void);
    ~Brain(void);
    void        setAddress(void);
    std::string getAddress(void);
    std::string identify(void);

private:
    std::string _address;
};

#endif
