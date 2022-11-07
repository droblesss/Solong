
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
# define BUFFER_SIZE 42

// GNL //

char	*get_next_line(int fd);
char	*ft_susbstr(char	*s, unsigned int start, size_t len);
char	*ft_strdup(const char	*s1);
int		ft_strlen(const char	*str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchrr(char	*s, int c);
char	*ft_strjjoin(char	*s1, char	*s2);

// STRUCTS //

typedef struct s_player
{
	int score;
	int lives;
	char *color;
	char *name;
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
} t_xpm;

typedef struct s_map
{
	char **mapa;
	int height;
	int width;
	int things;
	int player;
	int exit;
	t_xpm s_xpm;
	
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

//Functions

t_map getmap(char *file, t_map *mapa);
void load(t_xpm *xpm, t_map *map);
void drawmap(t_xpm *xpm,t_map *mapa);
void checkmap(t_map *mapa);

#endif