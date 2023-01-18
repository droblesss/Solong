/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkitem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:36:42 by drobles           #+#    #+#             */
/*   Updated: 2023/01/18 18:47:06 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void checkitem(t_map *mapa)
{
	int i;
	int j;
	
	i = 0;
	while (i < mapa->height - 1)
	{
		j = 0;
		while (j < mapa->width)
		{
			if (mapa->copia[i][j] == 'P')
			{
				if((mapa->copia[i][j + 1]) == '0' ||(mapa->copia[i][j + 1] == 'E')
					||(mapa->copia[i][j + 1] == 'C'))
					mapa->copia[i][j + 1] = 'P';
				if((mapa->copia[i][j - 1]) == '0' ||(mapa->copia[i][j - 1] == 'E')
					||(mapa->copia[i][j - 1] == 'C'))
					mapa->copia[i][j - 1] = 'P';
			}
		j++;
		}
		i++;
	}
	ft_printf("%s", mapa->copia[1]);
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
