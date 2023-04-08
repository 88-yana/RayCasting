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
		draw_line(game, (t_vec){player_x, player_y}, (t_vec){x, y}, COLOR_YELLOW);
	}
}
