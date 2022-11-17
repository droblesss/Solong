/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:49:15 by drobles           #+#    #+#             */
/*   Updated: 2022/11/17 13:10:21 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*insidecheck(t_map *mapa)
{
	static int i;
	static int j;

	while (i < mapa->height - 1)
	{
	 	while(j < mapa->width)
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
			error('I');
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

t_map *cornercheck(t_map *mapa)
{
	int i;
	int j;

	i = 0;
while (i < mapa->height - 1)
{
	j = 0;
	while (j < mapa->width - 1)
	{
		if (mapa->mapa[0][j] != '1')
			error('C');
		if (mapa->mapa[mapa->height - 2][j] != '1')
			error('C');
		if (mapa->mapa[i][0] != '1')
			error('C');
		if (mapa->mapa[i][mapa->width - 2] != '1')
			error('C');
		j++;
	}
	i++;
}
	return (mapa);
}

t_map	struct_init(t_map *mapa)
{
	mapa->height = 0;
	mapa->things = 0;
	mapa->player = 0;
	mapa->exit = 0;
	mapa->s_player.y = 0;
	mapa->s_player.x = 0;
	mapa->s_player.movimientos = 0;
	return (*mapa);
}

t_map	*lencheck(t_map *mapa)
{
	int i;
	int j;

	i = 0;
	while (i < mapa->height - 1)
	{
		j = 0;
		while (mapa->mapa[i][j] != '\0')
			j++;
		if (j != mapa->width - 1)
			error('L');
		i++;
	}
	return (mapa);
}

int bercheck(char *nombre)
{	
	int lon;
	
	lon = ft_strlen(nombre);
	if ((nombre[lon - 1] != 'r') || (nombre[lon - 2] != 'e') ||
			(nombre[lon - 3] != 'b') || (nombre[lon - 4] != '.'))
		error('N');
	return (0);
}