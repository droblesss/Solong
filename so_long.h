
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

void pressup(t_map *mapa);
void pressdown(t_map *mapa);
void pressright(t_map *mapa);
void pressleft(t_map *mapa);



//Functions

t_map getmap(char *file, t_map *mapa);
void load(t_map *map);
int drawmap(t_map *mapa);
void checkmap(t_xpm *xpm, t_map *mapa, int i, int j);
t_map	*insidecheck(t_map *mapa);
t_map	struct_init(t_map *mapa);
int	key_detect(int keycode, t_map *mapa);
void	drawassitant(t_map *mapa, int i, int j);
t_map *cornercheck(t_map *mapa);
t_map	*lencheck(t_map *mapa);
int	bercheck(char *nombre);

#endif