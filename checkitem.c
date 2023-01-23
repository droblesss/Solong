/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkitem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:36:42 by drobles           #+#    #+#             */
/*   Updated: 2023/01/23 19:57:02 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkitem(t_map *mapa, int y, int x)
{
	mapa->copia[y][x] = 'P';
	if (mapa->copia[y][x + 1] == '0' || mapa->copia[y][x + 1] == 'E'
		|| mapa->copia[y][x + 1] == 'C')
		checkitem (mapa, y, x + 1);
	if (mapa->copia[y][x - 1] == '0' || mapa->copia[y][x - 1] == 'E'
		|| mapa->copia[y][x - 1] == 'C')
		checkitem (mapa, y, x - 1);
	if (mapa->copia[y + 1] && (mapa->copia[y + 1][x] == '0'
		|| mapa->copia[y + 1][x] == 'E' || mapa->copia[y + 1][x] == 'C'))
		checkitem (mapa, y + 1, x);
	if (mapa->copia[y - 1][x] == '0' || mapa->copia[y - 1][x] == 'E'
		|| mapa->copia[y - 1][x] == 'C')
		checkitem (mapa, y - 1, x);
}

void	posfinder(int *x, int *y, t_map *mapa)
{
	*y = mapa->s_player.y;
	*x = mapa->s_player.x;
}

void	pathcheck(t_map *mapa)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mapa->height - 1)
	{
		j = 0;
		while (j < mapa->width)
		{
			if (mapa->copia[i][j] == 'E' || mapa->copia[i][j] == 'C')
				error('P');
			j++;
		}
		i++;
	}	
}

void	ultimatecheck(t_map *mapa)
{
	int	x;
	int	y;

	posfinder(&x, &y, mapa);
	checkitem(mapa, y, x);
	pathcheck(mapa);
}

void	extrachecker(t_map *mapa)
{
	static int	i;
	static int	j;

	if (mapa->player != 1 || mapa->exit != 1 || mapa->things < 1)
		exit(EXIT_FAILURE);
	while (i < mapa->height - 1)
	{
		while (j < mapa->width)
		{
			if (mapa->mapa[i][j] != '1' && mapa->mapa[i][j] != '0'
			&& mapa->mapa[i][j] != '\0' && mapa->mapa[i][j] != 'C'
			&& mapa->mapa[i][j] != 'E' && mapa->mapa[i][j] != 'P')
				error('I');
		j++;
		}
	j = 0;
	i++;
	}
	i = 0;
}
