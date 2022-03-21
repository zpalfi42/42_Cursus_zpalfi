# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:40:26 by zpalfi            #+#    #+#              #
#    Updated: 2022/02/23 15:58:24 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= src/pipex.c \
		  src/process.c \
		  src/error.c \
		  src/free.c \

SRCX	= extra/ft_split.c \
		  extra/ft_strjoin.c \
		  extra/ft_strlen.c \
		  extra/ft_strncmp.c \
		  extra/ft_strdup.c

OBJ		= $(SRC:%.c=%.o)

OBJX	= $(SRCX:%.c=%.o)

HEADER = includes/

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ) $(OBJX)
	@$(CC) $(OBJ) $(OBJX) -o $(NAME)
	@echo "$(GREEN)Pipex compiled and created succesfully!$(DEFAULT)"

all: $(NAME)

clean:
	@rm -rf $(OBJ) $(OBJX)
	@echo "$(GREEN)Object deleted succesfully!$(DEFAULT)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)All deleted succesfully!$(DEFAULT)"

re: fclean all

DEFAULT	= \033[0m
GREEN	= \033[1;32m
