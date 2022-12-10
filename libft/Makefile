# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 16:59:26 by tda-silv          #+#    #+#              #
#    Updated: 2022/12/10 20:52:02 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

HEADERS = ./libft.h \
		  ./get_next_line/get_next_line_bonus.h \

SRC = ./ft_isalpha.c \
	  ./ft_isdigit.c \
	  ./ft_isalnum.c \
	  ./ft_isascii.c \
	  ./ft_isprint.c \
	  ./ft_strlen.c \
	  ./ft_memset.c \
	  ./ft_bzero.c \
	  ./ft_memcpy.c \
	  ./ft_memmove.c \
	  ./ft_strlcpy.c \
	  ./ft_strlcat.c \
	  ./ft_toupper.c \
	  ./ft_tolower.c \
	  ./ft_strchr.c \
	  ./ft_strrchr.c \
	  ./ft_strncmp.c \
	  ./ft_memchr.c \
	  ./ft_memcmp.c \
	  ./ft_strnstr.c \
	  ./ft_atoi.c \
	  ./ft_calloc.c \
	  ./ft_strdup.c \
	  ./ft_substr.c \
	  ./ft_strjoin.c \
	  ./ft_strtrim.c \
	  ./ft_split.c \
	  ./ft_itoa.c \
	  ./ft_strmapi.c \
	  ./ft_striteri.c \
	  ./ft_putchar_fd.c \
	  ./ft_putstr_fd.c \
	  ./ft_putendl_fd.c \
	  ./ft_putnbr_fd.c \
	  ./get_next_line/get_next_line_bonus.c \
	  ./my_strjoin_free.c \
	  ./my_atoi_hex.c \
	  ./my_tab_reverse.c \
	  ./my_strdlen.c \
	  ./my_strdcpy.c \
	  ./my_strdjoin.c \
	  ./my_strcmp.c \
	  ./my_strdup_until.c \
	  ./my_strchr_pos.c \
	  ./my_strdfree.c \
	  $(addprefix ./t_dl/, \
	  					 dl_add_back.c \
						 dl_clear_one.c \
						 dl_clear.c \
						 dl_find_content.c \
						 dl_last.c \
						 dl_new.c \
						 dl_size.c \
	  ) \
	  $(addprefix ./t_li/, \
						 li_add_back.c \
						 li_clear_one.c \
						 li_clear.c \
						 li_find_content.c \
						 li_last.c \
						 li_new.c \
						 li_size.c \
	  ) \
	  $(addprefix ./t_ls/, \
						 ls_add_back.c \
						 ls_clear_one.c \
						 ls_clear.c \
						 ls_find_content.c \
						 ls_last.c \
						 ls_new.c \
						 ls_size.c \
	  ) \
	  $(addprefix ./ft_printf/, \
							  ft_putchar.c \
							  ft_putchar_hexa.c \
							  ft_putchar_hexa_cap.c \
							  ft_putnbr_hexa.c \
							  ft_putnbr_hexa_cap.c \
							  ft_putnbr_int.c \
							  ft_putnbr_unsigned.c \
							  ft_putstr.c \
							  ft_putstr_printf.c \
							  ft_idconv_c.c \
							  ft_idconv_d_i.c \
							  ft_idconv_p.c \
							  ft_idconv_s.c \
							  ft_idconv_u.c \
							  ft_idconv_x.c \
							  ft_idconv_x_cap.c \
							  ft_convselect.c \
							  ft_convchr.c \
							  ft_datazero.c \
							  ft_printf.c \
	  ) \

BNS = ./ft_lstnew.c \
	  ./ft_lstadd_front.c \
	  ./ft_lstsize.c \
	  ./ft_lstlast.c \
	  ./ft_lstadd_back.c \
	  ./ft_lstdelone.c \
	  ./ft_lstclear.c \
	  ./ft_lstiter.c \
	  ./ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJBNS = $(BNS:.c=.o)

all: $(NAME) $(HEADERS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

bonus: $(OBJ) $(OBJBNS)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBJBNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
