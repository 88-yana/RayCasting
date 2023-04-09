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

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

void	draw_back(t_game *game)
{
	t_rgb	floor;
	t_rgb	ceiling;

	floor = game->map_info.floor;
	ceiling = game->map_info.ceiling;
	draw_half(game, 0, rgb_to_int(floor.r, floor.g, floor.b));
	draw_half(game, 300, rgb_to_int(ceiling.r, ceiling.g, ceiling.b));
}
