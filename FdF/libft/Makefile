# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 14:18:26 by zpalfi            #+#    #+#              #
#    Updated: 2022/03/01 17:12:28 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRCDIR		= src
SRC 		= $(shell ls $(SRCDIR) | grep -E "ft_.+\.c") \

OBJDIR		= obj
OBJ			= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

INCDIR		= includes

PRINTF		= ft_printf/libftprintf.a

CFLAGS		= -Wall -Werror -Wextra -I$(INCDIR)
CC			= gcc

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(PRINTF)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
