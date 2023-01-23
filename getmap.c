/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:49:29 by drobles           #+#    #+#             */
/*   Updated: 2023/01/23 20:17:07 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	getmap(char *file, t_map *mapa)
{
	char	*linea;
	char	*archivo;
	int		fd;

	fd = open(file, O_RDONLY);
	linea = get_next_line(fd);
	mapa->width = ft_strlen(linea);
	archivo = malloc(mapa->width);
	mapa->height++;
	while (linea)
	{
		archivo = ft_strjjoin(archivo, linea);
		free(linea);
		linea = get_next_line(fd);
		mapa->height++;
	}
	free(linea);
	mapa->mapa = ft_split(archivo, '\n');
	mapa->copia = ft_split(archivo, '\n');
	mapa = lencheck(mapa);
	mapa = insidecheck(mapa);
	mapa = cornercheck(mapa);
	extrachecker(mapa);
	ultimatecheck(mapa);
	free(archivo);
}
