#include "cub3D.h"

void	draw_wall_intersection(t_game *game)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;

	x = game->player.x_wall_on_minimap;
	y = game->player.y_wall_on_minimap;
	player_x = game->player.pos.x * TIP_SIZE;
	player_y = game->player.pos.y * TIP_SIZE;
	if (!is_out_of_map_width(game, x / 10)
		&& !is_out_of_map_height(game, y / 10))
	{
		draw_pixel(&game->img, x, y, COLOR_GREEN);
		draw_line(game, player_x, player_y, x, y, COLOR_YELLOW);
		// draw_pixel(&game->img, x - 1, y, COLOR_GREEN);
		// draw_pixel(&game->img, x - 2, y, COLOR_GREEN);
		// draw_pixel(&game->img, x + 1, y, COLOR_GREEN);
		// draw_pixel(&game->img, x + 2, y, COLOR_GREEN);
		// draw_pixel(&game->img, x, y - 1, COLOR_GREEN);
		// draw_pixel(&game->img, x, y - 2, COLOR_GREEN);
		// draw_pixel(&game->img, x, y + 1, COLOR_GREEN);
		// draw_pixel(&game->img, x, y + 2, COLOR_GREEN);
	}
	// if (!is_out_of_map_width(game, game->player.near_x / 10) && !is_out_of_map_height(game, game->player.near_y / 10))
	// 	draw_pixel(&game->img, game->player.near_x, game->player.near_y, COLOR_RED);
}

