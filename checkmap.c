#include "so_long.h"

void checkmap(t_map *mapa)
{
	if (mapa->player != 1)
		return(0);
	if (mapa->exit != 1)
		return(0);
	if (mapa->things < 1)
		return("Mapa incorrecto");
	return(1);
}