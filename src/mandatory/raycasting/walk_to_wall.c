#include "cub3D.h"

bool	set_inf(float *x, float *y)
{
	*x = INF;
	*y = INF;
	// (void)x;
	// (void)y;
	return (true);
}

bool	is_out_of_map_height(t_game *game, double y)
{
	if (y < 0 || game->map_info.height <= y)
		return (true);
	return (false);
}

bool	is_out_of_map_width(t_game *game, double x)
{
	if (x < 0 || game->map_info.width <= x)
		return (true);
	return (false);
}

bool	finish_x_wall(t_game *game, t_player_info *player, t_raycasting *ray_info)
{
	if (player->dir.x >= 0)
	{
		if (is_out_of_map_height(game, ceil(ray_info->x_pos_on_grid.y)))
			return (set_inf(&ray_info->x_pos_on_grid.x, &ray_info->x_pos_on_grid.y));
		if (is_out_of_map_width(game, ray_info->x_pos_on_grid.x))
			return (set_inf(&ray_info->x_pos_on_grid.x, &ray_info->x_pos_on_grid.y));
		if (game->map[(int)ceil(ray_info->x_pos_on_grid.y)][(int)ray_info->x_pos_on_grid.x] == '1')
		{
			return (true);
		}
	}
	else
	{
		if (is_out_of_map_height(game, ceil(ray_info->x_pos_on_grid.y)))
			return (set_inf(&ray_info->x_pos_on_grid.x, &ray_info->x_pos_on_grid.y));
		if (is_out_of_map_width(game, ray_info->x_pos_on_grid.x - 1))
			return (set_inf(&ray_info->x_pos_on_grid.x, &ray_info->x_pos_on_grid.y));
		if (game->map[(int)ceil(ray_info->x_pos_on_grid.y)][(int)ray_info->x_pos_on_grid.x - 1] == '1')
			return (true);
	}
	return (false);
}

bool	finish_y_wall(t_game *game, t_player_info *player, t_raycasting *ray_info)
{
	if (player->dir.y >= 0)
	{
		if (is_out_of_map_height(game, ray_info->y_pos_on_grid.y))
			return (set_inf(&ray_info->y_pos_on_grid.x, &ray_info->y_pos_on_grid.y));
		if (is_out_of_map_width(game, floor(ray_info->y_pos_on_grid.x)))
			return (set_inf(&ray_info->y_pos_on_grid.x, &ray_info->y_pos_on_grid.y));
		if (game->map[(int)ray_info->y_pos_on_grid.y]
			[(int)floor(ray_info->y_pos_on_grid.x)] == '1')
			return (true);
	}
	else
	{
		if (is_out_of_map_height(game, ray_info->y_pos_on_grid.y + 1))
			return (set_inf(&ray_info->y_pos_on_grid.x, &ray_info->y_pos_on_grid.y));
		if (is_out_of_map_width(game, floor(ray_info->y_pos_on_grid.x)))
			return (set_inf(&ray_info->y_pos_on_grid.x, &ray_info->y_pos_on_grid.y));
		if (game->map[(int)ray_info->y_pos_on_grid.y + 1]
			[(int)floor(ray_info->y_pos_on_grid.x)] == '1')
			return (true);
	}
	return (false);
}

void	walk_to_wall(t_game *game, t_player_info *player, t_raycasting *ray_info)
{
	while (1)
	{
		if (ray_info->x_tile_step == 0 && ray_info->x_step_on_y_axis == 0)
		{
			set_inf(&ray_info->x_pos_on_grid.x, &ray_info->x_pos_on_grid.y);
			break ;
		}
		printf("x_pos %f, %f\n", ray_info->x_pos_on_grid.x, ray_info->x_pos_on_grid.y);
		if (finish_x_wall(game, player, ray_info))
			break ;
		printf("x_step_on_y_axis %f, %f\n", ray_info->x_tile_step, ray_info->x_step_on_y_axis);
		ray_info->x_pos_on_grid.x += ray_info->x_tile_step;
		ray_info->x_pos_on_grid.y += ray_info->x_step_on_y_axis;
	}
	printf("result of x walk %d, %f, %f\n", __LINE__, ray_info->x_pos_on_grid.x, ray_info->x_pos_on_grid.y);
	while (1)
	{
		if (ray_info->y_tile_step == 0 && ray_info->y_step_on_x_axis == 0)
		{
			set_inf(&ray_info->y_pos_on_grid.x, &ray_info->y_pos_on_grid.y);
			break ;
		}
		printf("y_pos %d, %f, %f\n", __LINE__, ray_info->y_pos_on_grid.x, ray_info->y_pos_on_grid.y);
		if (finish_y_wall(game, player, ray_info))
			break ;
		ray_info->y_pos_on_grid.x += ray_info->y_step_on_x_axis;
		ray_info->y_pos_on_grid.y += ray_info->y_tile_step;
	}
	printf("result of y walk %d, %f, %f\n", __LINE__, ray_info->y_pos_on_grid.x, ray_info->y_pos_on_grid.y);
}