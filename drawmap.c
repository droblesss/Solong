#include "so_long.h"

void load(t_map *mapa)
{
	int a;
	int b;

	mapa->s_xpm.mlx_win = mlx_new_window(mapa->s_xpm.mlx, (mapa->width-1) * SZEIMG, (mapa->height-1) * SZEIMG, "Juego");
	mapa->s_xpm.pared = mlx_xpm_file_to_image(mapa->s_xpm.mlx, "imgs/brick.xpm", &a, &b);
	mapa->s_xpm.puerta = mlx_xpm_file_to_image(mapa->s_xpm.mlx, "imgs/door.xpm", &a, &b);
	mapa->s_xpm.luz = mlx_xpm_file_to_image(mapa->s_xpm.mlx, "imgs/luz.xpm", &a, &b);
	mapa->s_xpm.hobbit = mlx_xpm_file_to_image(mapa->s_xpm.mlx, "imgs/hobbit.xpm", &a, &b);
	mapa->s_xpm.suelo = mlx_xpm_file_to_image(mapa->s_xpm.mlx, "imgs/floor.xpm", &a, &b);
}
	
void drawmap(t_map *mapa)
{	
	static int i;
	static int j;

	while (i < mapa->height -1)
	{
	 	while(j < mapa->width)
	 	{
			// checkmap(xpm, mapa, i, j);
	 		if (mapa->mapa[i][j] == '1' )
				mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win, mapa->s_xpm.pared, SZEIMG * j, SZEIMG * i);
			if (mapa->mapa[i][j] == '0')
	 			mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win, mapa->s_xpm.suelo, SZEIMG * j, SZEIMG * i);
			if (mapa->mapa[i][j] == 'P')
	 				mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win, mapa->s_xpm.hobbit, SZEIMG * j, SZEIMG * i);
			if (mapa->mapa[i][j] == 'E')
	 			mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win, mapa->s_xpm.puerta, SZEIMG * j, SZEIMG * i);
			if (mapa->mapa[i][j] == 'C')
	 			mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win, mapa->s_xpm.luz, SZEIMG * j, SZEIMG * i);
	 		j++;
	 	}
	 	j = 0;
	 	i++;
	}
	i = 0;
}
