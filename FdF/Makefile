# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 11:47:31 by zpalfi            #+#    #+#              #
#    Updated: 2022/03/02 15:44:45 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRCDIR		= src
SRC			= fdf.c \
		  	draw.c \
		  	error.c \
			draw_2.c \
			read_file.c \

OBJDIR		= obj
OBJ			= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))


LIBS		= libft/libft.a -framework OpenGL -framework AppKit

MLX_DIR		= ./mlx/
MLX_INCLUDE	= -Imlx
MLX			= -Lmlx -lmlx -framework OpenGL -framework AppKit

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@make -C mlx
			@$(CC) -o $(NAME) $(OBJ) $(LIBS) mlx/libmlx.a

clean:
			rm -f $(OBJ)
			@make -C libft clean
			@make -C mlx clean

fclean:		clean
			@rm -f $(NAME)
			@make -C libft fclean

re: fclean all

.PHONY:		all clean fclean re
