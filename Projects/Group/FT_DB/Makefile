# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtorres- <rtorres-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 20:45:33 by rtorres-          #+#    #+#              #
#    Updated: 2017/05/05 03:32:38 by anieto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = ft_db

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g

# Folders
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/

# Source files and object files
SRC_FILES = main.c db_create.c db_read.c db_delete.c db_update.c db_serialize.c\
			db_backup.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# Libft linkers
LNK  = -L $(LIBFT_DIR)

# all rule
all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I  $(LIBFT_DIR)/includes -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compiling
$(NAME): $(OBJ)
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@gcc $(OBJ) $(LNK) -lm -o $(NAME) $(LIBFT)
	@echo "(•̀ᴗ•́)و $(NAME) generated!"

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "¯\_(ツ)_/¯ Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME) removed!"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re
