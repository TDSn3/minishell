# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:32:32 by tda-silv          #+#    #+#              #
#    Updated: 2022/11/19 15:07:12 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRC_DIR		= source/
OBJ_DIR		= object/
INC_DIR		= include/
LIB_DIR		= libft

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror
LDFLAGS_1	= -fsanitize=address -g
LDFLAGS_2	= -fsanitize=address -g -fsanitize=leak
VFLAGS		= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=helgrind

# **************************************************************************** #
# -I | Chemin du dossier où trouver un .h									   #
# -L | Chemin du dossier où trouver un .a									   #
# -l | Nom du .a sans le préfixe "lib"										   #
# **************************************************************************** #

I_HEADERS	= -I $(INC_DIR) -I $(LIB_DIR)
L_LIB		= -L $(LIB_DIR) -l ft

################################################################################

HEADERS		= ./include/header.h \
			  ./include/struct.h \

NAME_FILE	= minishell	\

SRC			= $(addsuffix .c, $(addprefix $(SRC_DIR), $(NAME_FILE)))
OBJ			= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(NAME_FILE)))

################################################################################

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) $(I_HEADERS) -O3 -c $< -o $@

all: $(NAME) $(HEADERS)

$(NAME): $(OBJ)
	@cd libft; make; cd ..
	$(CC) $(OBJ) $(I_HEADERS) $(L_LIB) -o $(NAME)

################################################################################

valgrind: $(OBJ)
	@cd libft; make; cd ..
	$(CC) $(VFLAGS) $(OBJ) $(I_HEADERS) $(L_LIB) -o $(NAME)

fsanitize1: $(OBJ)
	@cd libft; make; cd ..
	$(CC) $(LDFLAGS_1) $(OBJ) $(I_HEADERS) $(L_LIB) -o $(NAME)

fsanitize2: $(OBJ)
	@cd libft; make; cd ..
	$(CC) $(LDFLAGS_2) $(OBJ) $(I_HEADERS) $(L_LIB) -o $(NAME)

################################################################################

clean:
	cd libft; make clean
	rm -rf $(OBJ_DIR)

fclean: clean
	cd libft; make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all valgrind fsanitize1 fsanitize2 clean fclean re
