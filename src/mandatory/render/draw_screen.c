#include "cub3D.h"

// void	draw_pixel(t_image *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// void	draw_rectangle(t_image *img, t_vec *p, int size, int color)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = p->y;
// 	while (i < p->y + size)
// 	{
// 		j = p->x;
// 		while (j < p->x + size)
// 		{
// 			draw_pixel(img, i, j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

bool	is_in_window(int x, int y)
{
	if (x < 0 || WIN_WIDTH <= x)
		return (false);
	if (y < 0 || WIN_HEIGHT <= y)
		return (false);
	return (true);
}

void	draw_screen(t_game *game, int x_axis)
{
	int	y;

	y = 0;
	while (y < (int) 50 * game->player.wall_height)
	{
		if (is_in_window(x_axis, y + WIN_HEIGHT / 2))
			draw_pixel(&game->img, x_axis, y + 300, COLOR_RED);
		y++;
	}
	y = 0;
	while (y > (int) - 50 * game->player.wall_height)
	{
		if (is_in_window(x_axis, y + WIN_HEIGHT / 2))
			draw_pixel(&game->img, x_axis, y + 300, COLOR_RED);
		y--;
	}
}
