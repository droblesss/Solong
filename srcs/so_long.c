/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:58:28 by drobles           #+#    #+#             */
/*   Updated: 2022/11/02 18:17:31 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img2;
	char	*relative_path = "./imgs/teapot.xpm";
	int		img_width;
	int		img_height;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Juego");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 10, 10);
	mlx_put_image_to_window(mlx, mlx_win, img2, 100, 100);
	mlx_loop(mlx);
}