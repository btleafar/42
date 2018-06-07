/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:14:31 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/14 21:14:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <list>
# include <vector>
# include <iostream>
# include <algorithm>

template <typename T>
void
easyfind(T &container, int n)
{
    typename    T::const_iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
    {
        std::cout << "Value exists." << std::endl;
    }
    else
    {
        throw (std::string("Value doesn't exist in the container."));
    }
}

#endif
