/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:53:53 by drobles           #+#    #+#             */
/*   Updated: 2022/11/15 18:38:57 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map mapa;
	t_xpm xpm;
	mapa = struct_init(&mapa);
	if (argc != 2)
	{	
		printf("No hay mapa");
		return (0);
	}
	xpm.mlx = mlx_init();
	(void)argc;
	mapa = getmap(argv[1], &mapa);
	load(&xpm, &mapa);
	drawmap(&xpm, &mapa);

	// mlx_loop_hook(xpm.mlx, (int)drawmap, &mapa);
	mlx_key_hook(xpm.mlx_win, key_detect, &mapa);
	mlx_loop(xpm.mlx);
	return (0);
}