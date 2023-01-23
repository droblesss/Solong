/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:49:41 by drobles           #+#    #+#             */
/*   Updated: 2023/01/23 18:58:26 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include "Libft/libft.h"
# include <stdarg.h>
# include "Ft_Prinf/libftprintf.h"

# define BUFFER_SIZE 42

// GNL //

char	*get_next_line(int fd);
char	*ft_susbstr(char	*s, unsigned int start, size_t len);
char	*ft_strdup(const char	*s1);
// int		ft_strlen(const char	*str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchrr(char	*s, int c);
char	*ft_strjjoin(char	*s1, char	*s2);

// STRUCTS //

typedef struct s_player
{
	int x;
	int y;
	int movimientos;
}t_player;

typedef struct s_xpm 
{
	void *mlx;
	void *mlx_win;
	void *pared;
	void *puerta;
	void *luz;
	void *hobbit;
	void *suelo;
	void *open_door;
} t_xpm;

typedef struct s_map
{
	char **mapa;
	char **copia;
	int height;
	int width;
	int things;
	int player;
	int exit;
	t_xpm s_xpm;
	t_player s_player;
	
} t_map;


typedef struct	s_data { 
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;


enum {
	SZEIMG = 64,
	MAXWIDTH = 5120,
	MAXHEIGHT = 2880
};

/// KEYS

# define DESTROY 	17
# define ESC		53
# define UP			13
# define LEFT		0
# define DOWN		1
# define RIGHT		2

void	pressup(t_map *mapa);
void	pressdown(t_map *mapa);
void	pressright(t_map *mapa);
void	pressleft(t_map *mapa);

//Functions

void	getmap(char *file, t_map *mapa);
void	load(t_map *map);
int		drawmap(t_map *mapa);
void	checkmap(t_xpm *xpm, t_map *mapa, int i, int j);
t_map	*insidecheck(t_map *mapa);
t_map	struct_init(t_map *mapa);
int		key_detect(int keycode, t_map *mapa);
void	drawassitant(t_map *mapa, int i, int j);
t_map	*cornercheck(t_map *mapa);
t_map	*lencheck(t_map *mapa);
int		bercheck(char *nombre);
int 	steps(t_map *mapa);
int 	error(char c);
int		win(char c);
void	checkitem(t_map *mapa, int y, int x);
void	extrachecker(t_map *mapa);
void	posfinder(int *x, int *y, t_map *mapa);
void	pathcheck(t_map *mapa);
void	ultimatecheck(t_map *mapa);
void	print_map(t_map *mapa);

#endif