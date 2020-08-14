# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 23:46:05 by jaleman           #+#    #+#              #
#    Updated: 2020/08/13 22:05:16 by rtorres-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := libft.a

INC_DIR := includes
SRC_DIR := srcs
OBJ_DIR := objs

INCLS   := $(INC_DIR)
SRCS    := $(wildcard $(SRC_DIR)/*.c)
OBJS    := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC      := gcc
CFLAGS  += -Wall -Wextra -Werror
LFLAGS  += -I.
AR      := ar rc
RLIB    := ranlib

all:	obj $(NAME)

obj:
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)
		@echo "[INFO] $(NAME) created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)/$(INCLS)

clean:
		@rm -rf $(OBJS) $(OBJ_DIR)
		@echo "[INFO] Objects removed!"

fclean: clean
		@rm -rf $(NAME) $(LIB_DIR)
		@echo "[INFO] Library [$(NAME)] removed!"

re:		fclean all

.PHONY:	all clean fclean re
