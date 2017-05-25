# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtorres- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 17:50:19 by rtorres-          #+#    #+#              #
#    Updated: 2016/11/11 13:34:23 by rtorres-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_memset.c				\
			ft_bzero.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strlen.c				\
			ft_strdup.c				\
			ft_strcpy.c				\
			ft_strncpy.c			\
			ft_strcat.c				\
			ft_strncat.c			\
			ft_strlcat.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strstr.c				\
			ft_strnstr.c			\
			ft_strcmp.c				\
			ft_strncmp.c			\
			ft_atoi.c				\
			ft_isspace.c			\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_isupper.c			\
			ft_islower.c			\
			ft_memalloc.c			\
			ft_memdel.c				\
			ft_strnew.c				\
			ft_strdel.c				\
			ft_strclr.c				\
			ft_striter.c			\
			ft_striteri.c			\
			ft_strmap.c				\
			ft_strmapi.c			\
			ft_strequ.c				\
			ft_strnequ.c			\
			ft_strsub.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_simple_space.c		\
			ft_strsplit.c			\
			ft_count_wrds.c			\
			ft_itoa.c				\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putendl.c			\
			ft_putnbr.c				\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_putnbr_base_fd.c		\
			ft_lstnew.c				\
			ft_lstdelone.c			\
			ft_lstdel.c				\
			ft_lstadd.c				\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_alpha_mirror.c		\
			ft_strcapitalize.c		\
			ft_inter.c				\
			ft_search_and_replace.c

CC		=	gcc
FLAGS	=	-c -Wall -Wextra -Werror
LIB		=	ar rc
RLIB	=	ranlib
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "... Building all the sources for $(NAME) ..."
	@$(CC) $(FLAGS) $(SRCS)
	@echo "... Creating $(NAME) ..."
	@$(LIB) $(NAME) $(OBJS)
	@echo "... Indexing $(NAME) for optimization ..."
	@$(RLIB) $(NAME)
	@echo "... Done! ... The Crimson Fucker ..."

.PHONY: all clean fclean re

clean:
	@echo "... Cleaning '.o' objects ..."
	@rm -f $(OBJS)
	@echo "... Done! ... The Crimson Fucker ..."

fclean: clean
	@echo " $(NAME) was removed ..."
	@rm -f $(NAME)

re: fclean all