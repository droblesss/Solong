#include "so_long.h"

void load(t_xpm *xpm, t_map *mapa)
{
	int a;
	int b;

	xpm->mlx_win = mlx_new_window(xpm->mlx, (mapa->width-1) * SZEIMG, (mapa->height-1) * SZEIMG, "Juego");
	xpm->pared = mlx_xpm_file_to_image(xpm->mlx, "imgs/brick.xpm", &a, &b);
	xpm->puerta = mlx_xpm_file_to_image(xpm->mlx, "imgs/door.xpm", &a, &b);
	xpm->luz = mlx_xpm_file_to_image(xpm->mlx, "imgs/luz.xpm", &a, &b);
	xpm->hobbit = mlx_xpm_file_to_image(xpm->mlx, "imgs/hobbit.xpm", &a, &b);
	xpm->suelo = mlx_xpm_file_to_image(xpm->mlx, "imgs/floor.xpm", &a, &b);
}
	
void drawmap(t_xpm *xpm, t_map *mapa)
{	
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mapa->height -1)
	{
	 	while(j < mapa->width)
	 	{
	 		if (mapa->mapa[i][j] == '1')
				mlx_put_image_to_window(xpm->mlx, xpm->mlx_win, xpm->pared, SZEIMG * j, SZEIMG * i);
			if (mapa->mapa[i][j] == '0')
	 			mlx_put_image_to_window(xpm->mlx, xpm->mlx_win, xpm->suelo, SZEIMG * j, SZEIMG * i);
			if (mapa->mapa[i][j] == 'P')
				{
					mlx_put_image_to_window(xpm->mlx, xpm->mlx_win, xpm->suelo, SZEIMG * j, SZEIMG * i);
	 				mlx_put_image_to_window(xpm->mlx, xpm->mlx_win, xpm->hobbit, SZEIMG * j, SZEIMG * i);
					mapa->player++;
				}
			if (mapa->mapa[i][j] == 'E')
	 			mlx_put_image_to_window(xpm->mlx, xpm->mlx_win, xpm->puerta, SZEIMG * j, SZEIMG * i);
				mapa->exit++;
			if (mapa->mapa[i][j] == 'C')
	 			mlx_put_image_to_window(xpm->mlx, xpm->mlx_win, xpm->luz, SZEIMG * j, SZEIMG * i);
				mapa->things++;
	 		j++;
	 	}
	 	j = 0;
	 	i++;
	}
}