/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:49:04 by drobles           #+#    #+#             */
/*   Updated: 2023/01/23 20:15:18 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char c)
{
	if (c == 'N')
	{
		ft_printf("ERROR: The map archive is not .ber");
		exit(EXIT_FAILURE);
	}
	else if (c == 'L')
	{
		ft_printf("ERROR: Not all the lines are the same len");
		exit(EXIT_FAILURE);
	}
	else if (c == 'C')
	{
		ft_printf("ERROR: The map is not properly closed");
		exit(EXIT_FAILURE);
	}
	else if (c == 'I')
	{
		ft_printf("ERROR: There is at least one invalid char");
		exit(EXIT_FAILURE);
	}
	else if (c == 'P')
	{
		ft_printf("ERROR: Invalid Path");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	win(char c)
{
	if (c == 'W')
	{
		ft_printf("Congratulations!, you won the game");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
