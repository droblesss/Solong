# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drobles <drobles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 11:56:59 by drobles           #+#    #+#              #
#    Updated: 2022/11/07 13:20:44 by drobles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -I. -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS = get_next_line.c get_next_line_utils.c getmap.c main.c drawmap.c checkmap.c
OBJS = $(SRCS:.c=.o)

LIBMLX = mlx/
LIBFT = Libft/
HEADERS = 
LIBFTA = Libft/libft.a
MINILIB = mlx/libmlx.a

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBMLX)
	@$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(MINILIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -L. -o $(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
