# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:16:53 by zpalfi            #+#    #+#              #
#    Updated: 2022/03/14 14:24:30 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= hola

#--------------- DIRS ---------------#

INCLUDE_DIR	= include
SRC_DIR		= src
LIBS_DIR	= libs
OBJS_DIR	= objs

#--------------- FILES ---------------#

LIBS			= $(LIBS_DIR)/Libft/libft.a \

LIBS_HEADERS	= -I $(LIBS_DIR)/Libft/include/ \

INC				= -I $(INCLUDE_DIR) $(LIBS_HEADERS)

SRC				= main.c \

OBJ				= $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))

#--------------- COMPILATION ---------------#

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(INC)

#--------------- RULES ---------------#

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "Compiling $^"

all:	$(NAME)

$(NAME): $(OBJ) $(LIBS)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Built $(NAME)"

$(LIBS_DIR)/Libft/libft.a:
	@make -C $(LIBS_DIR)/Libft

clean:
	@rm -rf $(OBJS_DIR)

fclean:
	@make fclean -C $(LIBS_DIR)/Libft
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
