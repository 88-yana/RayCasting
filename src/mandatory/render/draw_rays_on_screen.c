#include "cub3D.h"

bool	is_in_window(int x, int y)
{
	if (x < 0 || WIN_WIDTH <= x)
		return (false);
	if (y < 0 || WIN_HEIGHT <= y)
		return (false);
	return (true);
}

void	draw_ray_on_screen(t_game *game, int x_axis)
{
	int	y;

	y = 0;
	while (y < (int) 50 * game->player.draw.wall_height[x_axis])
	{
		if (is_in_window(x_axis, y + WIN_HEIGHT / 2))
			draw_pixel(&game->img, x_axis, y + WIN_HEIGHT / 2, COLOR_GREEN);
		y++;
	}
	y = 0;
	while (y > (int) - 50 * game->player.draw.wall_height[x_axis])
	{
		if (is_in_window(x_axis, y + WIN_HEIGHT / 2))
			draw_pixel(&game->img, x_axis, y + WIN_HEIGHT / 2, COLOR_GREEN);
		y--;
	}
}

void	draw_rays_on_screen(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		draw_ray_on_screen(game, x);
		x++;
	}
}
