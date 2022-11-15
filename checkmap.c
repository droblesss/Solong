#include "so_long.h"

t_map	*insidecheck(t_map *mapa)
{
	static int i;
	static int j;

	while (i < mapa->height -1)
	{
	 	while(j < mapa ->width)
	 	{
			if (mapa->mapa[i][j] == 'P')
			{
				mapa->player++;
				mapa->s_player.y = i;
				mapa->s_player.x = j;
			}

			else if (mapa->mapa[i][j] == 'E')
				mapa->exit++;
			else if (mapa->mapa[i][j] == 'C')
				mapa->things++;
			else if (mapa->mapa[i][j] != '1' && mapa->mapa[i][j] != '0'
			 && mapa->mapa[i][j] != '\0')
				exit(EXIT_FAILURE);
			j++;
		}
	 	j = 0;
	 	i++;
	}
	i = 0;
	if (mapa->player != 1 || mapa->exit != 1 || mapa->things < 1)
				exit(EXIT_FAILURE);
	return (mapa);
}

// t_map *cornercheck(t_map *mapa)
// {

t_map	struct_init(t_map *mapa)
{
	mapa->things = 0;
	mapa->player = 0;
	mapa->exit = 0;
	mapa->s_player.y = 0;
	mapa->s_player.x = 0;
	mapa->s_player.movimientos = 0;
	return(*mapa);
}