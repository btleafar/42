/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 16:13:04 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/04 16:13:05 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony
{
public:
    Pony(void);
    ~Pony(void);
    void        setName(std::string);
    void        setMark(std::string);
    void        setAge(std::string);
    void        setColor(std::string);
    std::string getName(void);
    std::string getMark(void);
    std::string getAge(void);
    std::string getColor(void);

private:
    std::string _name;
    std::string _mark;
    std::string _age;
    std::string _color;
};

#endif
