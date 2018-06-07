# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 23:43:48 by jaleman           #+#    #+#              #
#    Updated: 2017/07/09 23:16:13 by dhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program.
NAME        := ft_gkrellm

# Define all the compiling and linking flags.
CXX         := g++
CXXFLAGS    := -std=c++98 -Wall -Werror -Wextra
LNK         := -lncurses

# Folders
SRC_DIR     = ./srcs/
INC_DIR     = ./includes/
OBJ_DIR     = ./obj/

# Sources and objects.
SRCS_FILES := main.cpp monitor.cpp CPUInfoModule.cpp HostnameModule.cpp \
              OSInfoModule.cpp RAMInfoModule.cpp TimeModule.cpp Vector.cpp
HDRS_FILES := IMonitorDisplay.hpp IMonitorModule.hpp monitor.hpp \
              CPUInfoModule.hpp HostnameModule.hpp OSInfoModule.hpp \
              RAMInfoModule.hpp TimeModule.hpp Vector.hpp
OBJS_FILES := $(SRCS_FILES:.cpp=.o)

# Formatting variables
LINT       := clang-format -style=Google -i

# Paths
SRCS       := $(addprefix $(SRC_DIR), $(SRCS_FILES))
HDRS       := $(addprefix $(INC_DIR), $(HDRS_FILES))
OBJS       := $(addprefix $(OBJ_DIR), $(OBJS_FILES))

# Compile and create everything.
all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

# This won't run if the source files don't exist or are not modified.
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I $(INC_DIR)

# Compile the program with the objects.
$(NAME): $(OBJS) $(HDRS)
	@$(CXX) $(OBJS) -o $@ $(LNK)

# Rule to format CPP code to Google Style
format:
		$(LINT) $(SRCS)

# Rule to remove all the object files.
clean:
	@rm -rf $(OBJ_DIR)
	@echo "[INFO] Objects removed!"

# Rule to remove everything that has been created by the makefile.
fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

# Rule to re-make everything.
re:     fclean all

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean format re
