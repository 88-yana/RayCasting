#include "cub3D.h"

void	draw_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_rectangle(t_image *img, t_vec *p, int size, int color)
{
	size_t	i;
	size_t	j;

	i = p->y;
	while (i < p->y + size)
	{
		j = p->x;
		while (j < p->x + size)
		{
			draw_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map_info.height + 2)
	{
		j = 0;
		while (j < game->map_info.width + 2)
		{
			if (game->map[i][j] == '1')
				draw_rectangle(&game->img, &(t_vec){i * TIP_SIZE, j * TIP_SIZE}, TIP_SIZE, COLOR_LGRAY);
			else if (game->map[i][j] == '0' || is_start_position(game->map[i][j]))
				draw_rectangle(&game->img, &(t_vec){i * TIP_SIZE, j * TIP_SIZE}, TIP_SIZE, COLOR_GRAY);
			j++;
		}
		i++;
	}
}

