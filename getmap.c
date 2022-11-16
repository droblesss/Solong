#include "so_long.h"

t_map getmap(char *file, t_map *mapa)
{
	char *linea;
	char *archivo;
	int fd;

	archivo = "";
 	fd = open(file, O_RDONLY);
	linea = get_next_line(fd);
	mapa->width = ft_strlen(linea);
	mapa->height++;
	while (linea)
	{
		archivo = ft_strjoin(archivo, linea);
		linea = get_next_line(fd);
		mapa->height++;
	}
	mapa->mapa = ft_split(archivo, '\n');
	*mapa = *lencheck(mapa);
	*mapa = *insidecheck(mapa);
	*mapa = *cornercheck(mapa);
	return(*mapa);
}
