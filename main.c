/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:53:53 by drobles           #+#    #+#             */
/*   Updated: 2023/01/23 20:19:08 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// int	endwindow(t_map mapa)
// {
// 	mlx_destroy_window(mapa.s_xpm.mlx, mapa.s_xpm.mlx_win);
// 	exit(EXIT_FAILURE);
// 	return (0);
// }
int	main(int argc, char **argv)
{
	t_map	mapa;

	mapa = struct_init(&mapa);
	if (argc != 2)
		return (0);
	bercheck(argv[1]);
	mapa.s_xpm.mlx = mlx_init();
	getmap(argv[1], &mapa);	// system("leaks so_long");
	load(&mapa);
	mlx_loop_hook(mapa.s_xpm.mlx, drawmap, &mapa);
	// mlx_hook(mapa.s_xpm.mlx, DESTROY, 0L, endwindow, &mapa);
	mlx_key_hook(mapa.s_xpm.mlx_win, key_detect, &mapa);
	mlx_loop(mapa.s_xpm.mlx);
	return (0);
}
