/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc-wrap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 22:04:36 by kyork             #+#    #+#             */
/*   Updated: 2016/10/17 14:55:05 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

/*
** This library is neither thread-safe nor fork-safe.
**
** g_alloc_count provides a counter of the number of live allocations.
** You could check its value before and after a function call, for example.
** TODO: provide a way to turn off the atexit() print
**
**   extern int g_alloc_count;
**
** g_malloc_inject is used to cause malloc() to return NULL. When it is set to
** 0, the next allocation will return NULL and g_malloc_inject will be set to
** -1. When it is greater than 0, malloc will behave normally and the counter
** will be decremented.
**
**   extern int g_malloc_inject;
**
** It would be very stupid to turn this file in with your work, especially if
** it is included in the default compile configuration.
*/

int			g_alloc_count = 0;
int			g_malloc_inject = -1;
static int	g_have_registered = 0;

static void	print_alloc_count(void)
{
	if (g_alloc_count != 0)
		fprintf(stderr, "FAIL: %d mallocs not freed\n", g_alloc_count);
	else
		fprintf(stderr, "[OK]: all allocations freed\n");
}

void		*malloc(size_t sz)
{
	void	*(*libc_malloc)(size_t);
	void	*addr_alloc;

	if (!g_have_registered)
	{
		atexit(print_alloc_count);
		g_have_registered = 1;
	}
	if (g_malloc_inject >= 0)
		if (g_malloc_inject-- == 0)
		{
			fprintf(stderr, "malloc(%ld) = INJECT\n", sz);
			return (0);
		}
	libc_malloc = dlsym(RTLD_NEXT, "malloc");
	addr_alloc = libc_malloc(sz);
	if (addr_alloc)
		g_alloc_count++;
	fprintf(stderr, "malloc(%ld) = %p\n", sz, addr_alloc);
	return (addr_alloc);
}

void		free(void *p)
{
	void	(*libc_free)(void*);

	libc_free = dlsym(RTLD_NEXT, "free");
	fprintf(stderr, "free(%p)\n", p);
	libc_free(p);
	if (p)
		g_alloc_count--;
}
