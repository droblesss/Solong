#include "so_long.h"

t_map getmap(char *file, t_map *mapa)
{
	char *linea;
	char *archivo;

	mapa->height = 0;
	archivo = "";
 	int fd = open(file, O_RDONLY);
	linea = get_next_line(fd);
	mapa->width = ft_strlen(linea);
	mapa->height++;
	while (linea)
	{
		archivo = ft_strjoin(archivo, linea);
		linea = get_next_line(fd);
		// if(ft_strlen(linea) != mapa->width)
		// 	break;
		mapa->height++;
	}
	mapa->mapa = ft_split(archivo, '\n');
	return(*mapa);
}