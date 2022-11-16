/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:53:53 by drobles           #+#    #+#             */
/*   Updated: 2022/11/16 14:01:59 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map mapa;
	// t_xpm xpm;
	mapa = struct_init(&mapa);
	if (argc != 2)
	{	
		printf("No hay mapa");
		return (0);
	}
	bercheck(argv[1]);
	mapa.s_xpm.mlx = mlx_init();
	(void)argc;
	mapa = getmap(argv[1], &mapa);
	load(&mapa);
	// drawmap(&xpm, &mapa);
	mlx_loop_hook(mapa.s_xpm.mlx, drawmap, &mapa);
	mlx_key_hook(mapa.s_xpm.mlx_win, key_detect, &mapa);
	mlx_loop(mapa.s_xpm.mlx);
	return (0);
}