#include "so_long.h"

int	key_detect(int keycode, t_map *mapa)
{
	char *step;
	ft_printf("\033c\n");
	if (keycode == UP)
		pressup(mapa);
	else if (keycode == RIGHT)
		pressright(mapa);
	else if (keycode == LEFT)
		pressleft(mapa);
	else if (keycode == DOWN)
		pressdown(mapa);
	step = ft_itoa(mapa->s_player.movimientos); //Se Podría Meter en una función a parte, seguramente haga falta para imprimir por pantalla//
	ft_printf("%s\n", step);
	free (step);
	return (0);
}

void	pressup(t_map *mapa)
{
	if (mapa->mapa[(mapa->s_player.y) - 1][mapa->s_player.x] == '0')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y -1;
		mapa->s_player.movimientos++;
	}
	else if (mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y - 1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
	else if (mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] == 'E' &&
			mapa->things == 0)
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y - 1;
		mapa->s_player.movimientos++;
		exit(EXIT_SUCCESS);
	}
}

void	pressdown(t_map *mapa)
{
	if (mapa->mapa[mapa->s_player.y +1][mapa->s_player.x] == '0')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y + 1;
		mapa->s_player.movimientos++;
	}
	else if (mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y +1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
	else if (mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] == 'E' &&
			mapa->things == 0)
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y + 1;
		mapa->s_player.movimientos++;
		exit(EXIT_SUCCESS);
	}
}

void	pressright(t_map *mapa)
{
	if (mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] == '0')
	{
	mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
	mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] = 'P';
	mapa->s_player.x = mapa->s_player.x + 1;
	mapa->s_player.movimientos++;
	}
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x +1] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] = 'P';
		mapa->s_player.x = mapa->s_player.x + 1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] == 'E' &&
			mapa->things == 0)
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] = 'P';
		mapa->s_player.x = mapa->s_player.x + 1;
		mapa->s_player.movimientos++;
		exit(EXIT_SUCCESS);
	}
}

void	pressleft(t_map *mapa)
{
	if (mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] == '0')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] = 'P';
		mapa->s_player.x = mapa->s_player.x - 1;
		mapa->s_player.movimientos++;
	}
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x -1] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] = 'P';
		mapa->s_player.x = mapa->s_player.x - 1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x -1] == 'E' &&
			mapa->things == 0)
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] = 'P';
		mapa->s_player.x = mapa->s_player.x - 1;
		mapa->s_player.movimientos++;
		exit(EXIT_SUCCESS);
	}
}
