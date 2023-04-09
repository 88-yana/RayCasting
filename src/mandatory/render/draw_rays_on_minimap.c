#include "cub3D.h"

void	draw_ray_on_minimap(t_game *game, int i)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;

	x = game->player.draw.x_wall_on_minimap[i];
	y = game->player.draw.y_wall_on_minimap[i];
	player_x = game->player.pos.x * TIP_SIZE;
	player_y = game->player.pos.y * TIP_SIZE;
	if (!is_out_of_map_width(game, x / 10)
		&& !is_out_of_map_height(game, y / 10))
	{
		draw_pixel(&game->img, x, y, COLOR_GREEN);
		draw_line(game, (t_vec){player_x, player_y}, (t_vec){x, y}, COLOR_YELLOW);
	}
}

void	draw_rays_on_minimap(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		draw_ray_on_minimap(game, x);
		x++;
	}
}
