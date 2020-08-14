/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:27:05 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:59:49 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the character is a whitespace (spaces, tabs, newlines).
*/

int		ft_iswspace(int c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}
