#include "so_long.h"

int	key_detect(int keycode, t_map *mapa)
{
	int i = 0;
	printf("\033c\n");
	if (keycode == UP)
		pressup(mapa);
	else if (keycode == RIGHT)
		pressright(mapa);
	else if (keycode == LEFT)
		pressleft(mapa);
	else if (keycode == DOWN)
		pressdown(mapa);
	while(mapa->mapa[i])
		{
			printf("%s\n", mapa->mapa[i]);
			i++;
		}
	// drawmap(mapa);
	return(0);
}

void pressup(t_map *mapa)
{
	if (mapa->mapa[(mapa->s_player.y) - 1][mapa->s_player.x] == '0')
		{	
			mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
			mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] = 'P';
			mapa->s_player.y = mapa->s_player.y -1;
			mapa->s_player.movimientos++;
		}
		else if (mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] == '1')
			return;
		else if (mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] == 'C')
		{	
			mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
			mapa->mapa[mapa->s_player.y - 1][mapa->s_player.x] = 'P';
			mapa->s_player.y = mapa->s_player.y - 1;
			mapa->s_player.movimientos++;
			mapa->things--;
		}
		
}

void	pressdown(t_map *mapa)
{
	printf("abajo");
	if (mapa->mapa[mapa->s_player.y +1][mapa->s_player.x] == '0')
	
		{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] = 'P';
		mapa->s_player.y = mapa->s_player.y + 1;
		mapa->s_player.movimientos++;
		}
	else if (mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] == '1')
		return;
	else if (mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] == 'C')
		{	
			mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
			mapa->mapa[mapa->s_player.y + 1][mapa->s_player.x] = 'P';
			mapa->s_player.y = mapa->s_player.y +1;
			mapa->s_player.movimientos++;
			mapa->things--;
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
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] == '1')
		return;
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x +1] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x + 1] = 'P';
		mapa->s_player.x = mapa->s_player.x + 1;
		mapa->s_player.movimientos++;
		mapa->things--;
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
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] == '1')
		return;
	else if (mapa->mapa[mapa->s_player.y][mapa->s_player.x -1] == 'C')
	{
		mapa->mapa[mapa->s_player.y][mapa->s_player.x] = '0';
		mapa->mapa[mapa->s_player.y][mapa->s_player.x - 1] = 'P';
		mapa->s_player.x = mapa->s_player.x - 1;
		mapa->s_player.movimientos++;
		mapa->things--;
	}
}
