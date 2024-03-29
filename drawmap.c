/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:49:22 by drobles           #+#    #+#             */
/*   Updated: 2023/01/23 20:12:03 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load(t_map *mapa)
{
	int	a;
	int	b;

	mapa->s_xpm.mlx_win = mlx_new_window(mapa->s_xpm.mlx,
			(mapa->width - 1) * SZEIMG, (mapa->height - 1) * SZEIMG, "Juego");
	mapa->s_xpm.pared = mlx_xpm_file_to_image(mapa->s_xpm.mlx,
			"imgs/brick.xpm", &a, &b);
	mapa->s_xpm.puerta = mlx_xpm_file_to_image(mapa->s_xpm.mlx,
			"imgs/door.xpm", &a, &b);
	mapa->s_xpm.luz = mlx_xpm_file_to_image(mapa->s_xpm.mlx,
			"imgs/luz.xpm", &a, &b);
	mapa->s_xpm.hobbit = mlx_xpm_file_to_image(mapa->s_xpm.mlx,
			"imgs/hobbit.xpm", &a, &b);
	mapa->s_xpm.suelo = mlx_xpm_file_to_image(mapa->s_xpm.mlx,
			"imgs/floor.xpm", &a, &b);
	mapa->s_xpm.open_door = mlx_xpm_file_to_image(mapa->s_xpm.mlx,
			"imgs/opendoor.xpm", &a, &b);
}

int	drawmap(t_map *mapa)
{	
	static int	i;
	static int	j;

	while (i < mapa->height - 1)
	{
		while (j < mapa->width)
		{
			drawassitant(mapa, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	return (0);
}

void	drawassitant(t_map *mapa, int i, int j)
{
	if (mapa->mapa[i][j] == '1' )
		mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win,
			mapa->s_xpm.pared, SZEIMG * j, SZEIMG * i);
	if (mapa->mapa[i][j] == '0')
		mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win,
			mapa->s_xpm.suelo, SZEIMG * j, SZEIMG * i);
	if (mapa->mapa[i][j] == 'P')
	{
		mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win,
			mapa->s_xpm.suelo, SZEIMG * j, SZEIMG * i);
		mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win,
			mapa->s_xpm.hobbit, SZEIMG * j, SZEIMG * i);
	}
	if (mapa->mapa[i][j] == 'E')
	{
		mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win,
			mapa->s_xpm.puerta, SZEIMG * j, SZEIMG * i);
		if (mapa->things == 0)
			mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win,
				mapa->s_xpm.open_door, SZEIMG * j, SZEIMG * i);
	}
	if (mapa->mapa[i][j] == 'C')
		mlx_put_image_to_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win,
			mapa->s_xpm.luz, SZEIMG * j, SZEIMG * i);
}
