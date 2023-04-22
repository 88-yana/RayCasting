#include "cub3D.h"

/**
 * @brief 二点間を結ぶ直線を描画する（Bresenham's Algorithm）
 *
 * @param game
 * @param v1
 * @param v2
 * @param color
 */
void	draw_line(t_game *game, t_vec v0, t_vec v1, int color)
{
	t_vec	d;
	t_vec	s;
	int		err;
	int		e2;

	d.x = ft_abs(v1.x - v0.x);
	d.y = -ft_abs(v1.y - v0.y);
	s.x = v0.x < v1.x ? 1 : -1;
	s.y = v0.y < v1.y ? 1 : -1;
	err = d.x + d.y;
	while (true)
	{
		draw_pixel(&game->img, v0.x, v0.y, color);
		if (v0.x == v1.x && v0.y == v1.y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			v0.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			v0.y += s.y;
		}
	}
}
