/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:49:33 by drobles           #+#    #+#             */
/*   Updated: 2023/01/23 20:18:05 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_detect(int keycode, t_map *mapa)
{
	char	*step;

	ft_printf("\033c\n");
	if (keycode == UP)
		pressup(mapa);
	else if (keycode == RIGHT)
		pressright(mapa);
	else if (keycode == LEFT)
		pressleft(mapa);
	else if (keycode == DOWN)
		pressdown(mapa);
	else if (keycode == ESC)
	{
		mlx_destroy_window(mapa->s_xpm.mlx, mapa->s_xpm.mlx_win);
		exit(EXIT_FAILURE);
	}
	step = ft_itoa(mapa->s_player.movimientos);
	ft_printf("%s\n", step);
	free(step);
	return (0);
}

void	pressup(t_map *mapa)
{
	if (mapa->mapa[(mapa->s_player.y) - 1][mapa->s_player.x] == '0')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y -1;
		mapa->s_player.movimientos++;
	}
	else if (mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y - 1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
	else if (mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] == 'E' &&
			mapa->things == 0)
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y - 1;
		mapa->s_player.movimientos++;
		win('W');
	}
}

void	pressdown(t_map *mapa)
{
	if (mapa->mapa[mapa->s_player.y +1][mapa->s_player.x] == '0')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y + 1;
		mapa->s_player.movimientos++;
	}
	else if (mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y +1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
	else if (mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] == 'E' &&
			mapa->things == 0)
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y + 1;
		mapa->s_player.movimientos++;
		win('W');
	}
}

void	pressright(t_map *mapa)
{
	if (mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] == '0')
	{
	mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
	mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] = 'P';
	mapa->s_player.x = mapa->s_player.x + 1;
	mapa->s_player.movimientos++;
	}
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x +1] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] = 'P';
		mapa->s_player.x = mapa->s_player.x + 1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] == 'E' &&
			mapa->things == 0)
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] = 'P';
		mapa->s_player.x = mapa->s_player.x + 1;
		mapa->s_player.movimientos++;
		win('W');
	}
}

void	pressleft(t_map *mapa)
{
	if (mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] == '0')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] = 'P';
		mapa->s_player.x = mapa->s_player.x - 1;
		mapa->s_player.movimientos++;
	}
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x -1] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] = 'P';
		mapa->s_player.x = mapa->s_player.x - 1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x -1] == 'E' &&
			mapa->things == 0)
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] = 'P';
		mapa->s_player.x = mapa->s_player.x - 1;
		mapa->s_player.movimientos++;
		win('W');
	}
}
