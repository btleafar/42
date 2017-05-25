# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iumez-er <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 16:27:11 by iumez-er          #+#    #+#              #
#    Updated: 2016/12/20 17:31:17 by rtorres-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	=	fillit

HEADER	=	fillit.h

FILES	=	fillit.c check_forms.c check_errors.c \
			ft_atoi.c ft_putchar.c ft_strlen.c ft_fillit_print_solution.c \
			ft_fillit_create_tetrix.c ft_fillit_solve_sq.c ft_fillit_helpers.c \
			ft_itoa_base.c ft_strstr.c

CC		= 	gcc
FLAGS	= 	-Wall -Werror -Wextra
OBJS	= 	$(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Performing preprocess, compilation, and assemble steps for: $(NAME)."
	@$(CC) $(FLAGS) -c $(FILES)
	@echo "Write output to: $(NAME)."
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "Done!."

clean:
	@echo "Cleaning '.o' objects ..."
	@rm -rf $(OBJS)
	@echo "Done!."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) was removed."

re: fclean all

# The $@ and $< are special macros.
#	Where:
#	$@ is the file name of the target.
#	$< is the name of the first dependency.

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

norm:
	@norminette $(FILES) $(HEADER)
