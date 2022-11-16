/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:53:53 by drobles           #+#    #+#             */
/*   Updated: 2022/11/16 16:41:35 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map mapa;
	mapa = struct_init(&mapa);
	if (argc != 2)
		return (0);
	bercheck(argv[1]);
	mapa.s_xpm.mlx = mlx_init();
	(void)argc;
	mapa = getmap(argv[1], &mapa);
	load(&mapa);
	mlx_loop_hook(mapa.s_xpm.mlx, drawmap, &mapa);
	mlx_key_hook(mapa.s_xpm.mlx_win, key_detect, &mapa);
	mlx_loop(mapa.s_xpm.mlx);
	return (0);
}