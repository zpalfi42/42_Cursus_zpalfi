# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 16:53:06 by zpalfi            #+#    #+#              #
#    Updated: 2022/01/31 16:52:12 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC		= ft_print_n.c \
			ft_print_ptr.c \
			ft_print_un.c \
			ft_print_x.c \
			ft_print_X2.c \
			ft_printf.c \

OBJ		= $(SRC:%.c=%.o)

CFLAGS		= -Wall -Werror -Wextra

CC			= gcc

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ) $(BNS_OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all