#include "cub3D.h"

bool	is_in_window(int x, int y);

static void	draw_half(t_game *game, int offset, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel(&game->img, x, y + offset, color);
			x++;
		}
		y++;
	}
}

void	draw_back(t_game *game)
{	
	draw_half(game, 0, COLOR_GREEN);
	draw_half(game, 300, COLOR_GREEN);
}
