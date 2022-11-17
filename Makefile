# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drobles <drobles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 11:56:59 by drobles           #+#    #+#              #
#    Updated: 2022/11/17 13:15:47 by drobles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -I. -Wall -Wextra -Werror #-g3 -fsanitize=address

SRCS = get_next_line.c get_next_line_utils.c getmap.c main.c drawmap.c checkmap.c keys.c error.c
OBJS = $(SRCS:.c=.o)

LIBMLX = mlx/
LIBFT = Libft/
PRINTF = Ft_Prinf/
HEADERS = 
LIBFTA = Libft/libft.a
MINILIB = mlx/libmlx.a
PRINTFPATH= Ft_Prinf/libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBMLX)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(MINILIB) $(PRINTFPATH) -Lmlx -lmlx -framework OpenGL -framework AppKit -L. -o $(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C clean $(LIBMLX)
	@$(MAKE) -C clean $(LIBFT)
	@$(MAKE) -C clean $(PRINTF)

fclean: clean
	rm -f $(NAME)
norme:
	@norminette
re: fclean all
