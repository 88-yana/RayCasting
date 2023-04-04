#include "cub3D.h"

/**
 * @brief 二点間を結ぶ直線を描画する（Bresenham's Algorithm）
 *
 * @param game
 * @param v1
 * @param v2
 * @param color
 */
void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */

	while (true)
	{
		draw_pixel(&game->img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_player_pos(t_game *game)
{
	draw_pixel(&game->img, game->player.pos.x * 10, game->player.pos.y * 10, COLOR_RED);
}