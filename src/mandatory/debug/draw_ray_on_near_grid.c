#include "cub3D.h"

void	draw_ray_on_near_grid(t_game *game)
{
	get_wall_height(game, game->player.dir, dir_to_angle(game->player.dir));
	if (!is_out_of_map_width(game, game->player.near_x / 10)
		&& !is_out_of_map_height(game, game->player.near_y / 10))
		my_mlx_pixel_put(&game->img, game->player.near_x, game->player.near_y, COLOR_RED);
}
