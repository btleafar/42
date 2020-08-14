/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 07:11:51 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 21:34:53 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

/*
** Verify if whatever is in the stack, there's a newline. If it doesn't, returns
** a zero (0) to indicate that it's not valid. If there is a newline, we make a
** copy of the stack into the line, and we copied whatever was in the stack
** before, back to the stack (with the temporary stack that we created).
*/

static int			gnl_verify_line(char **stack, char **line)
{
	char			*tmp_stack;
	char			*strchr_stack;
	int				i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
		if (!strchr_stack[i++])
			return (0);
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

/*
** Reads into the heap, from the file descriptors, a specific number of bytes
** defined by the BUFF_SIZE macro in the get_nex_line.h file. It's going to
** continue the reading when the return value of the read function is greater
** than zero (no errors, or if there is nothing else to read).
** If there is something in the stack, we will concatinate whatever is in
** there, with whatever is read in the heap. If no, we will just add
** whatever is in the heap into the stack. Then we will verify the stack to
** see if there is a newline. If there is, we will break from the while loop
** and force the positive ret value into a one (1), using the RET_VALUE() macro.
** This answer form SO helped me visualize the stack and heap in a better way:
** http://stackoverflow.com/a/1213360
*/

static	int			gnl_read_file(int fd, char *heap, char **stack, char **line)
{
	int				ret;
	char			*tmp_stack;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (gnl_verify_line(stack, line))
			break ;
	}
	return (GNL_RET_VAL(ret));
}

/*
** This is where the real shit happens.
** It first checks for errors (is the line is empty, if the number of the file
** descriptor is invalid, or if it fails to allocate the heap), so it can return
** a minus one (-1) if needed.
**
** If there is something in the stack (because we are using a static variable),
** we verify that there is a newline. If not, we allocate memory for the heap,
** and we read the file.
**
** When the reading of the file ends, we will free the heap (we're not gonna
** use it anymore), and we check for the value of ret (if it's 1 or -1, return
** that, if the stack is empty, return 0). If neither of these conditions are
** valid, we assing line to the value of the stack, free the stack, and return 1
**
** A good read about file descriptors:
** http://www.bottomupcs.com/file_descriptors.xhtml
*/

int					get_next_line(int const fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*heap;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, stack[fd], 0) < 0) \
		|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (gnl_verify_line(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	ret = gnl_read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
