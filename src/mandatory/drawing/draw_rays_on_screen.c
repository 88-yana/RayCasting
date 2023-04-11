#include "cub3D.h"

bool	is_in_window(int x, int y)
{
	if (x < 0 || WIN_WIDTH <= x)
		return (false);
	if (y < 0 || WIN_HEIGHT <= y)
		return (false);
	return (true);
}

int	calc_color(t_image *image, float width_rate, float height_rate)
{
	int	pixel_pos;
	int	color;
	int	x;
	int	y;

	x = width_rate * image->width;
	y = height_rate * image->height;
	pixel_pos = y * image->line_len + x * 4;
	color = *(unsigned int *)(image->addr + pixel_pos);
	return (color);
}

int	get_color(t_game *game, int x_axis, float height_rate)
{
	int		color;
	float	x_wall_rate;
	float	y_wall_rate;

	x_wall_rate = game->draw.x_wall[x_axis] - floor(game->draw.x_wall[x_axis]);
	y_wall_rate = game->draw.y_wall[x_axis] - floor(game->draw.y_wall[x_axis]);
	if (game->draw.news[x_axis] == NORTH)
		color = calc_color(&game->images.north, x_wall_rate, height_rate);
	if (game->draw.news[x_axis] == SOUTH)
		color = calc_color(&game->images.south, 1.0 - x_wall_rate, height_rate);
	if (game->draw.news[x_axis] == EAST)
		color = calc_color(&game->images.east, y_wall_rate, height_rate);
	if (game->draw.news[x_axis] == WEST)
		color = calc_color(&game->images.west, 1.0 - y_wall_rate, height_rate);
	return (color);
}

void	draw_ray_on_screen(t_game *game, int x_axis)
{
	float	y;
	int		color;
	int		wall_height;
	int		start_pos;
	float	height_rate;

	start_pos = WIN_HEIGHT / 2 - game->draw.wall_height[x_axis];
	wall_height = 2 * game->draw.wall_height[x_axis];
	if (start_pos < 0)
		y = -start_pos;
	else
		y = 0;
	while (y < wall_height && y + start_pos < WIN_HEIGHT)
	{
		height_rate = y / wall_height;
		color = get_color(game, x_axis, height_rate);
		if (is_in_window(x_axis, y + start_pos))
			draw_pixel(&game->img, x_axis, y + start_pos, color);
		y++;
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
