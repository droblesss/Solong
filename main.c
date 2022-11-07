/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:53:53 by drobles           #+#    #+#             */
/*   Updated: 2022/11/07 11:59:39 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map mapa;
	t_xpm xpm;
	
	xpm.mlx = mlx_init();
	(void)argc;
	mapa = getmap(argv[1], &mapa);
	load(&xpm, &mapa);
	drawmap(&xpm, &mapa);
	mlx_loop(xpm.mlx);
	return (0);
}